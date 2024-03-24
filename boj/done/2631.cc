/*
    https://www.acmicpc.net/problem/2631
    (line up)

    similar problem
        https://www.acmicpc.net/problem/7570
        (line up)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

const int MAX_NUM = 200;
int N;
int children[MAX_NUM];

void solve_lis(){
    vector<int> lis;
    lis.push_back(children[0]);
    for(int idx=1; idx<N; ++idx){
        if(lis.back() < children[idx]){
            lis.push_back(children[idx]);
        }
        else{
            auto it = lower_bound(lis.begin(), lis.end(), children[idx]);
            *it = children[idx];
        }
    }
    cout << N - lis.size() << endl;
}

void solve(){
    solve_lis();
}

void input(){
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> children[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
