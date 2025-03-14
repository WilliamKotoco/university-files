use alignment::algorithms::lcs;
use alignment::algorithms::needleman_wunsh;
use alignment::dataloader::dataloader;
use core::panic;
use std::fs::File;
use std::io::{self, Write};
fn main() {
    let mut s1 = String::new();
    let mut s2 = String::new();
    let vec_s1 = dataloader::read_alignment_from_file(String::from("covid.txt"));
    let vec_s2 = dataloader::read_alignment_from_file(String::from("covid2.txt"));
    let score;

    let len = vec_s1.len();

    println!("Letter : {0}", vec_s2[60]);
    (score, s1, s2) = needleman_wunsh::global_alignment(vec_s1, vec_s2);

    if s1.len() > 250 || s2.len() > 250 {
        println!("Sequence too large to print...  Writing in a file output.txt");

        match dataloader::write_to_file(s1, s2) {
            Ok(_) => println!("Sequences have been stored"),
            Err(e) => eprintln!("Error writing to a file {}", e),
        }
    }
    println!("{s1}");
    println!("{s2}");

    println!("Score is {score}");
}
