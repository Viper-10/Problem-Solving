#include<iostream>
#include<unordered_map>
using namespace std; 
int main(){
    int n, sum; 
    cin >> n >> sum;  

    unordered_map<int, int> m;

    for(int i = 0;i < n; ++i){
        int a; 
        cin >> a; 
        if(m.find(sum-a) != m.end()){
            cout << m[sum-a] << " " << i+1 << endl; 
            return 0; 
        }

        m[a] = i+1; 
    }

    cout << -1 << endl; 
}