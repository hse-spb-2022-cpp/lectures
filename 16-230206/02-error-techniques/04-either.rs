// https://doc.rust-lang.org/book/ch09-02-recoverable-errors-with-result.html
use std::fs::File;
use std::io::Read;

fn main() {
    let mut f = match File::open("hello.txt") {  // We have to check.
        Ok(file) => file,
        Err(error) => {
            println!("Problem opening the file: {:?}", error);
            return
        },
    };
    let mut s = String::new();
    match f.read_to_string(&mut s) {
        Ok(_) => println!("File read: {:?}", s),
        Err(e) => {
            println!("Problem reading the file: {:?}", e);
            return
        }
    }
}
