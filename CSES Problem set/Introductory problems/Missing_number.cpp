#include<iostream>
using namespace std; 
int main(){
    int n; 
    cin >> n; 

    int64_t sum = 0; 
    for(int i = 0;i < n-1; ++i){
        int a; 
        cin >> a; 
        sum += a; 
    }

    cout << ((int64_t)n * (n+1))/2 - sum << endl; 

    return 0; 
}