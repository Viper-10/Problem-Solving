class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        int* store = new int[n];  

        if(n == 1){
            return nums[0]; 
        }
        
        store[0] = nums[0]; 
        store[1] = max(nums[0], nums[1]); 
        
        for(int i = 2;i < n; ++i){
            store[i] = max(store[i-1], store[i-2] + nums[i]); 
        }
        
        return store[n-1]; 
    }
};