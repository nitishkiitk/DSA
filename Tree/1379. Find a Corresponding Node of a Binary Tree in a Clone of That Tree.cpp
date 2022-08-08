// Given two binary trees original and cloned and given a reference to a node target in the original tree.

// The cloned tree is a copy of the original tree.

// Return a reference to the same node in the cloned tree.

// Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        // if original exist then will compare it with target at root itself 
        if(original){
            if(original==target) return cloned;
            // if it will not match at the root then will move further and look in left part
            TreeNode* temp=getTargetCopy(original->left, cloned->left, target);
            if(temp) return temp;
            // if left part will not contain then will move to right part
            return getTargetCopy(original-> right, cloned->right, target);
        }
        // if the tree not contain target then will return nullptr
        return nullptr;
    }
};