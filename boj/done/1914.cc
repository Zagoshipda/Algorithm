/*
    https://www.acmicpc.net/problem/1914
    (hanoi tower)

    similar problem
        https://www.acmicpc.net/problem/11729
        (hanoi tower)

        https://www.acmicpc.net/problem/23250
        (hanoi tower kth move)

        https://www.acmicpc.net/problem/31248
        (hanoi tower +1 tower)

        https://www.acmicpc.net/problem/16684
        (hanoi tower restricted)

    reference
        https://en.wikipedia.org/wiki/Tower_of_Hanoi

    solution
        bitwise operations on
            https://www.acmicpc.net/source/5798717
            (kajebiii, 140 ms) : vector<int> (100)
            https://www.acmicpc.net/source/5982920
            (Juno, 140 ms) : int array[40]
            https://www.acmicpc.net/source/6068347
            (codemaster3, 132 ms) : int array[100]
            https://www.acmicpc.net/source/15438353
            (sochun1518, 108 ms) : string

            long long array[2], 16 digits for each, implemented in calculate_number()
                https://www.acmicpc.net/source/1206985
                (csehydrogen, 12 ms)
                https://www.acmicpc.net/source/10265604
                (norang, 20 ms)
            https://www.acmicpc.net/source/4332109
            (sk7755, 16 ms) :  int array[4], 8 digits for each

        https://www.acmicpc.net/source/668129
        (joeyvalentine, 128 ms) : hard-coded numbers pre-calculated on char array[][32]

        https://www.acmicpc.net/source/5752012
        (donggyu04, 76 ms) : double (precision... ?)
        https://www.acmicpc.net/source/19182304
        (snowflake, 8 ms) : __int128
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        1. # of moves
        dp ?
            dp[k] = 2 * dp[k-1] + 1
                  = 2^k - 1
        (observation) largest plate does not affect the others

        1 0 0 > 0 0 1 : 1
        2 0 0 > 1 1 0 > 0 1 1 > 0 0 2 : 3
        3 0 0 > 1 2 0 (3) > 0 2 1 > 0 0 3 (3) : 7
        4 0 0 > 2 0 2 (3) > 1 3 0 (4) > 0 3 1 > 2 0 2 (4) > 0 0 4 (3) : 15
        ...
        k 0 0 > 1 k-1 0 > 0 k-1 1 > 0 0 k : dp[k] = dp[k-1] + 1 + dp[k-1]

        2. exact moves
        recurrence relation
            k 0 0   : k -> C
            1 k-1 0 : 1 -> C
            0 k-1 1 : k-1 -> C
            0 0 k   : (DONE)

        2^100 ~ 10^3^10 ~ 10^30

*/

const int MAX_NUM = 100;    // 10^2
const int PRINT_RANGE = 20;
const int MAX_BIT = 35;
const ll MOD = 1'000'000'000'000'000'000;   // 10^18

int N;

void calculate_number(){
    ll msb = 0, lsb = 1;    // 18-bit each
    for(int shift=1; shift<=N; ++shift){
        msb <<= 1;
        lsb <<= 1;

        // carry
        msb += lsb / MOD;
        lsb %= MOD;
    }

    if(msb){
        cout << msb;
    }
    cout << lsb-1 << endl;
}

void recursion_1(int src, int dest, int extra, int cnt, int num){
    if(cnt == 1){
        // cout << num << " : ";
        cout << src << " " << dest << endl;
        return;
    }

    recursion_1(src, extra, dest, num-1, num-1);
    recursion_1(src, dest, extra, 1, num);
    recursion_1(extra, dest, src, num-1, num-1);
}

void recursion_2(int src, int dest, int extra, int num){
    if(num <= 1){
        cout << src << " " << dest << endl;
        return;
    }

    recursion_2(src, extra, dest, num-1);
    recursion_2(src, dest, extra, 1);
    recursion_2(extra, dest, src, num-1);
}

void recursion_3(int src, int dest, int extra, int num){
    if(num <= 0){
        return;
    }

    recursion_3(src, extra, dest, num-1);
    cout << src << " " << dest << endl;
    recursion_3(extra, dest, src, num-1);
}

void solve_recursive(){
    calculate_number();

    if(N <= PRINT_RANGE){
        // recursion_1(1, 3, 2, N, N);
        recursion_2(1, 3, 2, N);
        // recursion_3(1, 3, 2, N);
    }
}

void solve(){
    solve_recursive();
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
