// https://www.cs.sjsu.edu/~aid/cs152/NeedlemanWunsch.pdf

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

    // hardcoded values for a while
    let mismatching = -5;
    let matching = 2;


    unimplemented!();
    // matrix
}
