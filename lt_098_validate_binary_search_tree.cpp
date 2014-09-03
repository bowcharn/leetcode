/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the 
node's key. The right subtree of a node contains only nodes with keys 
greater than the node's key. Both the left and right subtrees must also 
be binary search trees. confused what "{1,#,2,3}" means? > read more on 
how binary tree is serialized on OJ.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    bool isValidBST(TreeNode *root) {
      return aux_valid(root, INT_MIN, INT_MAX);     
    }
  
  bool aux_valid(TreeNode* root, int min, int max)
  {
    if(root == NULL)
      return true;
    if(!(min <= root->val && root->val <= max))
      return false;
    if(!aux_valid(root->right, root->val + 1, max))
      return false;
    if(!aux_valid(root->left, min, root->val - 1))
      return false;

    return true;
  }
};
