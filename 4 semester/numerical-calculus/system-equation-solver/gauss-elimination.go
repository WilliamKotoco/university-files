package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

/*
This program solve system equations using gauss elimination with partial pivot process. The gauss elimination
consists in transform the original system in an upper triangular matrix.

The program gets the system from a file.
*/

func main() {
	matrix := read_matrix()
	fmt.Println("Matriz inicial: ")
	fmt.Println(matrix)
	fmt.Println(" ")

	/// the first step is to transform it in a triangular matrix. We'll do it with the gaussian elimination with a partial pivot

	for step := 0; step < len(matrix)-1; step++ {
		pivot := get_pivot(step, matrix)

		for i := step + 1; i < len(matrix); i++ {
			multiplier := matrix[i][step] / pivot

			/// go through the columns as well.
			for j := step; j < len(matrix[0]); j++ {
				matrix[i][j] -= multiplier * matrix[step][j]
			}

		}
	}
	fmt.Println("Final matrix:")
	fmt.Println(matrix)
	/// now use the algorithm to solve the system of a triangular matrix
	matrix_last_index := len(matrix) - 1
	solutions := make([]float64, len(matrix))

	/// the answers are in the last_index + 1.
	solutions[matrix_last_index] = matrix[matrix_last_index][matrix_last_index+1] / matrix[matrix_last_index][matrix_last_index]
	for i := matrix_last_index - 1; i >= 0; i-- {
		var sum float64 = 0
		for j := i + 1; j < len(matrix); j++ {
			sum += matrix[i][j] * solutions[j]
		}
		solutions[i] = (matrix[i][matrix_last_index+1] - sum) / matrix[i][i]

	}
	fmt.Println("Solutions: ")
	fmt.Println(solutions)
}

func read_matrix() [][]float64 {
	read_file, _ := os.Open("matrix.txt")
	defer read_file.Close() // close the file

	scanner := bufio.NewScanner(read_file)
	scanner.Split(bufio.ScanLines)

	// read the number of variables
	scanner.Scan()
	number_variables, _ := strconv.ParseInt(scanner.Text(), 10, 64)

	// allocate the matrix
	matrix := make([][]float64, number_variables)
	for i := range matrix {
		matrix[i] = make([]float64, number_variables+1)
	}

	i := 0
	for i < int(number_variables) && scanner.Scan() {
		line := scanner.Text()
		splited := strings.Split(line, " ")

		// Lê n+1 colunas, sendo a última o resultado
		for j := 0; j < int(number_variables)+1; j++ {
			matrix[i][j], _ = strconv.ParseFloat(splited[j], 64)
		}

		i++
	}

	return matrix
}

// / Returns the partial pivot, which is the biggest element of the kth colunm, k being the current step.
func get_pivot(step int, matrix [][]float64) float64 {

	maxVal := math.Abs(matrix[step][step])
	maxRow := step

	for i := step + 1; i < len(matrix); i++ {
		if math.Abs(matrix[i][step]) > maxVal {
			maxVal, maxRow = matrix[i][step], i
		}
	}
	/// permutate the lines
	matrix[maxRow], matrix[step] = matrix[step], matrix[maxRow]
	return matrix[step][step]

}
