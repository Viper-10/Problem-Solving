class Solution {
    int n;  
    int store[100]; 

    int recursion(vector<int>& nums, int index){
        if(index >= n) return 0; 
        
        if(store[index] == -1){
            int ans1 = nums[index] + recursion(nums, index+2); 
            int ans2 = 0; 
            if(index+1 < n)  ans2 = nums[index+1] + recursion(nums, index+3); 
            
            store[index] = max(ans1, ans2);
        }
        
        return store[index]; 
    }
public:
    int rob(vector<int>& nums) {
        memset(store, -1, sizeof(store));
        n = nums.size(); 
        
        return recursion(nums, 0); 
    }
};