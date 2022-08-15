#include<iostream>
#include<algorithm>
using namespace std; 
int main(){
    int n, x; 
    cin >> n >> x; 

    int* arr = new int[n]; 

    for(int i = 0;i < n; ++i) cin >> arr[i]; 

    sort(arr, arr+n); 

    int ans = 0; 
    for(int i = 0, j = n-1;i <= j; --j){
        if(arr[i]+arr[j] <= x) i++; 
        ans++; 
    }

    cout << ans << endl; 
    return 0; 
}