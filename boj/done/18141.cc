/*
    https://www.acmicpc.net/problem/18141
    (are they all integers)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int ARR_SIZE = 50;

int n;
int arr[ARR_SIZE + 1];

void solve(){
    for(int idx=1; idx<=n; ++idx){
        for(int jdx=1; jdx<=n; ++jdx){
            for(int kdx=1; kdx<=n; ++kdx){
                if(idx != jdx && idx != kdx && jdx != kdx){
                    if((arr[idx] - arr[jdx]) % arr[kdx]){
                        cout << "no" << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "yes" << endl;
}

void input(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> arr[i];
    }
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
