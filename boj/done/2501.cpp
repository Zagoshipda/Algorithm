/*
    finding k-th smallest divisor
    https://www.acmicpc.net/problem/2501

    https://www.acmicpc.net/source/3046739
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE_N 10'000
int N, K;

void input(){
    cin >> N >> K;
}

void solve(){
    int cnt = 0;
    int kth_divisor = 0;
    for(int num=1; num<=N; ++num){
        if(N % num == 0){
            ++cnt;
        }
        if(cnt == K){
            kth_divisor = num;
            break;
        }
    }

    cout << kth_divisor << endl;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
