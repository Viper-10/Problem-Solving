#include<iostream>
using namespace std; 
int main(){
    int n; 
    cin >> n; 

    int64_t ans = 0; 
    int prevBig = 0; 
    cin >> prevBig; 

    for(int i = 0;i < n-1; ++i){
        int a; 
        cin >> a; 

        if(a >= prevBig) prevBig = a; 
        else ans += prevBig-a; 
    }

    cout << ans << endl; 

    return 0; 
}