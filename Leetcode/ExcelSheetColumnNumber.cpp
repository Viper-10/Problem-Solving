class Solution {
public:
    int titleToNumber(string& columnTitle, int start = 0) {
        if(start == columnTitle.size()) return 0; 
        
        return pow(26, columnTitle.size()-start-1) * (columnTitle[start]-'A'+1) + titleToNumber(columnTitle, start+1);
    }
};