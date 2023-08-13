package main

import "fmt"

/*
This program solve system equations using gauss elimination with partial pivot process. The gauss elimination
consists in transform the original system in an upper triangular matrix.

The program gets the system from a file.
*/
import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	matrix := read_matrix()
	fmt.Println("Matriz inicial: ")
	fmt.Println(matrix)
	fmt.Println(" ")

	/// the first step is to transform it in a triangular matrix. We'll do it with the gaussian elimination with a partial pivot

	for step := 0; step < len(matrix)-1; step++ {
		pivot := get_pivot(step, matrix)

		multipliers := create_multipliers(step, matrix, pivot)

		update_matrix(matrix, multipliers, step)

		//fmt.Println(matrix)
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
	var biggest float64 = 0

	/// the number of lines are the number of columns  - 1
	size := len(matrix[0]) - 1
	var biggest_line int
	for i := step; i < size; i++ {
		if matrix[i][step] > biggest {
			biggest = matrix[i][step]
			biggest_line = i
		}
	}

	/// permutate the lines
	matrix[biggest_line], matrix[step] = matrix[step], matrix[biggest_line]
	return biggest

}

/*
Create the multipliers according to the step and pivot. Returns a slice of them
*/
func create_multipliers(step int, matrix [][]float64, pivot float64) []float64 {

	multipliers := make([]float64, len(matrix))

	/// multipliers always made for the lines below the step
	for i := step + 1; i < len(matrix); i++ {
		multipliers[i] = matrix[i][step] / pivot
	}

	return multipliers

}

// / do the updates based on the multipliers, adding and permutating lines
func update_matrix(matrix [][]float64, multipliers []float64, step int) {

	for i := step + 1; i < len(matrix); i++ {

		/// multiplies each element of the line.
		for j := 0; j < len(matrix[i]); j++ {
			matrix[i][j] -= multipliers[i] * matrix[step][j]
		}

	}
}
