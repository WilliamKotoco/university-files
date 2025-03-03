use std::cmp;
use std::io;

fn create_dp_matrix(n: usize, m: usize) -> Vec<Vec<i32>> {
    vec![vec![0; m + 1]; n + 1]
}

fn lcs(s1: Vec<char>, s2: Vec<char>) -> i32 {
    let n = s1.len();
    let m = s2.len();
    let mut matrix = create_dp_matrix(n, m);

    for i in 1..=n {
        for j in 1..=m {
            if s1[i - 1] == s2[j - 1] {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = cmp::max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }

    matrix[n][m]
}

fn main() {
    let mut s1 = String::new();
    let mut s2 = String::new();

    println!("First string: ");
    io::stdin()
        .read_line(&mut s1)
        .expect("Failure reading string");

    println!("Second string: ");
    io::stdin()
        .read_line(&mut s2)
        .expect("Failure reading string");

    // remove \n
    s1 = s1.trim().to_string();
    s2 = s2.trim().to_string();

    let s1: Vec<char> = s1.chars().collect();
    let s2: Vec<char> = s2.chars().collect();

    let lcs = lcs(s1, s2);

    println!("{lcs}")
}
