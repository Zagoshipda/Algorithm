#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
vector<pair<int, int>> points(3);

int main(){
    IOS;

    cin >> t;
    while(t--){
        for(int i=0; i<3; ++i){
            cin >> points[i].first >> points[i].second;
        }

        int ans = abs(points[0].first - points[1].first) + abs(points[0].second - points[1].second);
        if(points[0].first == points[1].first && points[1].first == points[2].first){
            if((points[2].second - points[1].second) * (points[2].second - points[0].second) < 0){
                ans += 2;
            }
        }
        else if(points[0].second == points[1].second && points[1].second == points[2].second){
            if((points[2].first - points[1].first) * (points[2].first - points[0].first) < 0){
                ans += 2;
            }
        }
        cout << ans << endl;
    }


    return 0;
}
