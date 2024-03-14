/*
    https://www.acmicpc.net/problem/1748
    (consecutive number digit 1)

    similar problem
        https://www.acmicpc.net/problem/1790
        (consecutive number digit 2)

        https://www.acmicpc.net/problem/2154
        (consecutive number digit 3)

    solutions
        https://www.acmicpc.net/source/40005833
        (at_dotist, 0 ms)
        https://www.acmicpc.net/source/31505436
        (oculis, 0 ms)

        implemented in solve_2()
            https://www.acmicpc.net/source/30762851
            (bini0130, 0 ms)
            https://www.acmicpc.net/source/35244743
            (luniro, 0 ms)
            https://www.acmicpc.net/source/36565775
            (sons369, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MIN_NUM = 1;
const int MAX_NUM = 100'000'000;    // 10^8

ll N;

void solve_1(){
    ll total_digit = 0;
    ll start_num = 1;
    ll digit = 1;
    ll numbers = 9;
    while(N){
        ll cnt = numbers * digit;
        if(numbers < N){
            N -= numbers;
            total_digit += cnt;

            numbers *= 10;
            ++digit;
        }
        else{
            break;
        }
    }

    if(N){
        total_digit += N * digit;
    }
    cout << total_digit << endl;
}

void solve_2(){
    int digit = 0;
    for(int num=1; num<=N; num*=10){
        digit += N - num + 1;
    }
    cout << digit << endl;
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
