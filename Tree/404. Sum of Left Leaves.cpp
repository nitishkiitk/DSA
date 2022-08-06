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
    int sumOfLeftLeaves(TreeNode* root) {
        // if null root then zero
        if(!root) return 0;
        TreeNode* Temp=root->left, *TempR=root->right;
        // if it is only root then also left leave node suim is zero
        if(!Temp && !TempR)return 0;
        // if left is null but right is there then we have to take care of that
        if(!Temp && TempR){
            return sumOfLeftLeaves(TempR);
        }
        // if left exist then will add if leaf node and pass top the right one
        if(!Temp->left && !Temp->right){
            return Temp->val + sumOfLeftLeaves(TempR);
            
        }
        // otherwise pass to normal condition
        return sumOfLeftLeaves(root->left)+ sumOfLeftLeaves(root->right);
    }
};