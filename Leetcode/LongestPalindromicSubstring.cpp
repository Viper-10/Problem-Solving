class Solution {
public:
    string longestPalindrome(string& s) {
        int n = s.size(); 
        int ans = 1;
        int start = 0; 
        
        for(int i = 0;i < n-1; ++i){
            // odd string
            //s[i] is the middle 
            
            int low = i-1, high = i+1; 
            
            while(low >= 0 && high < n && s[low] == s[high]) low--, high++; 
            
            int len = (high - low + 1) - 2; 
            
            if(len > ans){
                start = low+1; 
                ans = len; 
            }
            
            // even string
            low = i; high = i+1; 
                
            while(low >= 0 && high < n && s[low] == s[high]) low--, high++; 
            
            len = (high-low+1) - 2; 
            
            if(len > ans){
                start = low+1; 
                ans = len; 
            }
        }
        
        return s.substr(start, ans); 
    }
};