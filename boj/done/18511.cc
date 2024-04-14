/*
    https://www.acmicpc.net/problem/18511
    (lower bound)

    solutions
        https://www.acmicpc.net/source/26994137
        (hanil0623, 0 ms)
        https://www.acmicpc.net/source/18101934
        (kdh9949, 0 ms)
        https://www.acmicpc.net/source/18593659
        (kdr06006, 0 ms) : implemented in solve_backtracking_2()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    8 bits, 3 elements
    => 3^8 ~ 10^4
    => brute force


100000000 1
1

// 11111111 (O)
// 0        (X)

*/

const int MAX_NUM = 100'000'000;    // 10^8
const int MAX_SIZE = 3;

int N, K;
string N_str;
int val;

set<int> digits;
int bits;
int ans;

void solve_backtracking_1(int nth, int num){
    // if(nth >= bits){
    //     if(num <= N){
    //         ans = max(ans, num);
    //     }
    //     return;
    // }

    if(num <= N){
        ans = max(ans, num);
    }

    if(nth >= bits){
        return;
    }

    for(int digit : digits){
        solve_backtracking_1(nth+1, num*10 + digit);
    }
}

void solve_backtracking_2(int num){
    if(num > N){
        return;
    }

    ans = max(ans, num);
    for(int digit : digits){
        solve_backtracking_2(num*10 +digit);
    }
}

void solve(){
    bits = N_str.size();
    N = stoi(N_str);

    // solve_backtracking_1(0, 0);

    solve_backtracking_2(0);
    cout << ans << endl;
}

void input(){
    cin >> N_str >> K;
    for(int i=1; i<=K; ++i){
        cin >> val;
        digits.insert(val);
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
