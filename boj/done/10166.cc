/*
    https://www.acmicpc.net/problem/10166
    (stand)

    solution
        https://www.acmicpc.net/source/5312074
        (lety, 64 ms) : implemented in solve_dp_1()

        implemented in solve_dp_2()
        (fast) considering multiples
            https://www.acmicpc.net/source/7621867
            (spectaclehong, 0 ms)
            https://www.acmicpc.net/source/8989571
            (dajinstory, 0 ms)
        (slow) considering divisors
            https://www.acmicpc.net/source/2866176
            (thkighie1224, 12 ms)
            https://www.acmicpc.net/source/11338369
            (sadboy, 12 ms)
            https://www.acmicpc.net/source/3924661
            (semteo02, 8 ms) : optimize for checking half range
            https://www.acmicpc.net/source/1040017
            (rhkdgus232, 4 ms) : optimize using checker
            https://www.acmicpc.net/source/350822
            (yukariko, 28 ms) : 1d array
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        method 1. # of divisors of lcm(D1 ... D2) ?
            => lcm overflow
        method 2. just check positions mod 360, in a fraction

    simulation
        4 6
            lcm 12
            3 2 => lcm 6
            12 / 6 = 2
            4 + 6 - 2 = 8

        3 6
            lcm 6
            2 1 => lcm 2
            6 / 2 = 3
            3 + 6 - 3 = 6

        3 4 6
            lcm 12
            4 3 2 => lcm 12
            12 / 12 = 1

        1 2 3 4 5  6  7 ... : radius
        1 1 2 2 4  2  6 ... : add
        1 2 4 6 10 12

        3 4 5 6 => lcm 60 = 2^2 * 3 * 5
        20 40 60
        15 30 45 60
        12 24 36 48 60
        10 20 30 40 50 60
        10 12 15 20 24 30 36 40 45 48 50 60 : 12

        4 5 6 => lcm 60
*/

const int MOD = 360;    // 10^3
const int MAX_NUM = 2'000;  // 10^3

int D_1, D_2;

bool is_seat[MOD];

void solve_wrong(){
    for(int radius=D_1; radius<=D_2; ++radius){
        int step = MOD / radius;
        for(int idx=0; idx<MOD; idx+=step){
            is_seat[idx] = true;
        }
    }

    int cnt = 0;
    for(int idx=0; idx<MOD; ++idx){
        cnt += is_seat[idx];
    }
    cout << cnt << endl;
}

// bool dp[MOD * (MAX_NUM + 1)][MAX_NUM + 1];  // memory : 10^9
bool dp[MAX_NUM + 1][MAX_NUM + 1];  // memory : 10^6
void solve_dp_1(){
    int cnt = 1;
    dp[0][1] = true;
    for(int radius=D_1; radius<=D_2; ++radius){
        for(int ith=1; ith<radius; ++ith){
            int _gcd = gcd(ith, radius);
            // if(!dp[ith / _gcd][radius / _gcd]){
            //     ++cnt;
                dp[ith / _gcd][radius / _gcd] = true;
            // }
        }
    }

    for(int radius=2; radius<=D_2; ++radius){
        for(int ith=1; ith<radius; ++ith){
            cnt += dp[ith][radius];
        }
    }
    cout << cnt << endl;
}

int dp_2[MAX_NUM + 1];
void solve_dp_2(){
    // initialize : only count the disjoint spots
    for(int num=1; num<=D_2; ++num){
        dp_2[num] += num;
        for(int multiple=(num<<1); multiple<=D_2; multiple+=num){
            dp_2[multiple] -= dp_2[num];
        }
    }

    // counting
    int cnt = 0;
    for(int num=1; num<D_1; ++num){
        int multiple = num;
        while(multiple < D_1){
            multiple += num;
        }
        // from the inner radius to the outer radius
        if(D_1 <= multiple && multiple <= D_2){
            cnt += dp_2[num];
        }
    }
    // radius along the target range
    for(int num=D_1; num<=D_2; ++num){
        cnt += dp_2[num];
    }
    cout << cnt << endl;
}

void solve(){
    // solve_wrong();

    // solve_dp_1();
    solve_dp_2();
}

void input(){
    cin >> D_1 >> D_2;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
