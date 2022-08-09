// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

// Note: A leaf is a node with no children.
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
    int mindepth(TreeNode* root) {
        // in case of min when for a root one part is null and another is not null then in that we want min to be not null part so we put null part count to be INT_MAX
        if(!root) return INT_MAX;
        // if the node is a leaf node then we will return 1
        if(!root->left && !root->right) return 1;
        // every root will contribute 1 so will add 1 and then min of both left ad right part
        return 1 + min(mindepth(root->left), mindepth(root->right));
    }
    int minDepth(TreeNode* root) {
        // I have written this line for taking care of empty tree only
        if(!root) return 0;
        // else we will move to mindepth function
        return mindepth(root);
    }
};