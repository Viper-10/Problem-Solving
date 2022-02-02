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
class Solution
{
  TreeNode *prev = new TreeNode(INT32_MIN);
  TreeNode *node1 = NULL;
  TreeNode *node2;

  void inorder(TreeNode *root)
  {
    if (root == NULL)
    {
      return;
    }

    inorder(root->left);

    if (root->val < prev->val)
    {
      if (node1 == NULL)
      {
        node1 = prev;
        node2 = root;
      }
      else
        node2 = root;
    }

    prev = root;

    inorder(root->right);
  }

public:
  void recoverTree(TreeNode *root)
  {
    inorder(root);

    swap(node1->val, node2->val);
  }
};