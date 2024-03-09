/*
    https://www.acmicpc.net/problem/30999
    (democracy) : demo + cracy
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

int N, M;
string vote;
const char YES = 'O';
const char NO = 'X';
int problems;

void solve(){

}

void input(){
    cin >> N >> M;
    while(N--){
        cin >> vote;
        int len = vote.size();
        int cnt = 0;
        for(int idx=0; idx<len; ++idx){
            if(vote[idx] == YES){
                ++cnt;
            }
        }
        if(cnt > (M >> 1)){
            ++problems;
        }
    }
    cout << problems << endl;
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
