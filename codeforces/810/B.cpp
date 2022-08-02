#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
bool compare(vector<int>& a, vector<int>& b){
    return a[0] > b[0]; 
} 
int main(){
    int t; 
    cin >> t; 

    while(t--){
        int n, m; 
        cin >> n >> m; 

        vector<int> arr(n, 0); 
        vector<bool> taken(n, false); 
        vector<vector<int>> friends(n); 
        vector<vector<int>> pairs; 

        for(int i = 0;i < n; ++i){
            cin >> arr[i]; 
        }

        for(int i = 0;i < m; ++i){
            int a, b; 
            cin >> a >> b; 
            a--; 
            b--; 

            friends[a].push_back(b); 
            friends[b].push_back(a);
            vector<int> temp; 
            
            temp.push_back(arr[a]+arr[b]); 
            temp.push_back(a); 
            temp.push_back(b);
            pairs.push_back(temp);
        }

        sort(pairs.begin(), pairs.end(), compare);
        vector<int> last; 
        bool even = true; 

        for(int i = 0;i < m;++i){
            if(taken[pairs[i][1]] || taken[pairs[i][2]]){
                continue; 
            }

            taken[pairs[i][1]] = true; 
            taken[pairs[i][2]] = true; 

            last = pairs[i]; 
            even = !even; 
        }

            // sort by highest unhappiness value pair. 
            // take them and maintain last pair. 

            // next for all unvisited people, check if they've friends.
            // if their friends are taken, then we consider their unhappiness. 
            // if their friends are not taken, check their friends unhappiness value. 
            //  choose the friend or himself based on highest unhappiness value. 
            //  mark him as taken. 

        if(!even){
            taken[last[1]] = false; 
            taken[last[2]] = false; 
        }

        int64_t ans = 0; 

        for(int i = 0;i < n; ++i){
            if(!taken[i]){
                bool friendTaken = false; 
                int unhappinessValue = arr[i]; 
                int person = i; 

                for(int& f: friends[i]){
                    if(taken[f]){
                        friendTaken = true;
                        break; 
                    }

                    if(arr[f] > unhappinessValue){
                        unhappinessValue = arr[f];
                        person = f; 
                    }
                }

                if(friendTaken){
                    ans += arr[i]; 
                }

                if(person != i){
                    ans += arr[i]; 
                }
            }
        }
        cout << ans << endl; 
    }

    return 0; 
}