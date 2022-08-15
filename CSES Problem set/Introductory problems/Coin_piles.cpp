#include<iostream>
using namespace std; 
int main(){
    int t; 
    cin >> t; 

    while(t--){
        int a, b; 
        cin >> a >> b; 

        if(max(a, b) > 2*min(a, b)) {
            cout << "NO" << endl; 
            continue; 
        }

        if((2*b - a) % 3 == 0 && (2*a - b) % 3 == 0){
            cout << "YES" << endl; 
        }else cout << "NO" << endl;
        
    }
    return 0; 
}