/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf 
path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
    int sumNumbers(TreeNode *root) {
      if(root == NULL)
	return 0;
      int each_sum = 0;
      int total_sum = 0;
      sumNum_rec(root, each_sum, total_sum);
      return total_sum;
    }

  void sumNum_rec(TreeNode * root, int each_sum, int &total_sum)
  {
    if(root == NULL)
      return;
    
    each_sum = 10*each_sum + root->val;
    if(root->left == NULL && root->right == NULL)
	total_sum += each_sum;
    else
      {
	sumNum_rec(root->left, each_sum, total_sum);
	sumNum_rec(root->right, each_sum, total_sum);
      }
  }
};
