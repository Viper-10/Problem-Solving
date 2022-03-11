class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int potentialBuy = INT32_MAX; 
        int profit = 0; 
        
        for(const int& price : prices){
            if(price > potentialBuy){
                profit += price-potentialBuy; 
                potentialBuy = price; 
            }else potentialBuy = price; 
        }
        
        return profit; 
    }
};