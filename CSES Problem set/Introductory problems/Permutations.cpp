#include<iostream>
using namespace std; 
int main(){
    int n; 
    cin >> n; 

    if(n == 1) cout << 1; 

    else if(n == 2 || n == 3) cout << "NO SOLUTION" << endl; 

    else{
        for(int i = n-1; i >= 1; i -= 2){
            cout << i << " "; 
        }

        for(int i = n; i >= 1; i -= 2){
            cout << i << " "; 
        }
    }
    return 0; 
}