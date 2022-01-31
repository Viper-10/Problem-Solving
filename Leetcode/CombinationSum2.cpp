class Solution
{
  vector<vector<int>> ans;
  vector<int> smallAns;

  void solve(vector<int> &candidates, int target, int index = 0)
  {
    if (target == 0)
    {
      ans.push_back(smallAns);
      return;
    }

    if (target < 0 || index == candidates.size())
    {
      return;
    }

    for (int i = index; i < candidates.size(); ++i)
    {
      smallAns.push_back(candidates[i]);
      solve(candidates, target - candidates[i], i + 1);
      smallAns.pop_back();
      while (i + 1 != candidates.size() && candidates[i] == candidates[i + 1])
        i++;
    }
  }

public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
  {
    sort(candidates.begin(), candidates.end());
    solve(candidates, target);
    return ans;
  }
};