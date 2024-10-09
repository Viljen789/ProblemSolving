/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// finnne den først noden der den ene er på en side og den andre er på den andre siden. 


TreeNode* rec(TreeNode* root, int p, int q){
    if(p<=root->val&&q>=root->val)return root;
    else if(root->val>q)return rec(root->left, p, q);
    else return rec(root->right, p, q);
}


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return rec(root, min(p->val, q->val),  max(p->val, q->val));
    }
    
};