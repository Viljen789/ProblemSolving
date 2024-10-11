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
bool trav(TreeNode* p, TreeNode* q){
    if(p->val != q->val)return 0;
    if(((p->left!=nullptr)+(q->left!=nullptr))==1)return 0;
    if(((p->right!=nullptr)+ (q->right!=nullptr))==1)return 0;
    if(p->left&&p->right){
        return (trav(p->left, q->left) + trav(p->right, q->right))==2;
    }
    else if(p->right)return trav(p->right, q->right);
    else if(p->left)return trav(p->left, q->left);
    else return true;
}



class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p)return (!q);
        if(!q)return (!p);
        return trav(p, q);

    }
};