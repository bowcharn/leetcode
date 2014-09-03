/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree 
in which the depth of the two subtrees of every node never differ 
by more than 1.
*/

#include <cstdio> 
#include <cmath>

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
  bool isBalanced(TreeNode *root) {
    if(root == NULL)
      return true;
    else
      {
	int left_height = maxDepth(root->left);
	int right_height =maxDepth(root->right);
	if(std::abs(left_height - right_height) <= 1 &&
	   isBalanced(root->left)&&
	   isBalanced(root->right))
	  return true;
	else
	  return false;
      }
  }

  int maxDepth(TreeNode *root) {
    if(root == NULL)
      return 0;
    else
      {
	int left_depth = maxDepth(root->left);
	int right_depth = maxDepth(root->right);
	return left_depth >= right_depth? left_depth+1 : right_depth+1;
      }
  }
};
