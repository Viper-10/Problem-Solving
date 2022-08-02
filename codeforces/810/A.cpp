#include<iostream>
using namespace std; 
int main(){
    int t; 
    cin >> t; 

    while(t--){
        int n; 
        cin >> n; 

        if(n == 1) {
            cout << 1 << endl; 
        }

        else if((n&1) == 0){
            for(int i = 1;i <= n; i += 2){
                cout << i+1 << " " << i << " "; 
            }
            cout << endl; 
        }
        else{
            cout << n << " " << 1 << " "; 

            for(int i = 3; i < n; i += 2){
                cout << i+1 << " " << i << " "; 
            }

            cout << 2 << endl; 
        }
    }

    return 0; 
}