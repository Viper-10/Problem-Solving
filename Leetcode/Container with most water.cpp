class Solution
{
public:
  int maxArea(vector<int> &arr)
  {
    int i = 0, j = arr.size() - 1;
    int ans = INT32_MIN;

    while (i < j)
    {
      int currArea = (j - i) * min(arr[i], arr[j]);
      ans = max(currArea, ans);

      if (arr[i] < arr[j])
        i++;
      else
        j--;
    }

    return ans;
  }
};