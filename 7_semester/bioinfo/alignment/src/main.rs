use alignment::algorithms::lcs;
use alignment::algorithms::needleman_wunsh;
use alignment::algorithms::smith_homemagua;
use alignment::dataloader::dataloader;
use core::panic;
use std::fs::File;
use std::io::{self};
use std::io::Write;


/// TODO: this is shitty code, modularize later
fn main() {
    println!("{}", std::env::current_dir().unwrap().display());

    println!("Enter the option: ");
    println!("[1] - Read sequence from files");
    println!("[2] - Read from input");

    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read");

    let op: i32 = match input.trim().parse() {
        Ok(num) => num,
        Err(_) => {
            panic!("Please enter a valid string")
        }
    };

    let vec_s1: Vec<char>;
    let vec_s2: Vec<char>;

    match op {
        1 => {
            let mut file1 = String::new();
            println!("Input the name of the first file: ");
            io::stdin().read_line(&mut file1).expect("Failed to read");

            file1 = file1.trim_end().to_string();

            let mut file2 = String::new();
            println!("Input the name of the second file: ");
            io::stdin().read_line(&mut file2).expect("Failed to read");

            file2 = file2.trim_end().to_string();
            vec_s1 = dataloader::read_alignment_from_file(file1);
            vec_s2 = dataloader::read_alignment_from_file(file2);
        }

        2 => {
            (vec_s1, vec_s2) = dataloader::read_alignment_from_user();

            println!("{:?}", vec_s1);
        }

        _ => panic!("Invalid option"),
    }

    println!("Enter the algorithm: ");
    println!("[1] - LCS");
    println!("[2] - Needleman Wunsh");
    println!("[3] - Smith Waterman");
    let score;
    let mut s1 = String::new();
    let mut s2 = String::new();

    input.clear();

    io::stdin().read_line(&mut input).expect("Failed to read");

    let op2: i32 = match input.trim().parse() {
        Ok(num) => num,
        Err(_) => {
            println!("{}", input.trim());
            panic!("Please enter a valid number")
        }
    };

    match op2 {
        1 => {
            (score, s1) = lcs::lcs(vec_s1, vec_s2);
            println!("Score is {score}");
            println!("{s1}");
            // gambiarra
            return;
        }

        2 => {
            (score, s1, s2) = needleman_wunsh::global_alignment(vec_s1, vec_s2);
        }

        3 => {
            (score, s1, s2) = smith_homemagua::local_alignment(vec_s1, vec_s2);
        }

        _ => panic!("Enter a valid option"),
    }

    if s1.len() > 500 || s2.len() > 500 {
        

        println!("Score: {score}");
        let mut file_s1 =
            File::create("alignment_s1.txt").expect("Erro ao criar o arquivo alignment_s1.txt");

        writeln!(file_s1, "s1:\n{s1}").unwrap();

        let mut file_s2 =
            File::create("alignment_s2.txt").expect("Erro ao criar o arquivo alignment_s2.txt");
        writeln!(file_s2, "s2:\n{s2}").unwrap();

        println!("Result too large, saved in alignment_s1.txt and alignment_s2.txt");
    } else {
        println!("s1: {s1}");
        println!("s2: {s2}");
        println!("Score: {score}");
    }
}
