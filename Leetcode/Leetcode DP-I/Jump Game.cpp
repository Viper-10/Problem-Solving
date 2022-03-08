class Solution {
public:
    bool canJump(vector<int>& nums) {
        int canGoTo = nums[0]; 
        
        for(int i = 0;canGoTo < nums.size()-1; ++i){
            if(canGoTo < i){
                return false; 
            }
            
            canGoTo = max(nums[i]+i, canGoTo);        
        }
        
        return true; 
    }
};