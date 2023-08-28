package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {

	matrix := read_matrix4()
	L := make([][]float64, len(matrix))
	U := make([][]float64, len(matrix))

	/// initialize L and U matrix
	for i := 0; i < len(matrix); i++ {
		L[i] = make([]float64, len(matrix))
	}

	for i := 0; i < len(matrix); i++ {
		U[i] = make([]float64, len(matrix))
	}

	solutions := make([]float64, len(matrix))

	for i := 0; i < len(matrix); i++ {
		solutions[i] = matrix[i][len(matrix)]
	}

	/// U matrix
	for row := 0; row < len(matrix); row++ {

		for column := row; column < len(matrix); column++ {
			var sum float64 = 0

			for r := 0; r < row; r++ {
				sum += L[row][r] * U[r][column]
			}
			U[row][column] = matrix[row][column] - sum /// divided by Lii which is always 1 by definition
		}

		for k := row; k < len(matrix); k++ {
			if row == k {
				L[k][row] = 1
			} else {
				var sum float64 = 0
				for r := 0; r < len(matrix); r++ {
					sum += L[k][r] * U[r][row]
				}

				L[k][row] = (matrix[k][row] - sum) / U[row][row]
			}
		}
	}

	/// now solve the equation
	/// i) Ly = solutions
	/// ii) Ux = y

	fmt.Println(L)
	fmt.Println(U)
	Y := solve_Ly(L, solutions)

	X := solveUx(U, Y)

	fmt.Println(X)
}

func read_matrix4() [][]float64 {
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

func solve_Ly(L [][]float64, results []float64) []float64 {
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

func solveUx(U [][]float64, Y []float64) []float64 {
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
