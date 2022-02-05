class Solution
{
public:
  int jump(vector<int> &nums)
  {

    int n = nums.size();
    int canJumpTill = nums[0];

    if (n == 1)
      return 0;

    int i = 0, count = 1;

    while (canJumpTill < n - 1)
    {
      if (i >= canJumpTill)
      {
        return -1;
      }

      int maxJump = 0;

      for (int j = i + 1; j <= canJumpTill; ++j)
      {
        maxJump = max(maxJump, nums[j] + j);
      }

      i = canJumpTill;
      canJumpTill = maxJump;
      count++;
    }

    return count;
  }
};