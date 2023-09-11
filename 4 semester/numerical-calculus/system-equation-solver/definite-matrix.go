package main

import (
	"bufio"
	"fmt"
	"gonum.org/v1/gonum/mat"
	"os"
	"strconv"
	"strings"
)

/*
*
The main objective is to proof if a matrix is positive-definite or not.
There's already a function for doing that in the gonum library. This is for educational purpose.

The proof has two steps:
i) proof that At = A (the matrix is symmetrical)
ii) proof that every eigenvalue of this matrix are positive

for testing, put the matrix in the file "matrix-definite.txt"
*/
func main() {
	matrix := read_matrixx()

	if is_symmetrical(matrix) {
		fmt.Println("The matrix is symmetrical ")

		if eigenvalues_positive(matrix) {
			fmt.Println("The matrix is definite-positive")
		} else {
			fmt.Println("The matrix is not definite-positive because there are one or more eigenvalues < 0")
		}
	} else {
		fmt.Println("The matrix is not symmetrical thus cannot be definite-positive")
	}

}

func read_matrixx() [][]float64 {
	read_file, _ := os.Open("matrix-definite.txt")
	defer read_file.Close() // close the file

	scanner := bufio.NewScanner(read_file)
	scanner.Split(bufio.ScanLines)

	// read the number of variables
	scanner.Scan()
	number_variables, _ := strconv.ParseInt(scanner.Text(), 10, 64)

	// allocate the matrix
	matrix := make([][]float64, number_variables)
	for i := range matrix {
		matrix[i] = make([]float64, number_variables)
	}

	i := 0
	for i < int(number_variables) && scanner.Scan() {
		line := scanner.Text()
		splited := strings.Split(line, " ")

		for j := 0; j < int(number_variables); j++ {
			matrix[i][j], _ = strconv.ParseFloat(splited[j], 64)
		}

		i++
	}

	return matrix

}

func is_symmetrical(matrix [][]float64) bool {
	rows := len(matrix)
	columns := len(matrix[0])
	if rows != columns {
		return false /// non-square matrix cannot be symmetrical

	}

	for i := 0; i < rows; i++ {
		for j := 0; j < columns; j++ {
			if matrix[i][j] != matrix[j][i] {
				return false
			}
		}
	}
	return true
}

func eigenvalues_positive(matrix [][]float64) bool {
	/// converts the matrix into a Dense for using the library gonum.
	new_matrix := mat.NewDense(len(matrix), len(matrix), nil)

	for i := 0; i < len(matrix); i++ {
		new_matrix.SetRow(i, matrix[i])
	}

	var eig mat.Eigen
	if !eig.Factorize(new_matrix, mat.EigenBoth) {
		fmt.Println("Eigenvalue factorization failed")
		return false
	}
	eigenValues := eig.Values(nil)

	fmt.Println("EigenValues: ")
	fmt.Println(eigenValues)

	for _, value := range eigenValues {
		if real(value) < 0 {
			return false
		}
	}
	return true
}
