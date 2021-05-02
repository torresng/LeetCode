impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = std::collections::HashMap::new();
        for (idx, val) in nums.iter().enumerate() {
            match map.get(&(target-val)) {
                Some(x) => { return vec![*x, idx as i32]; }
                None => { map.insert(val, idx as i32); }
            }
        }
        return vec![-1,-1];
    }
}
