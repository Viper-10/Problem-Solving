#include<iostream>
#define ROBOT 'R'
#define FIRST -1
using namespace std; 
bool solve(char** matrix, const int& m, const int& n){
    int min_r = -1, min_c = -1; 
    for(int i = 0;i < m; ++i){
        for(int j = 0;j < n; ++j){
            if(matrix[i][j] == ROBOT){
                if(min_r == FIRST) min_r = i; 
                if(min_c == FIRST || j < min_c) min_c = j;  
            }
        }
    }

    return matrix[min_r][min_c] == ROBOT; 
}
int main(){
    int t;
    cin >> t; 
    while(t--){
        int m, n; 
        cin >> m >> n; 
        
        char** matrix = new char*[m]; 

        for(int i = 0;i < m; ++i){
            matrix[i] = new char[n]; 

            for(int j = 0;j < n; ++j){
                cin >> matrix[i][j]; 
            }
        }

        cout << (solve(matrix, m, n) ? "YES" : "NO") << endl; 
    }
    return 0; 
}