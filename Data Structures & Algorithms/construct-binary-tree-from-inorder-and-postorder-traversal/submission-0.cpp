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
unordered_map<int,int>mp;
int post;
TreeNode* solve(vector<int>&postorder,int in,int end){
    if(in>end) return NULL;
    TreeNode* root=new TreeNode(postorder[post--]);
int index=mp[root->val];
root->right=solve(postorder,index+1,end);
root->left=solve(postorder,in,index-1);
return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        post=postorder.size()-1;
        return solve(postorder,0,inorder.size()-1);
    }
};