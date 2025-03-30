/*
    https://www.acmicpc.net/problem/15979
    (finding master)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

12 16

// 2 : (0 0) > (11 16) > (12 16)


6 14

// 2
// (7 14) (6 15)

*/

const int START_X = 0;
const int START_Y = 0;
int M, N;

int gcd_recursive(int num_1, int num_2){
    if(num_1 < 0){
        num_1 = -num_1;
    }
    if(num_2 < 0){
        num_2 = -num_2;
    }
    return num_2 ? gcd_recursive(num_2, num_1 % num_2) : num_1;
}

void solve_1(){
    if(M == 0 && N == 0){
        cout << 0 << endl;
    }
    // else if(gcd_recursive(M, N) == 1){
    else if(gcd(M, N) == 1){
        cout << 1 << endl;
    }
    else{
        cout << 2 << endl;
    }
}

void solve(){
    solve_1();
}

void input(){
    cin >> M >> N;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
