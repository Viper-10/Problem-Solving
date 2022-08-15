#include<iostream>
#include<algorithm>
#include<vector>
using namespace std; 
int main(){
    int n; 
    cin >> n;

    vector<pair<int, int>> movies; 
    for(int i = 0;i < n; ++i){
        int a, b; 
        cin >> a >> b; 
        movies.push_back({b, a});
    }

    sort(movies.begin(), movies.end()); 

    int prevEndTime = -1, ans = 0; 

    for(int i = 0;i < n; ++i){
        if(movies[i].second >= prevEndTime){
            prevEndTime = movies[i].first; 
            ans++; 
        }
    }

    cout << ans << endl; 

    return 0; 
}