#include<iostream>
using namespace std; 
int main(){

    int n; 
    cin >> n; 

    cout << 0 << endl; 

    if(n >= 2){
        cout << 6 << endl; 
    }

    for(int64_t i = 3;i <= n; ++i){
        cout << ((i*i)*(i*i-1)/2) - 4*(i-1)*(i-2) << endl; 
    }
    
    return 0; 
}