#include<iostream>
#include<algorithm>
using namespace std; 
int main(){
    int n; 
    cin >> n; 

    int* arr = new int[n]; 

    for(int i = 0;i < n; ++i){
        cin >> arr[i]; 
    }

    sort(arr, arr+n); 

    int chosenLength; 

    chosenLength = arr[n/2]; 
    int64_t ans = 0; 
    for(int i = 0;i < n; ++i){
        ans += abs(chosenLength - arr[i]);
    }

    cout << ans << endl; 

    return 0; 
}