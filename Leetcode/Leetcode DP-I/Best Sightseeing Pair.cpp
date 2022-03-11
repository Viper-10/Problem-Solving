class Solution {
    public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int chosen = values[0]-1; 
        int n = values.size(); 
        int maxScore = 0; 

        for(int i = 1;i < n; ++i){
            maxScore = max(chosen+values[i], maxScore); 
            chosen = max(chosen, values[i])-1; 
        }

        return maxScore;
    }
};