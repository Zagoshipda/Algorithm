#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
ll n;

int main(){
    IOS;

    cin >> t;
    while(t--){
        cin >> n;
        vector<int> c(n);
        for(int i=0; i<n; ++i){
            cin >> c[i];
        }

        vector<int> odds;
        vector<int> evens;
        odds.push_back(c[0]);
        evens.push_back(c[1]);
        int min_odds = c[0];
        int min_evens = c[1];
        ll sum_odds = n * c[0];
        ll sum_evens = n * c[1];
        ll sum_cost = sum_odds + sum_evens;
        ll min_cost = sum_cost;
        // cout << "first sum : " << min_cost << endl;
        for(int i=2; i<n; ++i){
            if(i&1){
                // cout << "evens" << endl;
                if(c[i] < min_evens){
                    sum_evens -= (n-evens.size()+1) * min_evens;
                    sum_evens += min_evens;

                    min_evens = c[i];
                    evens.push_back(c[i]);

                    sum_evens += (n-evens.size()+1) * min_evens;
                }
                else{
                    evens.push_back(c[i]);

                    sum_evens += c[i];
                    sum_evens -= min_evens;
                }
            }
            else{
                // cout << "odds" << endl;
                if(c[i] < min_odds){
                    sum_odds -= (n-odds.size()+1) * min_odds;
                    sum_odds += min_odds;

                    min_odds = c[i];
                    odds.push_back(c[i]);

                    sum_odds += (n-odds.size()+1) * min_odds;
                }
                else{
                    odds.push_back(c[i]);

                    sum_odds += c[i];
                    sum_odds -= min_odds;
                }
            }
            // cout << "two sums : " << sum_odds << ' ' << sum_evens << endl;
            sum_cost = sum_odds + sum_evens;
            if(sum_cost < min_cost){
                min_cost = sum_cost;
            }
            
        }

        cout << min_cost << endl;
    }

    return 0;
}
