use std::process::{Command, exit};

fn main() {
    /* 
        Fork to a child process, conditionally execute the 
        child or parent process by matching the return value of fork 
    */
    match unsafe { libc::fork() } {
        // If fork fails, print an error message and exit
        -1 => {
            eprintln!("Fork failed!");
            exit(1);
        },
        // If fork succeeds, execute the child process
        0 => {
            println!("Child PID is {}", std::process::id());
            Command::new("whoami")
                .status()
                .expect("Failed to execute command!");
            exit(1);
        },
        // Else, back to parent process
        _ => {
            println!("\nParent PID is {}", std::process::id());
            // Wait for the child process to finish
            unsafe { libc::waitpid(-1, std::ptr::null_mut(), 0) };
            exit(0);
        },
    }
}