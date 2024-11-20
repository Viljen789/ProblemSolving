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

int depth(TreeNode* root, int cur){
    if(root->left&&root->right)return min(depth(root->left, cur+1), depth(root->right, cur+1));
    if(root->left)return depth(root->left, cur+1);
    if(root->right)return depth(root->right, cur+1);
    return cur;
}
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        return depth(root, 1);
    }
};