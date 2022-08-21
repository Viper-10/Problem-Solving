#include<iostream>
#include<set>
using namespace std; 
int main(){
    int n;
    cin >> n; 

    multiset<int> s; 
    int towers = 0; 

    for(int i = 0;i < n; ++i){
        int a; 
        cin >> a; 

        set<int>::iterator it = s.upper_bound(a); 

        if(it == s.end()){
            s.insert(a); 
            towers++; 
        }else{
            s.erase(it);
            s.insert(a);
        }  
    }
    cout << towers << endl; 
    return 0; 
}