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

class Codec {
public:
void preorder(TreeNode* root,string &s){
    if(root==NULL){
        s+="#,";
        return;
    }
    s+=to_string(root->val)+",";
    preorder(root->left,s);
    preorder(root->right,s);
}
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        preorder(root,s);
        return s;
    }
    TreeNode* build(string &data,int &i){
        if(data[i]=='#'){
            i+=2;
            return NULL;
        }
        string num="";
        while(data[i]!=','){
        num+=data[i];
        i++;
        }
        i++;
        TreeNode* root=new TreeNode(stoi(num));
        root->left=build(data,i);
        root->right=build(data,i);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
       return  build(data,i);
        
    }
};
