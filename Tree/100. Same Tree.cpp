// Given the roots of two binary trees p and q, write a function to check if they are the same or not.

// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if both are null then true
        if(!p && !q) return true;
        // if anyone one null and other not null then false
        if(p && !q) return false;
        if(!p && q) return false;
        // if both are null and val are not same then false
        if(p->val!=q->val)return false;
        // if both node val are same then check the chuild node
        return isSameTree(p->left , q->left) && isSameTree(p->right, q->right);
    }
};