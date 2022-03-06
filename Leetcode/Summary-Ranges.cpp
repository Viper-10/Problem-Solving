class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) return {};
        int i = 1, j = 0, n = nums.size(); 
        vector<string> output; 
        
        while(i < n){
            if((int64_t)nums[i]-nums[i-1] != 1){
                string temp = to_string(nums[j]); 
                if(i-j > 1){
                    temp += "->"+ to_string(nums[i-1]);
                }
                j = i; 
                output.push_back(temp);
            }
            i++; 
        }
        
        string temp = to_string(nums[j]); 
        if(i-j > 1){
            temp += "->"+ to_string(nums[i-1]);
        }
        output.push_back(temp);

        
        return output; 
    }
};