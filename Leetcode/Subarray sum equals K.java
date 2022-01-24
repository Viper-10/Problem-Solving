class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> m = new HashMap<>(); 
        int ans = 0;
        int sum = 0; 
        
        m.put(0, 1);
        
        for(int i = 0;i < nums.length; ++i){
            sum += nums[i]; 
            
            if(m.containsKey(sum-k)){
                ans += m.get(sum-k);
            }
            
            int x = 1; 
            if(m.containsKey(sum)){
                x += m.get(sum);
            }
            
            m.put(sum, x); 
            
        }
        
        return ans; 
    }
}