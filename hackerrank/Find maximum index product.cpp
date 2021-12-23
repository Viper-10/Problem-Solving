#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int64_t solve(vector<int>& arr) {
    stack<int> l;
    stack<int> r; 
    int n = arr.size(); 
    
    vector<int64_t> ans(n, 1); 
     
    
    int64_t maxAns = 0; 
    l.push(0); 
    r.push(n-1);
    
    ans[0] = 0; 
    ans[n-1] = 0; 
    
    for(int i = 1, j = n-2;i < n; ++i, --j){
        int left = -1, right = -1;
        
        while(!l.empty() && arr[i] >= arr[l.top()]) l.pop(); 
        
        if(!l.empty()){
            left = l.top(); 
        }
        l.push(i); 
        
        while(!r.empty() && arr[j] >= arr[r.top()]) r.pop(); 
        
        if(!r.empty()){
            right = r.top(); 
        }   
        
        r.push(j); 
        
        ans[i] *= (int64_t)(left+1); 
        ans[j] *= (int64_t)(right+1); 
    }   
    
    for(int64_t& i : ans) maxAns = max(maxAns, i); 
    
    return maxAns; 
}
int main()
{
    
    int n; 
    cin >> n; 
    vector<int> arr(n); 
    
    for(int i = 0;i < n; ++i) cin >> arr[i]; 
    
    cout << solve(arr) << endl; 
    return 0; 
}
