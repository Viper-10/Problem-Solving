class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    if (nums2.size() < nums1.size())
      return findMedianSortedArrays(nums2, nums1);

    int n1 = nums1.size();
    int n2 = nums2.size();
    int start = 0, end = n1;

    while (start <= end)
    {
      int m1 = (start + end) / 2;
      int m2 = (n1 + n2 + 1) / 2 - m1;
      int left1 = m1 == 0 ? INT_MIN : nums1[m1 - 1];
      int left2 = m2 == 0 ? INT_MIN : nums2[m2 - 1];

      int right1 = m1 == n1 ? INT_MAX : nums1[m1];
      int right2 = m2 == n2 ? INT_MAX : nums2[m2];

      if (left1 <= right2 && left2 <= right1)
      {
        if ((n1 + n2) % 2 == 0)
          return (max(left1, left2) + min(right1, right2)) / 2.0;
        else
          return max(left1, left2);
      }
      else if (left1 > right2)
      {
        end = m1 - 1;
      }
      else
        start = m1 + 1;
    }
    return 0.0;
  }
};