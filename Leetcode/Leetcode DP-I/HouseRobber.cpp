class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int* store = new int[n]; 
        
        store[0] = nums[0]; 
        
        if(n == 1){
            return store[0]; 
        }
        
        store[1] = max(nums[0], nums[1]); 
        
        for(int i = 2;i < n; ++i){
            store[i] = max(nums[i] + store[i-2], store[i-1]); 
        }
        
        return store[n-1]; 
    }
};