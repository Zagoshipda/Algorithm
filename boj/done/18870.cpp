/*
    https://www.acmicpc.net/problem/18870
    (coordinate compression)

    solution
        https://www.acmicpc.net/source/38729117
        (rhs0266, 320 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int NUM = 1'000'000;
int N;
pair<int, int> X_i[NUM + 1];    // (X_i, idx)
int Y_i[NUM + 1];


void solve_1(){
    sort(X_i+1, X_i+1+N, less<pair<int, int> >());
    // int new_val = 1;    // WRONG
    int new_val = 0;    // AC : # of coordinates s.t. < X_i[1]
    int idx = 1;
    auto [_, pos] = X_i[idx];
    Y_i[pos] = new_val;
    for(idx=2; idx<=N; ++idx){
        auto [val_1, pos_1] = X_i[idx-1];
        auto [val_2, pos_2] = X_i[idx];
        if(val_1 == val_2){
            Y_i[pos_2] = new_val;
        }
        else{
            Y_i[pos_2] = ++new_val;
        }
    }

    for(int idx=1; idx<=N; ++idx){
        cout << Y_i[idx] << " ";
    }
    cout << endl;
}

void solve_2(){
    sort(X_i+1, X_i+1+N, less<pair<int, int> >());
    int cnt = 0;
    Y_i[X_i[1].second] = cnt;
    for(int idx=2; idx<=N; ++idx){
        if(X_i[idx-1].first != X_i[idx].first){
            ++cnt;
        }
        Y_i[X_i[idx].second] = cnt;
    }

    for(int idx=1; idx<=N; ++idx){
        cout << Y_i[idx] << " ";
    }
    cout << endl;
}

void solve(){
    solve_1();

    // solve_2();
}

void input(){
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> X_i[i].first;
        X_i[i].second = i;
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
