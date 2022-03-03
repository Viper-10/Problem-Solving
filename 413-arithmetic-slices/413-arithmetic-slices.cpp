class Solution {
    inline int sumOfNNumbers(int x){return ((x+1) * x)/2;}
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
                
        int n = arr.size(); 
        int ans = 0; 
        
        if(n < 3) return 0; 
        
        int i = 0, j = 1; 
        
        while(j < n){
            int d = arr[j]-arr[i]; 
            
            while(j+1 < n && arr[j+1] - arr[j] == d) j++; 
            
            int intervalSize = j-i+1; 
            
            ans += sumOfNNumbers(intervalSize - 3 + 1);  
    
            i = j; 
            j++; 
        }
        
        return ans; 
    }
};