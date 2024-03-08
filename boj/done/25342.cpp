/*
    https://www.acmicpc.net/problem/25342
    (maximum lcm)

    solutions
        https://www.acmicpc.net/source/45772997
        (cheetose, 20 ms) : brute force
        https://www.acmicpc.net/source/46576661
        (shandy5833, 0 ms) : brute force 3 choices among 4 numbers [n-3...n]

        https://www.acmicpc.net/source/45754036
        (koosaga, 0 ms)
        https://www.acmicpc.net/source/49753802
        (laprand, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
    take 3 numbers with maximum prime factors

    take lcm of 3 numbers

    N = 6
        1 2 3 4 5 6
        1 2 3 22 5 23 => 2 3 5 = 30

    N = 7
        2 3 5 7
        5 6 7
        5 23 7

    N=9
        2 3 5 7
        7 8 9 (O)
        5 6 7 (X)

    N=11
        2 3 5 7 11 : 25 7 11 = 7 10 11 = 770
    N=12
        2 3 5 7 11
        12 11 10 ? 2 6 11 2 5 = 2 5 6 11
        5 6 7 11 = 6 7 11
    N=16
        2 3 5 7 11 13 17 19 23
    14 15 16 : 2 7 3 5 2 8 =  3 2 5 7  8
    13 15 16 : 13  3 5 2 8 =  3 2 5 13 8
    7 11 13

    what if take 2 numbers ?
        NOTE : N-1 & N are coprime

    what if for 3 numbers?
        N-2 & N-1 are coprime
        N-1 & N are coprime
        !=> N-2 & N-1 & N are coprime

        Ga Gb Gc => G abc
        a b c    =>   abc

*/

const int MAX_NUM = 100'000;
int T;
ll N;

void solve_brute_force(){
    ll val;
    for(ll num=N-2; num>=1; --num){
        if(gcd(num, N) == 1 && gcd(num, N-1) == 1){
            // cout << lcm(lcm(N, N-1), num) << endl;
            val = num;
            break;
        }
    }

    ll max_lcm = 0;
    for(ll num_1=val; num_1<=N-2; ++num_1){
        for(ll num_2=num_1+1; num_2<=N-1; ++num_2){
            for(ll num_3=num_2+1; num_3<=N; ++num_3){
                max_lcm = max(max_lcm, lcm(num_1, lcm(num_2, num_3)));
            }
        }
    }
    cout << max_lcm << endl;
}

void solve_wrong(){
    cout << lcm(lcm(N, N-1), N-2) << endl;
}

void solve_2(){
    if(N & 1){
        cout << lcm(N-2, lcm(N-1, N)) << endl;
    }
    else{
        // odd even odd even
        //     N-2  N-1 N
        // N-3      N-1 N   (case 1)
        // N-3 N-2  N-1     (case 2)

        /*
            (case 1) N-3, N are coprime
                    since both are not multiples of 3
                    and the difference is 3,
                    therefore gcd(N-3, N) which is also a factor of 3
                    must then be the 1
        */
        // if(N % 3){
        if(gcd(N-3, N) == 1){
            cout << lcm(N-3, lcm(N-1, N)) << endl;
        }
        /*
            (case 2) N-3, N-1 are coprime
                    since both are odd and the difference is 2 (even)
        */
        else{
            cout << lcm(N-3, lcm(N-2, N-1)) << endl;
        }
    }
}

void solve(){
    // solve_brute_force();

    solve_2();
}

void input(){
    cin >> T;
    while(T--){
        cin >> N;

        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
