class Solution {
public:
    string getSmallestString(int n, int k) {
        
        string output = ""; 

        while(n > 0 && k <= 26*(n-1)){
            output += 'a';
            k--;
            n--;
        }

        if(n > 0){
            output += k-26*(n-1)+'a'-1;
            n--;
        }

        while(n > 0){
            output += 'z';
            n--;
        }

        return output;
    }
};