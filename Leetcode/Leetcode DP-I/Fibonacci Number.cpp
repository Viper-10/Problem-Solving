class Solution {
public:
    int fib(int n) {        
        if(n < 2) return n; 
        
        int t1 = 0, t2 = 1, t3; 
        
        while(n-- >= 2){
            t3 = t1+t2; 
            t1 = t2; 
            t2 = t3; 
        }
        
        return t3; 
    }
};