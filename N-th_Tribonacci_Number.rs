/*The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.
*/



impl Solution {
    pub fn tribonacci(n: i32) -> i32 {
        let mut tri = [0, 1, 1];
        if n < 3 {
            return tri[n as usize];
        }
        for _ in 3..=n {
            let temp = tri[0] + tri[1] + tri[2];
            tri[0] = tri[1];
            tri[1] = tri[2];
            tri[2] = temp;
        }
        tri[2]       
    }
}
