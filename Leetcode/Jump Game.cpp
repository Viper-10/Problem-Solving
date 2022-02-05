class Solution
{
public:
  bool canJump(vector<int> &nums)
  {
    int ICanReach = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
      if (i > ICanReach)
      {
        return false;
      }

      ICanReach = max(ICanReach, i + nums[i]);

      if (ICanReach >= nums.size() - 1)
      {
        return true;
      }
    }

    return true;
  }
};