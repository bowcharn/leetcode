#include <cstdio>
//Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {      
      if(p == NULL && q == NULL)
	return true;
      else if((p == NULL && q != NULL) || (p != NULL && q == NULL))
	return false;
      else
	{
	  if(p->val != q->val)
	    return false;
	  else
	    {
	      bool isLeft = isSameTree(p->left, q->left);
	      bool isRight = isSameTree(p->right, q->right);
	      
	      return isLeft && isRight;
	    }
	}
    }
};
