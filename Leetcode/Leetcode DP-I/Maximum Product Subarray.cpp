class Solution {
public:
    int maxProduct(vector<int>& arr){ 
        int maxProduct = 1, minProduct = 1, ans = INT32_MIN; 
        
        for(int& x : arr){
            if(x == 0){
                maxProduct = 1; 
                minProduct = 1;
                ans = max(0, ans);
                continue; 
            }    
            
            int temp = maxProduct; 
            
            maxProduct = max({maxProduct*x, minProduct*x, x});
            minProduct = min({temp*x, minProduct*x, x});     
            
            ans = max(maxProduct, ans); 
        }
        return ans;
    }
};