class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s; 
        int i = 0, j = 0, n = pushed.size(); 
        
        while(i < n){
            // if top element of stack == popped, pop the top element. Increase j+1;
            s.push(pushed[i]);
            
            while(!s.empty() && s.top() == popped[j]){
                s.pop(); 
                j++;
            }       
    
            i++; 
        }
        return s.empty();
    }
};