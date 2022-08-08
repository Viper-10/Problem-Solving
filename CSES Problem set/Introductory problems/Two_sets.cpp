#include<iostream>
using namespace std; 
void printOdd(int i, int n){
    for(int x = i;x < n/2; x += 2) cout << x << " " << n-x << " "; 
    cout << endl; 
}
void printEven(int i, int n){
    for(int x = i;x <= n/2; x += 2){
        cout << x << " " << (n+1)-x << " ";
    }

    cout << endl;
}
int main(){
    int n; 
    cin >> n; 

    if((((n * (n+1))/2 % 2)) & 1){
        cout << "NO" << endl; 
        return 0; 
    }

    cout << "YES" << endl; 

    if((n&1)){
        cout << n/2 +1 << endl; 
        cout << n/2 << " " << n/2+1 << " "; 

        printOdd(1, n); 
        
        cout << n/2 << endl; 
        cout << n << " "; 

        printOdd(2, n); 
    }

    else{
        cout << n/2 << endl; 
        printEven(1, n);
        cout << n/2 << endl;
        printEven(2, n);
    }
    return 0; 
}