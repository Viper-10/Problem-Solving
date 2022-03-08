class Solution {
    int solve(vector<int>& nums, int l, int r){
        int dp[2]; 
        
        dp[0] = nums[l]; 
        dp[1] = max(nums[l], nums[l+1]); 
        
        for(int i = l+2, j = 0; i <= r; ++i, ++j){
            dp[j%2] = max(dp[j%2]+nums[i], dp[!(j%2)]); 
        }

        return dp[(r-l)%2]; 
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if(n == 1) return nums[0]; 
        
        if(n == 2) return max(nums[0], nums[1]); 
        
        return max(solve(nums, 0, n-2), solve(nums, 1, n-1)); 
    }
};