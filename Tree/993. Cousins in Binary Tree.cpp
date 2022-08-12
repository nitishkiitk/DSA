// Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

// Two nodes of a binary tree are cousins if they have the same depth with different parents.

// Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.
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
    int level(TreeNode* root, int a, int h){
    if(!root)return 0;
    if(root->val==a) return h;
    int l=level(root->left, a, h+1);
    if(l!=0){
        return l;
    }
    l=level(root->right,a,h+1);
    return l;
}
bool issibling(TreeNode*root, int a, int b){
    if(!root)return false;
    if(!root->left)return issibling(root->right,a,b);
    if(!root->right)return issibling(root->left,a,b);
    return (root->left->val==a && root->right->val==b)||(root->left->val==b && root->right->val==a)|| issibling(root->left, a,b) || issibling(root->right,a,b);
}
// Returns true if the nodes with values 'a' and 'b' are cousins. Else returns false
bool isCousins(TreeNode *root, int a, int b)
{
   //add code here.
   if(!root || !a || !b)return false;
   int h1=1, h2=1;
   int levela=level(root, a, h1);
   int levelb=level(root, b, h2);
//   cout<<h1 <<h2;
   if(levela!=levelb)return false;
   return !issibling(root, a,b);
   
}
};