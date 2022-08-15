#include<iostream>
#include<algorithm>
#include<set>
using namespace std; 
int main(){
    int n, m; 
    cin >> n >> m; 
    
    multiset<int> s; 

    for(int i = 0;i < n; ++i){
        int a; cin >> a; 
        s.insert(a); 
    }

    while(m--){
        int price; 
        cin >> price; 

        auto it = s.lower_bound(price+1);
        if(it == s.begin()){
            cout << -1; 
        }else{
            it--; 
            cout << *it; 
            s.erase(it); 
        }

        cout << endl;
    }

    return 0; 
}