vector<int> countBits(int n) {
        vector<int> output(n+1, 0); 
        
        int lastPowerOf2 = 1; 
        
        for(int i = 1;i <= n; ++i){
            if((i & i-1) == 0){
                output[i] = 1;
                lastPowerOf2 = i; 
            }else{
                output[i] = output[lastPowerOf2] + output[i-lastPowerOf2]; 
            }
        }
        
        return output; 
    }