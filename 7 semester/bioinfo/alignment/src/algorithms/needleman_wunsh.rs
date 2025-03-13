use core::panic;
// https://www.cs.sjsu.edu/~aid/cs152/NeedlemanWunsch.pdf
use std::cmp::{self, max};

const GAP: i32 = -1;
// Creates the dynamic program matrix for the Needleman Wunsh algorithm
/// using fixed scored and mismatches penalties
///
/// The Needleman Wunsh algorithm is a LCS assigning score for matches
/// and penalties for mismatches and gaps.
///
/// TODO: For a while it is using a single value for mismatching penalty
///       in the future should be able to read a score matrix or something
///
fn create_dp_matrix(n: usize, m: usize) -> Vec<Vec<i32>> {
    let mut matrix = vec![vec![0; m + 1]; n + 1];

    // fill the first row and column with multiples of the gap
    for i in 1..=m {
        matrix[0][i] = (i as i32) * GAP;
    }
    for i in 1..=n {
        matrix[i][0] = (i as i32) * GAP;
    }

    matrix
}

/// Creates a score matrix that assigns a score for alignment or or not misalignment
///
/// The score matrix has the format
/// A C G T
/// A
/// C
/// G
/// T
///
/// Where (A,C) is the penalty for the misalignment of A and C
///  
/// TODO: For a while it is hard-coded, but it should be able to be read
/// from a file or from user
fn create_score_matrix() -> Vec<Vec<i32>> {
    vec![
        vec![1, -1, -1, -1],
        vec![-1, 1, -1, -1],
        vec![-1, -1, 1, -1],
        vec![-1, -1, -1, 1],
    ]
}

/// Return the score of s1 and s2
fn score(s1: char, s2: char, score: &Vec<Vec<i32>>) -> i32 {
    let nucleotides = ['A', 'C', 'G', 'T'];

    let index1 = nucleotides.iter().position(|&n| n == s1).unwrap();
    let index2 = nucleotides.iter().position(|&n| n == s2).unwrap();

    score[index1][index2]
}

///  Returns the length of the best found global alignment and the string.
///
/// The recursion that built the global alignment matrix is given :
///
/// D(i,j) = max { D(i-1, j-1) + score(xi,yj)
///                D(i-1, j) + gap
///                 D(i, j-1) + g
///                 }  
pub fn global_alignment(s1: Vec<char>, s2: Vec<char>) -> (i32, String, String) {
    let n = s1.len();

    let m = s2.len();

    let mut matrix = create_dp_matrix(n, m);

    let score_matrix = create_score_matrix();

    for i in 1..=n {
        for j in 1..=m {
            matrix[i][j] = max(
                max(
                    matrix[i - 1][j - 1] + score(s1[i - 1], s2[j - 1], &score_matrix),
                    matrix[i][j - 1] + GAP,
                ),
                matrix[i - 1][j] + GAP,
            )
        }
    }

    let mut alignment_s1 = String::new();
    let mut alignment_s2 = String::new();

    let mut i = n;
    let mut j = m;

    while i > 0 && j > 0 {
        // if max is diagonal
        if i > 0
            && j > 0
            && matrix[i][j] == matrix[i - 1][j - 1] + score(s1[i - 1], s2[j - 1], &score_matrix)
        {
            alignment_s1.push(s1[i - 1]);
            alignment_s2.push(s2[j - 1]);
            i -= 1;
            j -= 1;
        }
        // if the maximum is up
        else if i > 0 && matrix[i][j] == matrix[i - 1][j] + GAP {
            alignment_s1.push(s1[i - 1]);

            alignment_s2.push('-');

            i -= 1;
        }
        // max is left
        else {
            alignment_s1.push('-');
            alignment_s2.push(s2[j - 1]);
            j -= 1;
        }
    }

    // for row in &matrix {
    //     println!("Linha1: {:?}", row);
    // }

    (matrix[n][m], alignment_s1.chars().rev().collect(), alignment_s2.chars().rev().collect())
}
