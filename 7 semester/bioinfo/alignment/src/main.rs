use alignment::dataloader::dataloader;
use alignment::algorithms::lcs;
use alignment::algorithms::needleman_wunsh;
fn main() {

    let mut s1 = String::from("GCAT");
    let mut s2 = String::from("GATT");

    let vec_s1: Vec<char> = s1.chars().collect();
    let vec_s2: Vec<char> = s2.chars().collect();
    let mut score;


    (score, s1, s2) = needleman_wunsh::global_alignment(vec_s1, vec_s2);


    println!("Score is {score}");
    println!("{s1}");
    println!("{s2}");




}
