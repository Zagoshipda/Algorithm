/*
    https://www.acmicpc.net/problem/1676
    (trailing zeros on factorial)

    similar problem
        https://www.acmicpc.net/problem/9693
        (trailing zeros on factorial)

        https://www.acmicpc.net/problem/2004
        (trailing zeros on combination)

        https://www.acmicpc.net/problem/1564
        (factorial 5)

    solutions
        https://www.acmicpc.net/source/226577
        (koosaga, 0 ms) : implemented in solve_2()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    10! = 10 9 8 7 6 5 4 3 2 1
          5*2        5
*/

int N;

void solve_1(){
    int cnt = 0;
    for(int factor=5; factor<=N; factor*=5){
        // for(int num=factor; num<=N; num+=factor){
        //     ++cnt;
        // }
        cnt += N/factor;
    }
    cout << cnt << endl;
}

void solve_2(){
    cout << (N / 5 + N / 25 + N / 125) << endl;
}

void solve(){
    // solve_1();

    solve_2();
}

void input(){
    cin >> N;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
