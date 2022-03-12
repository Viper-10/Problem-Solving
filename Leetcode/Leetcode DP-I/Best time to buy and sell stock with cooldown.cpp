class Solution {
public:
    int dp[50001][2][2];
    
    int solve(vector<int>& prices, int pos, bool own, bool cool)
    {
        if(pos == prices.size())
            return 0;
        
        int &ans = dp[pos][own][cool];
        if(dp[pos][own][cool] != -1)
            return ans;
        
        if(own)
        {
            int op1 = solve(prices, pos + 1, own, 0);
            int op2 = prices[pos] +  solve(prices, pos + 1, !own, 1);
            ans =  max(op1, op2);
        }
        else
        {
            int op1 = solve(prices, pos + 1, 0, 0);
            int op2 = (cool) ? 0 : - (prices[pos]) +  solve(prices, pos + 1, 1, 0);            
            ans =  max(op1, op2);
        }
        
        return ans;
        
    }
    int maxProfit(vector<int>& prices) {
     
        memset(dp, -1, sizeof(dp));   
        return solve(prices, 0, 0, 0);
    }
};