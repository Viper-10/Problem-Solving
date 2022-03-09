class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = INT32_MIN, a = 0, b = 0,  minSum = INT32_MAX, sum = 0; 
        
        for(int x : nums){
            // whole array sum
            sum += x; 
            
            // maxsum subarray
            a = max(x, a+x); 
            maxSum = max(a, maxSum); 
            
            // minsum subarray
            b = min(x, b+x); 
            minSum = min(b, minSum);
        }
        
        return minSum == sum ? maxSum : max(maxSum, sum-minSum); 
    }
};