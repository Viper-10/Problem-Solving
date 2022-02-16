class Solution:
    def longestPalindrome(self, s: str) -> str:
        
        n = len(s)
        maxLength = 1
        start = 0
        
        for i in range(n-1) : 
            if i+1 < n and s[i] == s[i+1] : 
                j,k = i-1, i+2
                
                while j >= 0 and k < n and s[j] == s[k]: 
                    j -= 1;
                    k += 1; 
                
                j += 1
                k -= 1 
                
                if maxLength < k-j+1 : 
                    maxLength = k-j+1; 
                    start = j; 
            
            j,k = i-1,i+1
            
            while j >= 0 and k < n and s[j] == s[k]: 
                j -= 1
                k += 1
            
            j += 1
            k -= 1
            
            if maxLength < k-j+1 : 
                maxLength = k-j+1
                start = j
                
        return s[start:start+maxLength]