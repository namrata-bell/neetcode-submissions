/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    void preorder(TreeNode* root, string &s) {

        if(root == NULL){
            s += "#,";
            return;
        }

        s += to_string(root->val) + ",";

        preorder(root->left, s);

        preorder(root->right, s);
    }

    string serialize(TreeNode* root) {

        string s = "";

        preorder(root, s);

        return s;
    }

    TreeNode* build(string &data, int &i){

        // Null node
        if(data[i] == '#'){
            i += 2;          // Skip "#,"
            return NULL;
        }

        // Read number
        string num = "";

        while(data[i] != ','){
            num += data[i];
            i++;
        }

        i++;                 // Skip ','

        TreeNode* root = new TreeNode(stoi(num));

        root->left = build(data, i);

        root->right = build(data, i);

        return root;
    }

    TreeNode* deserialize(string data) {

        int i = 0;

        return build(data, i);
    }
};