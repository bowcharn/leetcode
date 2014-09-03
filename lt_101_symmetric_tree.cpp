/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric 
around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

confused what "{1,#,2,3}" means? > read more on how binary tree is 
serialized on OJ.
*/

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
