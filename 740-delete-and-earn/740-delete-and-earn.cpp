class Solution {    
    int recursion(vector<int>& arr, int index, int* store){
        if(index == arr.size()) return 0; 
        
        if(store[index] == -1){
            int ans = 0; 
            int i = index;        
            int sumOfAi = 0; 

            while(i < arr.size() && arr[i] == arr[index]){
                i++; 
            }

            sumOfAi = (i-index) * arr[index];
            int j = i; 

            while(j < arr.size() && arr[j] == arr[index]+1){
                j++; 
            }

            ans = recursion(arr, j, store) + sumOfAi; 

            if(i != j){
                int sumOfAiPlusOne = (j-i) * arr[i]; 
                while(j < arr.size() && arr[j] == arr[i]+1) j++; 

                ans = max(ans, recursion(arr, j, store)+sumOfAiPlusOne);
            }       
            
            store[index] = ans; 
        }
        
        return store[index]; 
        
    }
    int recursionHelper(vector<int>& arr){
        int* store; 
        store = new int[arr.size()]; 
        
        for(int i = 0;i < arr.size(); ++i){
            store[i] = -1; 
        }
        
        return recursion(arr, 0, store); 
    }
public:
    int deleteAndEarn(vector<int>& arr) {
        sort(arr.begin(), arr.end()); 
        
        return recursionHelper(arr); 
           
        
    }
};