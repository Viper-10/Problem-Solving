#include<iostream>
using namespace std; 
int solve(int& l1,  int& l2, int& r1, int& r2){
    if(l1 > l2){
        swap(l1, l2); 
        swap(r1, r2); 
    }

    return (l2 <= r1) ? l2 : l1+l2; 
}
int main(){
    int t; 
    cin >> t; 

    while(t--){
        int l1, l2, r1, r2; 
        cin >> l1 >> r1 >> l2 >> r2; 

        cout << solve(l1, l2, r1, r2) << endl; 
    }

    return 0; 
}