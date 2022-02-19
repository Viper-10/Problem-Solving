class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> s; 
        
        for(int i : nums){
            if(i % 2 == 1){
                s.insert(i*2); 
            }else s.insert(i); 
        }
        
        int deviation = INT32_MAX; 
        
        while(*s.rbegin() % 2 == 0){
            int top = *s.rbegin(); 
            
            deviation = min(deviation, top - *s.begin()); 
            s.erase(top);
            s.insert(top/2); 
        }
        
        return min(deviation, *s.rbegin()-*s.begin());
    }
};