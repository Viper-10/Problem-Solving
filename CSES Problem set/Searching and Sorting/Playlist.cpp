#include<iostream>
#include<unordered_map>
using namespace std; 
int main(){
    int n; 
    cin >> n; 

    int* arr = new int[n]; 
    for(int i = 0;i < n; ++i) cin >> arr[i]; 

    unordered_map<int, int> indexOf; 
    
    int ans = 0, j = 0; 

    for(int i = 0;i < n; ++i){
        j = max(indexOf[arr[i]], j); 
        ans = max(ans, i-j+1); 
        indexOf[arr[i]] = i+1; 
    }

    cout << ans << endl; 
    return 0; 
}