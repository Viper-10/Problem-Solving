// Traveling Salesman Problem
#include<iostream>
using namespace std; 
int main(){
    int t; 
    cin >> t; 

    while(t--){
        int n; 
        cin >> n; 

        int x, y; 
        int posX = 0, posY = 0, negX = 0, negY = 0; 

        while(n--){
            cin >> x >> y; 
            
            x >= 0 ? posX = max(posX, x) : negX = min(negX, x); 
            y >= 0 ? posY = max(posY, y) : negY = min(negY, y);
        }
        
        cout << 2 * (posX+posY-negX-negY) << endl; 
    }

    return 0; 
}