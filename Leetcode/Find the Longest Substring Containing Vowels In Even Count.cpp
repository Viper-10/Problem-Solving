class Solution {
    void setOrUnset(int& k, const int& i){
        k ^= (1 << i); 
    }
    
public:
    int findTheLongestSubstring(const string& s) {
        unordered_map<int, int> m = {{0, -1}}; 
        int k = 0, maxLength = 0; 
        
        for(int i = 0;i < s.size(); ++i){
            switch(s[i]){
                case 'a' : {
                    setOrUnset(k, 0); 
                    break; 
                }
                case 'e' : {
                    setOrUnset(k, 1); 
                    break; 
                }
                case 'i' : {
                    setOrUnset(k, 2); 
                    break; 
                }
                case 'o' : {
                    setOrUnset(k, 3); 
                  break; 
                }
                case 'u' : {
                    setOrUnset(k, 4); 
                    break; 
                }       
            }    
            
            if(m.find(k) != m.end()){
                maxLength = max(i-m[k], maxLength);
            }else{
                m[k] = i; 
            }           
        }
        
        return maxLength; 
    }
};