#include<iostream>
using namespace std; 
int main(){
    int t; 
    cin >> t; 

    while(t--){
        int n; 
        cin >> n; 

        bool ok = true; 
        bool increasing = true; 
        int prev = -1; 
        for(int i = 0;i < n; ++i){
            int a; 
            cin >> a; 

            if(a > prev && !increasing){
                ok = false; 
            }
            if(prev > a){
                increasing = false; 
            } 
            prev = a; 
        }

        cout << (ok ? "Yes" : "No") << endl; 
    }
    return 0; 
}