#include<iostream>
#include<algorithm>
using namespace std; 
int main(){

    int n; 
    cin >> n; 

    int* coins = new int[n]; 

    for(int i = 0;i < n; ++i) cin >> coins[i]; 

    sort(coins, coins+n); 

    int64_t canMake = 0; 
    for(int i = 0;i < n; ++i){
        int64_t next = canMake+1; 

        if(coins[i] > next) break; 
        
        else{
            canMake += coins[i]; 
        }
    }

    cout << canMake+1 << endl; 

    return 0; 
}