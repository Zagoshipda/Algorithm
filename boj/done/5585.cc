/*
    https://www.acmicpc.net/problem/5585
    (keep the change)

    solutions
        https://www.acmicpc.net/source/1216059
        (sujin, 0 ms)
        https://www.acmicpc.net/source/2360048
        (ntopia, 0 ms) : implemented in solve_2()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MONEY = 1'000;
int N;
int numbers[] = {500, 100, 50, 10, 5, 1};

void solve_1(){
    N = MONEY - N;
    int cnt = 0;
    for(int number : numbers){
        while(number <= N){
            N -= number;
            ++cnt;
        }
    }
    cout << cnt << endl;
}

void solve_2(){
    N = MONEY - N;
    int cnt = 0;
    for(int number : numbers){
        cnt += N / number;
        N %= number;
    }
    cout << cnt << endl;
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
