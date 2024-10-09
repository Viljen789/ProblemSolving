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
        
void trav(TreeNode *cur){
    if(cur->left!=nullptr)trav(cur->left);
    if(cur->right!=nullptr)trav(cur->right);
    TreeNode *temp;
    temp = cur->left;
    cur->left = cur->right;
    cur->right = temp;
}



class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr)return root;
        trav(root);
        return root;
    }
};