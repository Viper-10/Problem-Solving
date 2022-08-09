#include<iostream>
#include<set>
using namespace std; 
set<int> s; 
void calcPerfectSquare(){
    for(int i = 0;i*i <= 200000; ++i){
        s.insert(i*i);
    }
}
void solve(int n){

    if(n < 0) return; 

    int nextSquare = *s.lower_bound(n);
    int l = nextSquare - n; 
    int r = n; 

    // between l and r sum will always remain l+r taking them 
    // towards them. That is (l, r), (l+1, r-1), (l+2, r-2)..

    solve(l-1); 
    
    while(r >= l){
        cout << r << " "; 
        r--; 
    }
}
int main(){

    calcPerfectSquare(); 

    int t; 
    cin >> t; 
    while(t--){
        int n; 
        cin >> n; 

        // 0 to n-1
        solve(n-1); 
        cout << endl; 
    }

    return 0; 
}