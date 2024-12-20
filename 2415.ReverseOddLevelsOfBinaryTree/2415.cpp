/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void initialize(TreeNode* root, int level, queue<int>& nodes) {
        if (root == nullptr) return;
        
        if (level % 2 == 1) {
            nodes.push(root->val);
        }

        level++;

        initialize(root->left, level, nodes);
        initialize(root->right, level, nodes);
    }

    void change(TreeNode* root, int level, queue<int>& nodes) {        
        if (root == nullptr) return;

        if (level % 2 == 1) {
            root->val = nodes.front();
            nodes.pop();
        }

        level++;

        change(root->right, level, nodes);
        change(root->left, level, nodes);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<int> nodes;

        initialize(root, 0, nodes);

        change(root, 0, nodes);

        return root;
    }
};
