#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std; 
void calculateQueriedTimes(vector<int64_t>& arr){
    for(int i = 1;i <= arr.size(); ++i){
        arr[i] += arr[i-1]; 
    } 

    sort(arr.begin(), arr.end(), greater<int>()); 
}
int64_t calculateQueryTotalSum(auto& arr, auto& pq){
    int64_t sum = 0;  
    for(int i = 0;i < arr.size(); ++i){
        sum += arr[i] * pq.top(); 
        pq.pop(); 
    }

    return sum;
}
int main(){

    int n, q; 
    cin >> n >> q; 

    priority_queue<int64_t> pq; 
    vector<int64_t> queriedTimes(n+1, 0);

    for(int i = 0;i < n; ++i){
        int x; 
        cin >> x; 
        pq.push(x); 
    }

    int l, r; 

    while(q--){
        cin >> l >> r; 
        l--, r--; 
        queriedTimes[l]++;
        queriedTimes[r+1]--;
    }

    calculateQueriedTimes(queriedTimes);

    cout << calculateQueryTotalSum(queriedTimes, pq) << endl; 

    return 0; 
}