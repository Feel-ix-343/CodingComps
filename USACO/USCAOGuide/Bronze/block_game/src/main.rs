fn main() {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).expect("FAIL");

    let n: u32 = match line.trim().parse() {
        Ok(num) => num,
        Err(_) => 0,
    };

    let mut m = [0; 26];

    for _ in 0..n {
        let mut card = String::new();
        std::io::stdin().read_line(&mut card).expect("FAIL");
        let wds: Vec<&str> = card.splitn(2, ' ').collect();
        let (w1, w2) = (wds[0], wds[1]);
        for i in 0u8..26u8 {
            let char = (i + 97) as char;
            m[i as usize] += std::cmp::max(w1.matches(char).count(), w2.matches(char).count())
        }
    }
    m.iter().for_each(|&x| println!("{}", x));
}
