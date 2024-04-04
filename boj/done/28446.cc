/*
    https://www.acmicpc.net/problem/28446
    (find bowling ball)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        (unique) All weights are different
*/

const int NUM_QUERY = 500'000;          // 5 * 10^5
const int NUM_BOX = 1'000'000;          // 10^6
const int MAX_WEIGHT = 1'000'000'000;   // 10^9

enum TYPES{
    insert = 1,
    lookup = 2,
};

int M;
int type;
int x, w;
unordered_map<int, int> hashes;

void solve(){
    if(type == insert){
        cin >> x >> w;
        hashes.insert({w, x});
    }
    else if(type == lookup){
        cin >> w;
        cout << hashes[w] << endl;
    }
    else{
        // error
    }
}

void input(){
    cin >> M;
    while(M--){
        cin >> type;
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
