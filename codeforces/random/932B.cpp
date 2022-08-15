#include<iostream>
#include<cstdio>
using namespace std; 
int values[10][1000001]; 
int f(int n){
    int product = 1; 

    while(n > 0){
        int remainder = n%10; 
        if(remainder) product *= remainder; 
        n /= 10; 
    }

    return product;
}
int g(int n){
    if(n < 10) return n; 

    return g(f(n)); 
}
void precompute(){
    for(int i = 1;i <= 1000000; ++i){
        values[g(i)][i] = 1; 
    }

    for(int i = 1;i < 10; ++i){
        for(int j = 1;j <= 1000000; ++j){
            values[i][j] += values[i][j-1]; 
        }
    }
}
int main(){
    int t; 
    scanf("%d", &t);

    precompute(); 
    while(t--){
        int l, r, k; 
        scanf("%d%d%d", &l,&r,&k);

        printf("%d\n", values[k][r] - values[k][l-1]);
    }
    return 0; 
}