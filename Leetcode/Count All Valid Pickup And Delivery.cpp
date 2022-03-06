class Solution {
    int mod = 1e9 + 7; 
public:
    int countOrders(int n) {
        
        // We've to pick up to deliver an order. 
        // For any n, we take one order at a time. 
        // So if we take P1 at say n = 3, as first pickup, we've 5 options 
        // D1, P2, P3, D2, D3. 
        
        // We observe that number of services is 2*n for any order. Given that we already took
        // P1 we've 2n - 1 services left. The D1 can go to any one of the 2n-1 places. 
        // Now the 2n-1 places is occupied by n = 2 and D1. So as D1 goes to all of the 2n-1 
        // positions there are f(n-1) ways the other 2n-2 places are occupied. 
        
        // Now we did this only for P1. There are n ways of choosing first order. P1 or P2 or P3
        // first for n = 3. Hence the formula will be n * [(2n-1) * f(n-1)]
        
        // n is the number of ways to choose the first order, 2n-1 is the number of ways the
        // corresponding delivery done and f(n-1) is the number of ways other n-1 orders are arranged
        
        int ans = 1; 
        
        for(int i = 2;i <= n; ++i){
            ans = (i * (((2* i -1) * (int64_t)ans) % mod)) % mod; 
        }
        
        return ans; 
    }
};