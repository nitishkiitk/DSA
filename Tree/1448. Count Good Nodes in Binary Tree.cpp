// Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

// Return the number of good nodes in the binary tree.
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
private :
    int search(TreeNode* root, int max){
        if(!root) return 0;
        // checking id root nide is good node or not
        int count=0;
        if(root->val >=max){
            max=root->val;
            count++;
        }
        // calling recursive call for left and right nodes
        count+=search(root->left,max);
        count+=search(root->right,max);
        return count;
    }
public:
    int goodNodes(TreeNode* root) {
        // if the null tree then 0
        if(!root)return 0;
        // if only one node in tree then it will be a good node
        if(!root->left && !root->right) return 1;
        int good=1;
        // otherwise we hve to keep track of max and find the good node count using another function search
        // calling searxh function for lrft node
        good+=search(root->left, root->val);
        // calling search function for right node
        good+=search(root->right, root->val);
        return good;
    }
};