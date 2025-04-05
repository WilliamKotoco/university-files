/// algorithm used for global sequence alignment using DP
/// similar to LCS, but with different scores for mismatching and for matching and containing gaps

// https://www.cs.sjsu.edu/~aid/cs152/NeedlemanWunsch.pdf
use std::io;
use std::cmp;


fn create_dp_matrix(n: usize, m: usize) -> Vec<Vec<i32>> {
    vec![vec![0; m + 1]; n + 1]
}

/// TODO: Read a matrix instead of setting the same mismatch score
fn create_mismatch_score_matrix(n: usize, m: usize) -> Vec<Vec<i32>>{

    let mismatching = -5
    let matching = 2

    /// (0..n) create a sequence from 0 to n-1
    /// .map(|i| (0..m)) applies a closure to each index from the sequence (0..n) that generates anotehr sequence (0..m), which is the columns for each row
    /// 
    ///  for each column we map the values of j  to either matching or mismatching depending on the condition i == j
    /// 
    /// after we use the .collect() to collect the result of map into Vec<i32>  to create a row
    /// after we use .collect() to collect the rows in the matrix
    let matrix = (0..n).map(|i| (0..m).map(|j| if i == j {matching} else {mismatching}).collect()).collect();

    matrix
}
