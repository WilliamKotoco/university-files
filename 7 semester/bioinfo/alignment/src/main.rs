use alignment::algorithms::lcs;
use alignment::algorithms::needleman_wunsh;
use alignment::dataloader::dataloader;
fn main() {

    let mut s1 = String::new();
    let mut s2 = String::new();
    let vec_s1 = dataloader::read_alignment_from_file(String::from("human.txt"));
    let vec_s2 = dataloader::read_alignment_from_file(String::from("dog.txt"));
    let score;

    let len = vec_s1.len();

    println!("{len}");
    (score, s1, s2) = needleman_wunsh::global_alignment(vec_s1, vec_s2);

    println!("Score is {score}");
    println!("{s1}");
    println!("{s2}");
}
