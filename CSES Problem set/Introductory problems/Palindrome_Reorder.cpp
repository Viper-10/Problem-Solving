#include<iostream>
#include<stack>
using namespace std; 
int main(){
    string s; 
    cin >> s; 

    int freq[26] = {0};

    for(char& c: s){
        freq[c-'A']++; 
    }

    int oddFreqCount = 0; 

    for(int i = 0;i < 26; ++i){
        if((freq[i] & 1) == 1) oddFreqCount++; 
    }

    if(oddFreqCount > 1){
        cout << "NO SOLUTION" << endl; 
        return 0; 
    }

    stack<char> st;

    char odd = '$'; 

    for(int i = 0;i < 26; ++i){
        while(freq[i]){
            if(freq[i] == 1){
                odd = 'A'+i; 
                freq[i] = 0; 
            }else{
                cout << (char)('A'+i); 
                st.push('A'+i); 
                freq[i] -= 2; 
            }
        }
    } 

    if(odd != '$') cout << odd; 

    while(!st.empty()){
        cout << st.top(); 
        st.pop(); 
    }

    cout << endl; 
    return 0; 
}