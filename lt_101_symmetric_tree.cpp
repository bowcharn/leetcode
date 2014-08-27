
#include <cstdio>
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



class Solution {
public:
    bool isSymmetric(TreeNode *root) {
      if(root == NULL)
	return true;
      else
	return isSym(root->left, root->right);
    }

  bool isSym(TreeNode* left, TreeNode* right){
    if(left == NULL && right == NULL)
      return true;
    else if(left != NULL && right != NULL)
      {
	return (left->val == right->val &&
		isSym(left->right, right->left)&&
		isSym(left->left, right->right));
      }
    else
      return false;
  }
};
