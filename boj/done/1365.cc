/*
    https://www.acmicpc.net/problem/1365
    (twisted wire)

    similar problem
        https://www.acmicpc.net/problem/2565
        (wire 1)
        https://www.acmicpc.net/problem/1946
        (newbie)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MAX_NUM = 100'000;    // 10^5
int N;
int wires[MAX_NUM + 1];

void solve_lis(){
    vector<int> lis;
    lis.push_back(wires[1]);
    for(int idx=2; idx<=N; ++idx){
        if(lis.back() < wires[idx]){
            lis.push_back(wires[idx]);
        }
        else{
            auto it = lower_bound(lis.begin(), lis.end(), wires[idx]);
            *it = wires[idx];
        }
    }
    cout << N - lis.size() << endl;
}

void solve(){
    solve_lis();
}

void input(){
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> wires[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
