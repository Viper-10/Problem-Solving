#include<iostream>
#include<algorithm>
using namespace std; 
int main(){
    int n, m, k; 
    cin >> n >> m >> k; 

    int* a = new int[n]; 
    int* b = new int[m]; 

    for(int i = 0;i < n; ++i){
        cin >> a[i]; 
    }

    for(int j = 0;j < m; ++j){
        cin >> b[j]; 
    }

    sort(a, a+n); 
    sort(b, b+m); 

    int ans = 0; 

    for(int i = 0, j = 0;i < n && j < m;){
        if(abs(a[i]-b[j]) <= k) {
            ans++; 
            i++; 
            j++; 
        }
        else if(a[i] > b[j]){
            j++;
        }
        else{
            i++; 
        }
    }

    cout << ans << endl; 
    return 0; 
}