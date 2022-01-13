class Solution
{
public:
  int threeSumClosest(vector<int> &nums, int target)
  {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans;
    int diff = INT32_MAX;

    for (int i = 0; i < n - 2; ++i)
    {
      int saveTarget = target;
      target -= nums[i];
      for (int j = i + 1, k = n - 1; j < k;)
      {
        int currDeviation = target - nums[j] - nums[k];

        if (currDeviation == 0)
        {
          return saveTarget;
        }

        else if (abs(currDeviation) < diff)
        {
          diff = abs(currDeviation);
          ans = nums[i] + nums[j] + nums[k];
        }

        if (nums[j] + nums[k] > target)
        {
          k--;
        }

        else
        {
          j++;
        }
      }
      target = saveTarget;
    }
    return ans;
  }
};