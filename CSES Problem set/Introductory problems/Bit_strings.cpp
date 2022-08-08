#include<iostream>
using namespace std; 
int main(){
    int n;
    const int mod = 1e9+7; 
    cin >> n; 
    
    int ans = 1; 

    for(int i = 1;i <= n; ++i){
        ans = ((int64_t)ans << 1) % mod; 
    }

    cout << ans << endl;

    return 0; 
}