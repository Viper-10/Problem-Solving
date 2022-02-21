class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0; 
        
        for(int i = 0;i < 32; ++i){
            int mask = 1 << i; 
            if((x & mask) ^ (y & mask)) res++; 
        }
        
        return res; 
    }
};