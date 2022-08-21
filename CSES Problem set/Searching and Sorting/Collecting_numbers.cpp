#include<iostream>
using namespace std; 
int main(){
    int n; 
    cin >> n; 

    int* indices = new int[n]; 
    for(int i = 0;i < n; ++i){
        int a; 
        cin >> a;
        a--;  
        indices[a] = i; 
    }

    int rounds = 0; 
    for(int i = 0;i < n; ++i){
        if(i == n-1 || indices[i] > indices[i+1]) rounds++; 
    }

    cout << rounds << endl; 


    return 0; 
}