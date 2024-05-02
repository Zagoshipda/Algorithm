/*
    https://www.acmicpc.net/problem/24416
    (fibonacci number 1)

    similar problem
        https://www.acmicpc.net/problem/24417
        (fibonacci number 2)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MAX_NUM = 40;

int n;

int cnt_1, cnt_2;
int fibonacci_recursive(int num){
    if(num <= 2){
        ++cnt_1;
        return 1;
    }

    return fibonacci_recursive(num - 1) + fibonacci_recursive(num - 2);
}

int fib[MAX_NUM + 1];
int fibonacci_iterative(){
    fib[1] = 1;
    fib[2] = 1;
    for(int num=3; num<=n; ++num){
        ++cnt_2;
        fib[num] = fib[num-1] + fib[num-2];
    }
    return fib[n];
}

void solve_simulation(){
    fibonacci_recursive(n);
    fibonacci_iterative();

    cout << cnt_1 << " " << cnt_2 << endl;
}

void solve(){
    // solve_simulation();

    cout << fibonacci_iterative() << " " << n-2 << endl;
}

void input(){
    cin >> n;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
