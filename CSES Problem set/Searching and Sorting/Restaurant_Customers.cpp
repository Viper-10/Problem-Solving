#include<iostream>
#include<map>
using namespace std; 
int main(){
    int n; 
    cin >> n; 

    map<int, int> m; 
    while(n--){
        int l, r; 
        cin >> l >> r; 

        m[l]++; 
        m[r]--; 
    }

    int ans = 1; 
    int sum = 0; 

    for(const pair<int, int>& p: m){
        sum += p.second; 
        ans = max(ans, sum); 
    }

    cout << ans << endl; 
    return 0; 
}