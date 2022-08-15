#include<iostream>
using namespace std; 
int main(){
    int n; 
    cin >> n; 

    int ans = 0; 

    for(int i = 5;i <= 1e9; i *= 5){
        if(i > n) break; 
        ans += n/i; 
    }
    cout << ans << endl; 
    return 0; 
}