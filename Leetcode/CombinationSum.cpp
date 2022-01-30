class Solution {
    vector<vector<int>> ans;
    vector<int> smallAns;
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target, int level = 0) {
        if(target < 0){
            return ans;         
        }
        
        if(target == 0){
            ans.push_back(smallAns); 
            return ans; 
        }
        
        for(int i = level;i < candidates.size(); ++i){
            smallAns.push_back(candidates[i]);
            combinationSum(candidates, target-candidates[i], i);
            smallAns.pop_back();
        }
        
        return ans; 
    }
};