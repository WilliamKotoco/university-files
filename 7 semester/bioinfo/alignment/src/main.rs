use alignment::algorithms::lcs;
use alignment::algorithms::needleman_wunsh;
use alignment::algorithms::smith_homemagua;
use alignment::dataloader::dataloader;
use core::panic;
use std::fs::File;
use std::io::{self, Write};
fn main() {
    let mut s1 = String::new();
    let mut s2 = String::new();
   // let vec_s1 = dataloader::read_alignment_from_file(String::from("covid.txt"));
    //let vec_s2 = dataloader::read_alignment_from_file(String::from("covid2.txt"));
    let score;

    
    
    let mut s1 = String::from("GGATCGA");
    let mut s2 = String::from("GAATTCAGTTA");
    
   // (score, s1, s2) = needleman_wunsh::global_alignment(vec_s1, vec_s2);

    (score, s1, s2) = smith_homemagua::local_alignment(s1.chars().collect(), s2.chars().collect());
   println!("{s1}");
    println!("{s2}");

    println!("Score is {score}");
}
