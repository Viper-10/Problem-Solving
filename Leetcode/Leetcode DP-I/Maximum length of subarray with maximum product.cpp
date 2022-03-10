class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int countN = 0, firstN = -1, zero = -1;
        int maxL = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)      //  Counting -ve numbers
            {   
                countN++;
                if(firstN==-1) firstN = i;  // Storing index of first -ve Number
            }
            if(nums[i]==0)     // If number is 0 then reset the values
            {    
                countN = 0;
                firstN = -1;
                zero = i;
            }
            else
            {
                if(countN%2==0) maxL = max(maxL,i-zero);  // If -ve Count is EVEN then store the length till there
                else      maxL = max(maxL,i-firstN);  
            }
        }
        return maxL;
    }
};