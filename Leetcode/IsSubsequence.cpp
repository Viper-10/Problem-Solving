class Solution {
public:
    bool isSubsequence(string& s, string& t, int i = 0, int j = 0) {
        if(j == s.size()) return true; 
        
        if(i == t.size()) return false; 
        
        if(t[i] == s[j]) return isSubsequence(s, t, i+1, j+1); 
        
        return isSubsequence(s, t, i+1, j); 
    }
};