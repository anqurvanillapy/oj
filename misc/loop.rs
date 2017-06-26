/**
 *  Loop
 *  ====
 *
 *  `loop` is the right `while true` in Rust.
 */

fn main() {
    let x;

    // The compiler does not semantically infer that an undeclared variable that
    // is set inside a `while true' loop must always be inited if breaking out
    // of the loop.
    // while true { x = 42; break; }

    // `loop' helps the compiler reason about the loops.
    loop { x = 42; break; }

    println!("x={}", x);
}
