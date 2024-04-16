// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::collections::VecDeque;  //--> added this to remove error 
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn add_one_row(root: Option<Rc<RefCell<TreeNode>>>, val: i32, depth: i32) -> Option<Rc<RefCell<TreeNode>>> {
        if depth == 1 {
            let new_root = Rc::new(RefCell::new(TreeNode::new(val)));
            new_root.borrow_mut().left = root.clone(); // Clone the root here
            return Some(new_root);
        }

        let mut queue = VecDeque::new();
        if let Some(node) = root.clone() { // Clone the root here
            queue.push_back(node);
        }
        let mut level = 1;

        while !queue.is_empty() && level < depth - 1 {
            for _ in 0..queue.len() {
                let node = queue.pop_front().unwrap();
                let node = node.borrow();
                if node.left.is_some() {
                    queue.push_back(node.left.as_ref().unwrap().clone());
                }
                if node.right.is_some() {
                    queue.push_back(node.right.as_ref().unwrap().clone());
                }
            }
            level += 1;
        }

        while let Some(node) = queue.pop_front() {
            let mut node = node.borrow_mut();
            let temp = node.left.take();
            node.left = Some(Rc::new(RefCell::new(TreeNode::new(val))));
            node.left.as_ref().unwrap().borrow_mut().left = temp;

            let temp = node.right.take();
            node.right = Some(Rc::new(RefCell::new(TreeNode::new(val))));
            node.right.as_ref().unwrap().borrow_mut().right = temp;
        }

        root   
    }
}
