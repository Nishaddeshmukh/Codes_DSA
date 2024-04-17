//Smallest String Starting From Leaf ->  lexicographically smallest string that starts at a leaf of this tree and ends at the root.


use std::collections::VecDeque;
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn smallest_from_leaf(root: Option<Rc<RefCell<TreeNode>>>) -> String {
        let mut path = Vec::new();
        let mut smallest_str = "~".to_string();
        let mut st = VecDeque::new();
        st.push_back((root, false));

        while !st.is_empty() {
            let (node, visited) = st.pop_back().unwrap();

            if let Some(real_node) = node {
                if visited {
                    path.pop();
                } else {
                    path.push(real_node.borrow().val);
                    st.push_back((Some(real_node.clone()), true));  

                    if real_node.borrow().right.is_some() {
                        st.push_back((real_node.borrow().right.clone(), false));
                    }
                    if real_node.borrow().left.is_some() {
                        st.push_back((real_node.borrow().left.clone(), false));
                    }

                    // If it's a leaf node, update the smallest string
                    if real_node.borrow().left.is_none() && real_node.borrow().right.is_none() {
                        let str: String = path.iter().rev().map(|&x| (x as u8 + b'a') as char).collect();
                        if str < smallest_str {
                            smallest_str = str;
                        }
                    }
                }
            }
        }

        smallest_str
    }
}       
