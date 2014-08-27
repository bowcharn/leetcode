/*
Given a binary tree, return the level order traversal of its nodes' values. 
(ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/


#include <vector>
#include <utility>
#include <queue>

using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
      queue<pair<TreeNode*,int> > tqueue;
      vector<vector<int> > ret;
      if(root == NULL)
	return ret;

      tqueue.push(pair<TreeNode*, int>(root,0));
      int level = -1;
      while(!tqueue.empty())
	{
	  std::pair<TreeNode*, int> curNode(tqueue.front());
	  tqueue.pop();
	  if(curNode.second > level)
	    {
	      level = curNode.second;
	      ret.push_back(vector<int>{curNode.first->val});	      
	    }
	  else
	    ret[level].push_back(curNode.first->val);
	  
	  if(curNode.first->left != NULL)
	    tqueue.push(pair<TreeNode*, int>(curNode.first->left, 
					     curNode.second+1));
	  if(curNode.first->right != NULL)
	    tqueue.push(pair<TreeNode*, int>(curNode.first->right, 
					     curNode.second+1));
	}
      return ret;
    }
};
