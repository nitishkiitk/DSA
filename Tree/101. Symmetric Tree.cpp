// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

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
    bool isMirror(TreeNode* l, TreeNode* r ){
        // if both null then true
        if(!l && !r) return true;
        // if anyone different then false;
        if(!l && r) return false;
        if(l && !r) return false;
        // compare val;
        if(l->val!=r->val)return false;
        return isMirror(l->left, r->right) && isMirror(l->right, r->left);
        
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        // checking whether the trre is mirror of each other or not
        return isMirror(root->left, root->right);
    }
};