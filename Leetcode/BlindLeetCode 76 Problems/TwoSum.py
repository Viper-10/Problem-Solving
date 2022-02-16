class Solution:
  def twoSum(self, nums: List[int], target: int) -> List[int]:

  visited = {}
  for i in range(0, len(nums)) : 
    if (target - nums[i]) in visited : 
      return [visited[target-nums[i]], i]

    visited[nums[i]] = i;