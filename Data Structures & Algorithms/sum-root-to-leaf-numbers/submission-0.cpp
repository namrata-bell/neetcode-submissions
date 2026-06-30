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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    void solve(TreeNode* root, int curr, int &sum) {
        if (root == NULL)
            return;

        curr = curr * 10 + root->val;

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            sum += curr;
            return;
        }

        solve(root->left, curr, sum);
        solve(root->right, curr, sum);
    }

public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        solve(root, 0, sum);
        return sum;
    }
};