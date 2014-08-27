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
