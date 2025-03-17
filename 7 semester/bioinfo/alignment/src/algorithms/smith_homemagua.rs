use std::{cmp::max, f64::MAX};
/// http://web.tecnico.ulisboa.pt/ana.freitas/bioinformatics.ath.cx/bioinformatics.ath.cx/index2568.html?id=49
/// https://www.biogem.org/downloads/notes/kau/Local%20Alignment.pdf
///
///
const GAP: i32 = -4;
// Creates a score matrix that assigns a score for alignment or or not misalignment
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
        vec![5, -3, -3, -3],
        vec![-3, 5, -3, -3],
        vec![-3, -3, 5, -3],
        vec![-3, -3, -3, 5],
    ]
}

/// Return the score of s1 and s2
fn score(s1: char, s2: char, score: &Vec<Vec<i32>>) -> i32 {
    let nucleotides = ['A', 'C', 'G', 'T'];

    let index1 = nucleotides.iter().position(|&n| n == s1).unwrap();
    let index2 = nucleotides.iter().position(|&n| n == s2).unwrap();

    score[index1][index2]
}

/// Creates the dynamic programming matrix for smith-waterman algorithm.
///
/// As local alignment methods aligns only exact matching terms
/// in the sequence, there are no negative score and the first
/// row and colunm are initialized with zero.
///
fn create_dp_matrix(n: usize, m: usize) -> Vec<Vec<i32>> {
    vec![vec![0; m + 1]; n + 1]
}

///  Returns the length of the best local alignment and the respective alignments as a tuple
///
/// The DP matrix is built using the same recursion as the needleman_wunsh algorithm. However,
/// if score becomes negative the value is set to zero.
pub fn local_alignment(s1: Vec<char>, s2: Vec<char>) -> (i32, String, String) {
    let n = s1.len();

    let m = s2.len();
    let mut dp = create_dp_matrix(n, m);

    let score_matrix = create_score_matrix();

    let mut max_score = 0;
    let mut max_score_position = (0, 0);
    for i in 1..=n {
        for j in 1..=m {
            dp[i][j] = max(
                max(
                    dp[i - 1][j - 1] + score(s1[i - 1], s2[j - 1], &score_matrix),
                    dp[i - 1][j] + GAP,
                ),
                dp[i][j - 1] + GAP,
            );

            // local alignment has no negative scores
            if dp[i][j] < 0 {
                dp[i][j] = 0
            };

            if dp[i][j] > max_score {
                max_score = dp[i][j];
                max_score_position = (i, j);
            }
        }
    }

    let mut i;
    let mut j;
    let mut curr_value = max_score;
    let mut s1_aligned = String::new();
    let mut s2_aligned = String::new();
    (i, j) = max_score_position;

    while curr_value != 0 {
        if dp[i][j] == dp[i - 1][j - 1] + score(s1[i - 1], s2[j - 1], &score_matrix) {
            s1_aligned.push(s1[i - 1]);
            s2_aligned.push(s2[j - 1]);
            i -= 1;
            j -= 1;
        } else if dp[i][j] == dp[i][j - 1] + GAP {
            s1_aligned.push('-');
            s2_aligned.push(s2[j - 1]);
            j -= 1;
        } else if dp[i][j] == dp[i - 1][j] + GAP {
            s1_aligned.push(s1[i - 1]);
            s2_aligned.push('-');
            i -= 1;
        }

        curr_value = dp[i][j];
    }

    //for row in &dp {
    //      println!("Linha1: {:?}", row);
    // }

    (
        max_score,
        s1_aligned.chars().rev().collect(),
        s2_aligned.chars().rev().collect(),
    )
}
