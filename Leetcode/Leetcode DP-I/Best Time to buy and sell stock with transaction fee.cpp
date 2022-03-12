class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        if ( 2 > prices.size() ) return 0;
        
        int gain = 0;
        int hold = INT_MIN;
        
        for ( int price : prices )
        {
            hold = max( hold, gain-price );
            gain = max( gain, hold+price-fee );
        }
        
        return gain;
    }
};