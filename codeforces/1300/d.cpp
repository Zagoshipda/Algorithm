#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int n;
vector<pair<int, int>> p;

int main(void){

    cin >> n;
    int x, y;
    for(int i=0; i<n; ++i){
        cin >> x >> y;
        pair<int, int> temp = make_pair(x, y);
        p.push_back(temp);
    }
    if(n & 1){
        cout << "NO" << endl;
    }
    else{
        int cenx = (p[0].first + p[n/2].first);
        int ceny = (p[0].second + p[n/2].second);
        bool flag = true;
        for(int j=1; j<n/2; ++j){
            if((p[j].first + p[j+n/2].first) != cenx || (p[j].second + p[j+n/2].second) != ceny){
                cout << "NO" << endl;
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }
    }
    

    return 0;
}
