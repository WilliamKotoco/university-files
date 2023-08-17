package main

/*
This program aims to solve a system equation using the Lu factoring.

The main difference is that we store the multipliers on the zeros and get
Ax = B as (LU)x = b, where L is a lower triangular matrix and U is an upper  triangular
matrix

After that decomposition, we make y = Ux and obtain the resolution through the following system:
i) Ly = b
ii) Ux = y
*/
import (
	"bufio"
	"fmt"
	"math"
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
	Y := solution_first_system(L, results)
	fmt.Println("Solution of Y equation: ")
	fmt.Println(Y)

	/// finally, solve the system b) Ux =y where the solution is the solution for the entire system
	final_solution := solve_final_system(U, Y)
	fmt.Println("Final solution of the system: ")
	fmt.Println(final_solution)
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

// / The first system consists in a lower triangular matrix.
func solution_first_system(L [][]float64, results []float64) []float64 {
	size := len(L)
	solution := make([]float64, size)

	solution[0] = results[0] / L[0][0]

	for step := 1; step < size; step++ {
		var sum float64 = 0
		for i := 0; i < step; i++ {
			sum += L[step][i] * solution[i]
		}
		solution[step] = (results[step] - sum) / L[step][step]
	}
	return solution
}

// / Solve an upper triangular system equation
func solve_final_system(U [][]float64, Y []float64) []float64 {
	last_index := len(U) - 1
	solution := make([]float64, len(Y))

	solution[last_index] = math.Round(Y[last_index] / U[last_index][last_index])

	for step := last_index - 1; step >= 0; step-- {
		var sum float64 = 0
		for i := step + 1; i < last_index+1; i++ {
			sum += U[step][i] * solution[i]
		}

		solution[step] = math.Round((Y[step] - sum) / U[step][step])
	}
	return solution
}
