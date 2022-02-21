class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0; 
        
        for(int i = 0;i < 32; ++i){
            int mask = 1 << (31-i);
            
            if((mask & n) > 0){
                res |= 1 << i; 
            }
        }
        
        return res; 
    }
};