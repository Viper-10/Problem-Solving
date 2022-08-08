#include<iostream>
using namespace std; 
int main(){
    int t; 
    cin >> t; 

    while(t--){
        int x, y; 
        cin >> x >> y; 

        int64_t big = max(x, y); 
        int64_t over = (big-1) * (big-1); 

        if((big&1) == 0){
            if(min(x, y) == y){
                cout << big*big-(y-1)<< endl; 
            }else{
                cout << over+x << endl; 
            }
        }else{
            if(min(x, y) == y){
                cout << over+y << endl; 
            }else{
                cout << big * big-(x-1) << endl; 
            }
        }
    }

    return 0; 
}