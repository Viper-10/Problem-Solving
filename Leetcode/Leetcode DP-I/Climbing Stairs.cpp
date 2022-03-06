class Solution {
public : 
    int climbStairs(int n) {
        int dp[2] = {1, 1}; 
        
        if(n < 2) return dp[n];
        
        int j = 0; 
        int sum = 2; 
        
        for(int i = 3; i <= n; ++i){
            int prevI = dp[j]; 
            dp[j] = sum; 
            sum = sum - prevI + sum; 
            j = (j+1)%2;
        }        
        
        return sum; 
    }
};