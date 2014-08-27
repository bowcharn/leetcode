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
