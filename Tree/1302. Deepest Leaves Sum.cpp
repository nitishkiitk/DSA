// Given the root of a binary tree, return the sum of values of its deepest leaves.
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
    // function for calculating height of tree
    int height(TreeNode *root){
        if(!root)return 0;
        return 1 + max(height(root->left),height(root->right));
    }
    // function for calculation longest leaf sum
    void sumleaf(TreeNode * root, int height, int &sum){
        if(!root) return;
        if(height==1){sum+=root->val;}
        sumleaf(root->left, height-1,sum);
        sumleaf(root->right,height-1,sum);
    }
    int deepestLeavesSum(TreeNode* root) {
        // first find the height of tree
        int h=height(root);
        // intialise sum as zero
        int sum=0;
        // then call sumleaf functio 
        sumleaf(root,h,sum);
        return sum;
    }
};