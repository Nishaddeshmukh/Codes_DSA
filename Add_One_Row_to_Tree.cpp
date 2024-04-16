TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (root == NULL) return root;

        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        std::queue<TreeNode*> q;
        q.push(root);
        int level = 1;

        while (!q.empty() && level < depth - 1) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            level++;
        }

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            TreeNode* temp = node->left;
            node->left = new TreeNode(val);
            node->left->left = temp;

            temp = node->right;
            node->right = new TreeNode(val);
            node->right->right = temp;
        }

        return root;
}
