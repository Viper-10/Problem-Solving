#include<iostream>
using namespace std; 
int main(){
    string s; 
    cin >> s; 

    int maxOccurence = 0; 

    for(int i = 0;i < s.length(); ++i){
        int storeI = i; 
        while(i < s.length()-1 && s[i] == s[i+1]){
            i++; 
        }

        if(i-storeI+1 > maxOccurence){
            maxOccurence = i-storeI+1; 
        }
    }

    cout << maxOccurence << endl; 

    return 0; 
}