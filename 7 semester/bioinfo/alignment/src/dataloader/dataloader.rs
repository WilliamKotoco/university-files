use std::fs;
use std::io;
use std::path;
/// Read alignment from file and return it as a char vector
fn read_alignment_from_file(file_name: String) -> Vec<char> {
    let file = path::PathBuf::from(env!("CARGO_MANIFEST_DIR"))
        .join("data")
        .join(file_name)
        .join(".txt");

    match fs::read_to_string(&file) {
        Ok(content) => {
            let s: Vec<char> = content.chars().collect();
            s 
        },
        Err(e) => panic!("Failed to read file {}", e),
    }
    
}


/// Read alignment two aligments from user and return them as a tuple of vec<char>
/// TODO: implement better verification to avoid numbers or special characters
fn read_alignment_from_user() -> (Vec<char>, Vec<char>) {
    let mut s1 = String::new();
    let mut s2 = String::new();
    println!("Enter the first alignment: ");

    io::stdin().read_line(&mut s1).expect("Failure reading string");

    print!("Enther the second alignment: ");
    io::stdin().read_line(&mut s2).expect("Failure reading string");

    (s1.to_ascii_uppercase().chars().collect(), s2.to_ascii_uppercase().chars().collect())
}