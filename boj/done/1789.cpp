/*
    https://www.acmicpc.net/problem/1789
    (sum of numbers 1)

    solutions
        https://www.acmicpc.net/source/2171184
        (zard320, 0 ms) : count the remainder, implemented in solve_greedy_3()

        closed form solution, implemented in solve_greedy_4()
            https://www.acmicpc.net/source/171022
            (ZZangZZang, 0 ms)
            https://www.acmicpc.net/source/24536
            (kdk8747, 0 ms)

            https://www.acmicpc.net/source/69182310
            (chanhui, 108 ms)
            1 + ... + k < S < 1 + ... + k + k+1
            k (k+1) / 2 <= S
            k^2 + k - 2S = 0
            k = (-1 + sqrt(1+8S)) / 2
            k = sqrt(2S + 1/4) - 1/2

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    1+...+N = S = N(N+1)/2
*/

ll S;

void solve_greedy_1(){
    // cout << static_cast<int>(sqrt(2*S))-1 << endl;
    ll sum = 0;
    ll cnt = 0;
    for(int num=1; sum<S; ++num){
        sum += num;
        ++cnt;
    }
    if(sum == S){
        cout << cnt << endl;
    }
    else{
        cout << cnt-1 << endl;
    }
}

void solve_greedy_2(){
    ll sum = 0;
    ll N;
    for(N=1; sum<=S; ++N){
        sum += N;
    }

    // NOTE : N is 1 ahead, therefore N-2, NOT N-1
    cout << N-2 << endl;
}

void solve_greedy_3(){
    ll N = 1;
    while(S >= N){
        S -= N;
        ++N;
    }

    cout << N-1 << endl;
}

void solve_greedy_4(){
    ll N;
    for(N=1; N*(N+1)>>1 <= S; ++N){
    }

    cout << N-1 << endl;
}

void solve_closed_form(){
    cout << static_cast<int>(sqrt(2*S + 0.25) - 0.5) << endl;
}

void solve(){
    solve_greedy_1();

    // solve_greedy_2();

    // solve_greedy_3();

    // solve_greedy_4();

    // solve_closed_form();
}

void input(){
    cin >> S;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
