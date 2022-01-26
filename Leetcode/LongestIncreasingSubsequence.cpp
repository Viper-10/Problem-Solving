class Solution {

private : 
    int recursion(vector<int>& nums, int prev = INT32_MIN, int i = 0){
        if(i == nums.size()) return 0; 
        
        int ans = 0; 
        
        if(nums[i] > prev){
            ans = recursion(nums, nums[i], i+1) + 1; 
        }
        
        ans = max(ans, recursion(nums, prev, i+1));
        
        
        return ans; 
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        // return recursion(nums); 
        int n = nums.size(); 
        vector<int> dp(n, 1); 
        int ans = 1; 
        
        for(int i = 1; i < n; ++i){
            for(int j = 0;j < i; ++j){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1); 
                }
            }
            ans = max(ans, dp[i]); 
        }
    
        return ans; 
    }
    
};