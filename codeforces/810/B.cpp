#include<iostream>
#include<vector>
using namespace std; 
int main(){
    int t; 
    cin >> t; 

    while(t--){
        int n, m; 
        cin >> n >> m; 

        vector<int> unhappinessValue(n, 0); 
        for(int i = 0;i < n; ++i) cin >> unhappinessValue[i]; 

        vector<pair<int, int>> edges; 
        vector<int> degree(n, 0); 

        for(int i = 0;i < m; ++i){
            int a, b; 
            cin >> a >> b; 
            a--; 
            b--; 
            degree[a]++; 
            degree[b]++; 
            edges.push_back({a, b});
        }

        if((m&1) == 0){
            cout << 0 << endl; 
            continue; 
        }

        int ans = INT32_MAX; 
        for(int i = 0;i < n; ++i){
            if(degree[i] & 1){
                ans = min(ans, unhappinessValue[i]);
            }
        }

        for(const pair<int, int>& p: edges){
            if((degree[p.first] & 1) == 0 && (degree[p.second] & 1) == 0){
                ans = min(ans, unhappinessValue[p.first]+unhappinessValue[p.second]);
            }
        }

        cout << ans << endl; 
    }
}