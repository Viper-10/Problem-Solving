#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<unordered_set>
using namespace std; 
bool solve(int n, int m, vector<int>& colors){
    bool moreThanTwo = false; 
    int k = colors.size();
    int64_t count = 0; 

    for(int i = 0;i < k; ++i){
        if(colors[i]/n >= 2){
            count += colors[i]/n; 

            if(colors[i]/n > 2){
                moreThanTwo = true; 
            }
        }
    }

    if(count < m) return false; 

    if((m&1) == 1) return moreThanTwo; 

    return true; 
}
int main(){
    int t; 
    cin >> t; 

    while(t--){
        int m, n, k; 
        cin >> m >> n >> k; 

        vector<int> colors(k, 0); 
        for(int i = 0;i < k; ++i){
            cin >> colors[i]; 
        }

        if(n == 1 || m == 1){
            cout << "No" << endl; 
            continue; 
        }

        if(solve(n, m, colors) || solve(m, n, colors)){
            cout << "Yes" << endl; 
        }else{
            cout << "No" << endl;
        }
    }

    return 0; 
}