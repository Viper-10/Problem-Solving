class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0; 
        int maxSum = INT32_MIN; 
        
        for(int& i : nums){
            sum = max(sum+i, i); 
            maxSum = max(maxSum, sum);              
        }
        
        return maxSum; 
    }
};