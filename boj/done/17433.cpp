/*
    https://www.acmicpc.net/problem/17433
    (mysterious number)

    similar problem
        https://www.acmicpc.net/problem/1684
        (same remainder)
        https://www.acmicpc.net/problem/2981
        (granica)

    solutions
        https://www.acmicpc.net/source/39594253
        (YunGoon, 0 ms)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    when infinity ?
        N = 1 or all numbers are the same
*/

const int SIZE_ARR = 2'000;
int T;
int N;
int numbers[SIZE_ARR + 1];
set<int> numbers_set;

void solve_1(){
    if(numbers_set.size() <= 1){
        cout << "INFINITY" << endl;
    }
    else{
        int num = 0;
        for(int idx=1; idx<N; ++idx){
            num = gcd(num, abs(numbers[idx] - numbers[idx+1]));
        }
        cout << num << endl;
    }
}

void solve_2(){
    int num = 0;
    for(int idx=1; idx<N; ++idx){
        num = gcd(num, abs(numbers[idx] - numbers[idx+1]));
    }
    if(num){
        cout << num << endl;
    }
    else{
        cout << "INFINITY" << endl;
    }
}

void solve(){
    // solve_1();

    solve_2();
}

void input(){
    cin >> T;
    while(T--){
        cin >> N;
        numbers_set.clear();
        for(int i=1; i<=N; ++i){
            cin >> numbers[i];
            // numbers_set.insert(numbers[i]);
        }

        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
