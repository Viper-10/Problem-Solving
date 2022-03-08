class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> dp(n, 0); 
        
        if(n == 1) return 0; 
        
        int j = 0; 
        dp[0] = 0; 
        
        for(int i = 0;i < n; ++i){
            int canGoTo = nums[i]+i; 
            
            if(canGoTo >= n-1) return dp[i]+1; 
            
            for(j = j+1;j <= canGoTo; ++j){
                dp[j] = dp[i]+1; 
            }
            
            j -= 1; 
        }
        return -1; 
    }
};