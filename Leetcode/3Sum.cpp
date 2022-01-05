class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &arr)
  {
    int n = arr.size();

    vector<vector<int>> output;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; ++i)
    {
      while (i != 0 && i < n - 2 && arr[i] == arr[i - 1])
        i++;

      for (int j = i + 1, k = n - 1; j < k;)
      {
        bool forJ = false, forK = false;

        if (arr[i] + arr[j] + arr[k] == 0)
        {
          output.push_back({arr[i], arr[j], arr[k]});
          j++, k--;
          forJ = true;
          forK = true;
        }

        else if (arr[i] + arr[j] + arr[k] > 0)
        {
          k--;
          forK = true;
        }

        else
        {
          j++;
          forJ = true;
        }

        if (forJ)
        {
          while (j < k && arr[j] == arr[j - 1])
            j++;
        }

        if (forK)
        {
          while (j < k && arr[k] == arr[k + 1])
            k--;
        }
      }
    }

    return output;
  }
};