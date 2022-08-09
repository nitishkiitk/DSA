// Given the root of a binary tree, return all root-to-leaf paths in any order.

// A leaf is a node with no children.

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
    vector<string>res;
    void paths(TreeNode* root, string temp){
        // whole paths function simila to the binary Tree Paths except the addng as we have to add "->" also after root so wer have changed
        if(!root)return;
        temp+="->"+to_string(root->val);
        if(!root->left && !root->right){
            res.push_back(temp);
        }
        else{
            paths(root->left,temp);
            paths(root->right,temp);
        }
        // here qwe have call the pop function twice as we have to pop "->" also
        temp.pop_back();
        temp.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        // A string that will be pushed t result vector
        string temp="";
        // if the tree is null then return empty
        if(!root)return res;
        // if tree is not null then add the root val t temp
        temp+=to_string(root->val);
        // if tree of size 1 then add the tmp to res and not go to paths function
        if(!root->left && !root->right){
            res.push_back(temp);
        }
        // if tree size is greater than 1 then will g to path function 
        else{
            paths(root->left,temp);
            paths(root->right,temp);
        }
        return res;
    }
};