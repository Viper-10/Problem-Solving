#include<bits/stdc++.h>
#define maxN 1000001
using namespace std; 
int main(){
    int t; 
    cin >> t; 
    
    vector<int> dp(maxN, INT32_MAX); 
    dp[0] = 0; 
    dp[1] = 1; 
    
    // a tricky sieve question
    
    // for each number we multiply it till that number, ie 
    // 10 gets multiplied from 1 * 10, 2*10, ... 10*10 and every 
    // index is modified if it's minimum. 
    // Beyond 10*10, 11 becomes the bigger number so max(10, 11) is 
    // 11 so it is taken care during 11s turn. 
    
    // when we reach maxN/2, we reach the limit, beyond that 
    // we go out of bounds, since maxN/2 * 2 = maxN. 
    
    // But we've to check for each number if going to previous number
    // is rewarding, so we do that alone. 
    
    for(int i = 2; i < maxN/2; ++i){
        dp[i] = min(dp[i], dp[i-1] + 1); 
        for(int64_t j = 2; j <= i && i*j < maxN; ++j){
            dp[i*j] = min(dp[i*j], dp[i] + 1); 
        }   
    }  
    
    for(int i = maxN/2; i < maxN; ++i) dp[i] = min(dp[i], dp[i-1]+1); 
    
    while(t--){
        int x; 
        cin >> x; 
        cout << dp[x] << endl; 
        // cout << downToZero(x) << endl; 
    }
    
    return 0; 
}
