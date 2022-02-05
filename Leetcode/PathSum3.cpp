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
private:
  unordered_map<int, int> m{{0, 1}};
  int currSum = 0;

public:
  int pathSum(TreeNode *root, const int &targetSum)
  {
    if (root == NULL)
      return 0;

    currSum += root->val;
    int ans = 0;

    if (m.find(currSum - targetSum) != m.end())
    {
      ans += m[currSum - targetSum];
    }

    m[currSum]++;

    ans += pathSum(root->left, targetSum);
    ans += pathSum(root->right, targetSum);

    if (m[currSum] > 1)
      m[currSum]--;

    else
      m.erase(currSum);

    currSum -= root->val;

    return ans;
  }
};