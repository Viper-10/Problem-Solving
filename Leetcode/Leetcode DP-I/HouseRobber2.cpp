class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        int ans; 
        
        if(n == 1){
            return nums[0];
        }
        else if(n == 2){
            return max(nums[0], nums[1]); 
        }
        int dp[100]; 
        
        // I'm taking nums[0]
        dp[0] = nums[0]; 
        dp[1] = max(nums[0], nums[1]); 
        
        for(int i = 2;i < n-1; ++i){
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]); 
        }
        
        dp[n-1] = max(dp[n-2], dp[n-3]); 
        ans = dp[n-1]; 
        
        // I'm taking nums[n-1]
        dp[n-1] = nums[n-1]; 
        dp[n-2] = max(nums[n-1], nums[n-2]); 
        
        for(int i = n-3;i >= 1; --i){
            dp[i]  = max(nums[i]+dp[i+2], dp[i+1]); 
        }
        
        dp[0] = max(dp[1], dp[2]); 
        ans = max(ans, dp[0]);
        
        return ans; 
    }
};