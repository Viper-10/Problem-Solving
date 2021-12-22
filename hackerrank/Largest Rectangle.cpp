#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'largestRectangle' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY h as parameter.
 */

int64_t largestRectangle(vector<int>& h) {
    int n = h.size(); 
    stack<int> s; 
    int64_t area = 0;
    
    for(int i = 0;i < n; ++i){
        while(!s.empty() && h[i] <= h[s.top()]){
            int64_t topElementArea = (i-s.top()) * h[s.top()]; 
            int topElementIndex = s.top(); 
            
            s.pop(); 
            
            if(s.empty())
                topElementArea += (int64_t)topElementIndex * h[topElementIndex];
            
            else 
                topElementArea += (topElementIndex - s.top()) * (int64_t)h[topElementIndex];
            
            area = max(area, topElementArea); 
        }
        
        s.push(i);
    }
    
    int i = n-1; 
    while(!s.empty()){
        int x = s.top(); 
        s.pop(); 
        
        int64_t topElementArea = (int64_t)(i - x) * h[x]; 
        
        if(s.empty()) topElementArea += (int64_t)(x+1) * h[x]; 
        
        else topElementArea += (int64_t)(x-s.top()) * h[x]; 
        
        area = max(area, topElementArea); 
        
    }
    
    return area; 
}
   
int main()
{
    int n; 
    cin >> n; 
    
    vector<int> h(n, 0); 
    for(int i = 0;i < n; ++i){
        cin >> h[i]; 
    }
    
    cout << largestRectangle(h) << endl;
    return 0; 
}
 
