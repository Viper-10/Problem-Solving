class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        lastOccurence = {}
        
        i = 0
        maxLength = 0
        start = 0
        
        for c in s : 
            if c in lastOccurence and lastOccurence[c] >= start : 
                maxLength = max(maxLength, i-start)
                start = lastOccurence[c]+1; 

            lastOccurence[c] = i;
            i += 1
            
        maxLength = max(maxLength, i-start)
        return maxLength