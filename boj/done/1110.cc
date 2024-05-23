/*
    https://www.acmicpc.net/problem/1110
    (addition cycle)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

int N;
// string N_str;
// string next_num;
int curr;
int sum;
int cycle;

void solve(){
    curr = N;

    while(true){
        ++cycle;
        sum = 0;
        for(int val=curr; val; val/=10){
            sum += val % 10;
        }
        curr %= 10;
        curr = curr * 10 + sum % 10;
        if(curr == N){
            cout << cycle << endl;
            break;
        }
    }
}

void input(){
    cin >> N;
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
