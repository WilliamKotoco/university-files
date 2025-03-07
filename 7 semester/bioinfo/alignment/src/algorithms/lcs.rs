use std::cmp;

/// Longest Common Subsquence does not impute penalty or scores
fn create_dp_matrix(n: usize, m: usize) -> Vec<Vec<i32>> {
    vec![vec![0; m + 1]; n + 1]
}

/// Return the LCS length and the LCS string
///
/// The LCS solution follows the following recursive equation:
///
/// C(i,j) = C(i-1,j-1) + 1 if xi = yi
///        = max(c(i-1, j), c(i, j-1)) if xi != yi
///        = 0 if i or j == 0
///
/// The lcs can be rebuilt by backtracing on the same conditions defined
/// in the recursive formula
///
pub fn lcs(s1: Vec<char>, s2: Vec<char>) -> (i32, String) {
    let n = s1.len();
    let m = s2.len();

    let mut matrix = create_dp_matrix(n, m);

    for i in 1..=n {
        for j in 1..=m {
            matrix[i][j] = if s1[i - 1] == s2[j - 1] {
                matrix[i - 1][j - 1] + 1
            } else {
                cmp::max(matrix[i][j - 1], matrix[i - 1][j])
            };
        }
    }

    let mut lcs = String::new();
    let mut i = n;
    let mut j = m;

    while i > 0 && j > 0 {
        if s1[i - 1] == s2[j - 1] {
            lcs.push(s1[i - 1]);
            i -= 1;
            j -= 1;
        } else if matrix[i - 1][j] > matrix[i][j - 1] {
            i -= 1;
        } else {
            j -= 1
        }
    }

    // reverse the lcs string because it is built bottom up
    lcs = lcs.chars().rev().collect();

    (matrix[n][m], lcs)
}
