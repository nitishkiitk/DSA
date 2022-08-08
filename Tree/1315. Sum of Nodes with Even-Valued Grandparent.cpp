// Given the root of a binary tree, return the sum of values of nodes with an even-valued grandparent. If there are no nodes with an even-valued grandparent, return 0.

// A grandparent of a node is the parent of its parent if it exists.
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
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        // checking if root exist or not
        if(root){
            // checkimng the root is even or odd if even then fi insisde otherwise continue
            if(root->val%2==0){
                // moving left
                if(root->left){
                    // checking values and adding if they exist
                    if(root->left->left) sum+=root->left->left->val;
                    if(root->left->right)sum+=root->left->right->val;
                }
                // moving right
                if(root->right){
                    // checking values and adding if they exist
                    if(root->right->left) sum+=root->right->left->val;
                    if(root->right->right)sum+=root->right->right->val;
                }
            }
            // calling the same function for left part and right part
            sum+=sumEvenGrandparent(root->left);
            sum+=sumEvenGrandparent(root->right);
        }
        return sum;
    }
};
