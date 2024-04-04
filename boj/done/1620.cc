/*
    https://www.acmicpc.net/problem/1620
    (pokemon master)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MAX_NUM = 100'000;    // 10^5
int N, M;
string name;
string query;

unordered_map<int, string> hashes_int;
unordered_map<string, int> hashes_string;
void solve(){
    if('0' <= query[0] && query[0] <= '9'){
        cout << hashes_int[stoi(query)] << endl;
    }
    else{
        cout << hashes_string[query] << endl;
    }
}

void input(){
    cin >> N >> M;
    for(int i=1; i<=N; ++i){
        cin >> name;
        hashes_int.insert({i, name});
        hashes_string.insert({name, i});
    }
    for(int i=1; i<=M; ++i){
        cin >> query;
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
