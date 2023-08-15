package main

/*
This program aims to solve a system equation using the Lu factoring.

The main difference is that we store the multipliers on the zeros and get
Ax = B as (LU)x = b, where L is a lower triangular matrix and U is an upper one triangular
matrix

After that decomposition, we make y = Ux and obtain the resolution through the following system:
i) Ly = b
ii) Ux = y
*/
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	matrix := read_matrix2()
	fmt.Println("Initial matrix:")
	fmt.Println(matrix)

	for step := 0; step < len(matrix)-1; step++ {
		pivot := matrix[step][step]

		/// now it goes until the last colunm
		for i := step + 1; i < len(matrix); i++ {
			multiplier := matrix[i][step] / pivot

			for j := step; j < len(matrix); j++ {
				matrix[i][j] -= multiplier * matrix[step][j]

				/// here the indices currently being zero will be replaced by the multiplier
				matrix[i][step] = multiplier
			}

		}

	}

	/// getting the vector of results
	results := make([]float64, len(matrix))
	for i := 0; i < len(matrix); i++ {
		results[i] = matrix[i][len(matrix)]
	}

	fmt.Println("Final matrix:")
	fmt.Println(matrix)

	L := build_L_matrix(matrix)
	fmt.Println("L matrix: ")
	fmt.Println(L)

	U := build_U_matrix(matrix)
	fmt.Println("U matrix: ")
	fmt.Println(U)

	/// now we need to solve those systems
	/// a) Ly = b, L * variable = results
	
}

func read_matrix2() [][]float64 {
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

func build_L_matrix(matrix [][]float64) [][]float64 {

	L := make([][]float64, len(matrix))

	for i := 0; i < len(matrix); i++ {
		L[i] = make([]float64, len(matrix[i])-1) // Initialize each row
		for j := 0; j < len(matrix); j++ {
			if i == j {
				L[i][j] = 1
			} else if i > j {
				L[i][j] = matrix[i][j]
			} else {
				L[i][j] = 0
			}
		}

	}
	return L
}

func build_U_matrix(matrix [][]float64) [][]float64 {
	U := make([][]float64, len(matrix))

	for i := 0; i < len(matrix); i++ {
		U[i] = make([]float64, len(matrix[0])-1)
		for j := 0; j < len(matrix); j++ {
			if i > j {
				U[i][j] = 0
			} else {
				U[i][j] = matrix[i][j]
			}

		}
	}
	return U
}
