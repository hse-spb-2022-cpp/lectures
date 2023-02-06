// https://doc.rust-lang.org/book/ch09-02-recoverable-errors-with-result.html
use std::fs::File;
use std::io::Error;
use std::io::Read;

fn main() -> Result<(), Error> {
    let mut f = File::open("hello.txt")?;  // '?' is a shortcut for "if failure, return Err()".
    let mut s = String::new();
    f.read_to_string(&mut s)?;
    println!("File read: {:?}", s);
    Ok(())
}
