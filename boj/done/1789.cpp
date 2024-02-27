/*
    https://www.acmicpc.net/problem/1789
    (sum of numbers)

    solutions
        https://www.acmicpc.net/source/2171184
        (zard320, 0 ms) : count the remainder, implemented in solve_greedy_3()

        closed form solution, implemented in solve_greedy_4()
            https://www.acmicpc.net/source/171022
            (ZZangZZang, 0 ms)
            https://www.acmicpc.net/source/24536
            (kdk8747, 0 ms)
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

void solve(){
    // solve_greedy_1();

    // solve_greedy_2();

    // solve_greedy_3();

    solve_greedy_4();
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
