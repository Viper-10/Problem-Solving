class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    int n = nums.size();
    int start = 0, end = n - 1;

    while (start <= end)
    {
      int mid = start + (end - start) / 2;

      if (nums[mid] == target)
      {
        return mid;
      }

      // first part
      if (nums[mid] >= nums[start])
      {
        if (target > nums[mid])
        {
          start = mid + 1;
        }
        else
        {
          if (target < nums[start])
          {
            start = mid + 1;
          }
          else
          {
            end = mid - 1;
          }
        }
      }

      // second part
      else
      {
        if (target < nums[mid])
        {
          end = mid - 1;
        }
        else
        {
          if (target < nums[start])
          {
            start = mid + 1;
          }
          else
          {
            end = mid - 1;
          }
        }
      }
    }

    return -1;
  }
};