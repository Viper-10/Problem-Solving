#include<iostream>
using namespace std; 
int main(){
    int n; 
    cin >> n; 

    int64_t maxSum = INT32_MIN, currSum = 0; 
    for(int i = 0;i < n; ++i){
        int64_t a; 
        cin >> a; 
        currSum = max(currSum + a, a);
        maxSum = max(currSum, maxSum); 
    }

    cout << maxSum << endl; 
    return 0; 
}