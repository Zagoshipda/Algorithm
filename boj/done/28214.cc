/*
    https://www.acmicpc.net/problem/28214
    (cream bread)

    solution
        implemented in solve_2()
            https://www.acmicpc.net/source/63909415
            (xiaowuc1, 0 ms)
            https://www.acmicpc.net/source/64070036
            (rootcucu, 0 ms) : x, 1 - x
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

int N, K, P;

void solve_1(){
    int len = N * K;
    int sell = 0;
    int bread;
    for(int ith=1, group=0, cnt=0; ith<=len; ++ith){
        cin >> bread;
        cnt += bread;
        ++group;
        if(group >= K){
            if(cnt > K-P){
                ++sell;
            }
            cnt = 0;
            group = 0;
        }
    }

    cout << sell << endl;
}

void solve_2(){
    int cream;
    int sell = 0;
    for(int group=1; group<=N; ++group){
        int cnt = 0;
        for(int bread=1; bread<=K; ++bread){
            cin >> cream;
            // cnt += (cream == 0);
            cnt += 1 - cream;
        }
        // if(cnt < P){
        //     ++sell;
        // }
        sell += (cnt < P);
    }

    cout << sell << endl;
}

void solve(){
    // solve_1();

    solve_2();
}

void input(){
    cin >> N >> K >> P;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
