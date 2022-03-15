class Solution {
public:
    string minRemoveToMakeValid(string& s) {
        int n = s.length(); 
        string output = ""; 
        int totalOpeningBrackets = 0, openingBracketWithoutPair = 0; 
        queue<int> ignoreIndex; 
        
        for(int i = 0;i < n; ++i){
            if(s[i] == '('){
                openingBracketWithoutPair++;
                totalOpeningBrackets++;
            }
            
            else if(s[i] == ')'){
                if(openingBracketWithoutPair == 0){
                    ignoreIndex.push(i);
                }
                else{
                    openingBracketWithoutPair -= 1; 
                }                
            }            
        }
        
        int j = 0; 
        for(int i = 0;i < n; ++i){
            if(!ignoreIndex.empty() && ignoreIndex.front() == i){
                ignoreIndex.pop();
                continue;
            }
            
            if(s[i] == '(' && totalOpeningBrackets != openingBracketWithoutPair){
                output += s[i]; 
                totalOpeningBrackets--; 
            }
            
            else if(s[i] != '('){
                output += s[i];
            }
        }
        
        return output;
                
    }
};