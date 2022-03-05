class Solution {
public:
    int tribonacci(int n) {
        if(n < 2) return n; 
        
        if(n == 2) return 1; 
        
        int t1 = 0, t2 = 1, t3 = 1, t4; 
        
        while(n-- > 2){
            t4 = t1 + t2 + t3; 
            t1 = t2; 
            t2 = t3; 
            t3 = t4; 
        }
        
        return t4; 
    }
};