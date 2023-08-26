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
Solves the LU decomposition using the partial pivot method.

A permutation matrix, M_n, can be derived from I_n through line/column permutation
*

LU w = PA ,P is a permutation matrix. The same permutations done in A should be done
in the B (answers).

Ly = PB
Ux = y
/
*/
func main() {
	matrix := read_matrix3()
	fmt.Println(matrix)

	for step := 0; step < len(matrix); step++ {
		pivot := get_pivot2(matrix, step) /// gets the pivot and permutate the lines

		/// goes untill the B vector, which is on the last column
		for row := step + 1; row < len(matrix); row++ {
			multiplier := matrix[row][step] / pivot

			/// does the Li = Li - mult * LK
			for column := step; column < len(matrix)+1; column++ {
				matrix[row][column] -= multiplier * matrix[step][column]
			}

			/// the indices that would be zero will have the multipliers on them
			matrix[row][step] = multiplier
		}
	}

	fmt.Println("Final matrix: ")
	fmt.Println(matrix)

	/// in this time I will solve using the L matrix inside the original one.
	Y := solve_first_system(matrix)
	solution := solve(matrix, Y)
	fmt.Println("Solution: ")
	fmt.Println(solution)
}

func read_matrix3() [][]float64 {
	read_file, _ := os.Open("matrix2.txt")
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

func get_pivot2(matrix [][]float64, step int) float64 {
	var biggest_element float64
	var biggest_element_line int

	biggest_element = 0

	for row := step; row < len(matrix); row++ {
		if val := math.Abs(matrix[row][step]); val > biggest_element {
			biggest_element, biggest_element_line = val, row
		}
	}

	/// permutate the row
	matrix[step], matrix[biggest_element_line] = matrix[biggest_element_line], matrix[step]

	return biggest_element
}

func solve_first_system(matrix [][]float64) []float64 {
	Y := make([]float64, len(matrix))
	last_index := len(matrix)

	Y[0] = matrix[0][last_index] / 1

	for step := 1; step < len(matrix); step++ {
		var sum float64 = 0

		for i := 0; i < step; i++ {
			sum += matrix[step][i] * Y[i]
		}
		Y[step] = (matrix[step][last_index] - sum) / 1

	}
	return Y
}

func solve(matrix [][]float64, Y []float64) []float64 {
	last_index := len(matrix) - 1 /// we do not need the answers columns
	solution := make([]float64, len(Y))

	solution[last_index] = (Y[last_index] / matrix[last_index][last_index])

	for step := last_index - 1; step >= 0; step-- {
		var sum float64 = 0

		for i := step + 1; i <= last_index; i++ {
			sum += matrix[step][i] * solution[i]
		}
		solution[step] = math.Round((Y[step] - sum) / matrix[step][step])
	}

	return solution

}
