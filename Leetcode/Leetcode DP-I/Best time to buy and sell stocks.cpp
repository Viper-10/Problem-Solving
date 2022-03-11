class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int potentialBuy = INT32_MAX; 
        int profit = 0; 
        
        for(const int& price : prices){
            if(potentialBuy > price) potentialBuy = price; 
            
            else profit = max(profit, price-potentialBuy);
        }
        
        return profit; 
    }
};