class Solution {
public:
    int tribonacci(int n) {
        int dp[3] = {0, 1, 1}; 
        
        if(n < 3) return dp[n]; 
        
        int i = 0, sum = 2; 
        
        while(n-- > 3){
            int saveI = dp[i]; 
            dp[i] = sum; 
            sum += (dp[i] - saveI); 
            i = (i+1) % 3; 
        }
        return sum; 
    }
};