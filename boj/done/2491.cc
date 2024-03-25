/*
    https://www.acmicpc.net/problem/2491
    (sequence)

    solutions
        https://www.acmicpc.net/source/11331250
        (jhnah917, 4 ms) : 2-pass

        https://www.acmicpc.net/source/17291829
        (clrmt, 4 ms) : 1-pass
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
int numbers[MAX_NUM + 1];

void solve(){
    int max_cnt = 1;

    // 1. consequtive increasing sequence
    int cnt = 1;
    for(int idx=2; idx<=N; ++idx){
        if(numbers[idx-1] <= numbers[idx]){
            ++cnt;
            max_cnt = max(max_cnt, cnt);
        }
        else{
            cnt = 1;
        }
    }

    // 2. consecutive decreasing sequence
    cnt = 1;
    for(int idx=2; idx<=N; ++idx){
        if(numbers[idx-1] >= numbers[idx]){
            ++cnt;
            max_cnt = max(max_cnt, cnt);
        }
        else{
            cnt = 1;
        }
    }

    cout << max_cnt << endl;
}

void input(){
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> numbers[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
