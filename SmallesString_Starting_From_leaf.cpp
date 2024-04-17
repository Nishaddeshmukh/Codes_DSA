//Smallest String Starting From Leaf -> lexicographically smallest string that starts at a leaf of this tree and ends at the root.

class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        vector<int> path;
        string smallest_str = "~";  // Initialize with a string larger than any other
        stack<pair<TreeNode*, bool>> st;
        st.push({root, false});

        while (!st.empty()) {
            TreeNode* node = st.top().first;
            bool visited = st.top().second;
            st.pop();

            if (node) {
                if (visited) {
                    //visited all of node's descendants
                    path.pop_back();
                } else {
                    path.push_back(node->val);
                    st.push({node, true});  

                    if (node->right) st.push({node->right, false});
                    if (node->left) st.push({node->left, false});

                    // If it's a leaf node, update the smallest string
                    if (!node->left && !node->right) {
                        string str;
                        for (int i = path.size() - 1; i >= 0; --i) {
                            str += 'a' + path[i];
                        }
                        if (str < smallest_str) {
                            smallest_str = str;
                        }
                    }
                }
            }
        }

        return smallest_str;
    }
};
