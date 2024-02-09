/*
    https://www.acmicpc.net/problem/17618
    (amazing number)

    solutions
        https://www.acmicpc.net/source/45362279
        (mileyilove0926, 88 ms) : brute force with 8 digits
        https://www.acmicpc.net/source/22966545
        (wyverns077, 76 ms) : 8 digit direct manipulation

        mathematical digit sum
            https://www.acmicpc.net/source/21936122
            (qwertyu, 68 ms)
            https://www.acmicpc.net/source/15973609
            (ldhun041203, 48 ms)
            https://www.acmicpc.net/source/21901678
            (woolim, 40 ms)
            https://www.acmicpc.net/source/23580129
            (20aa20, 40 ms)


        https://www.acmicpc.net/source/18273593
        (jhhope1, 72 ms) : DP on (N, N-1)
        https://www.acmicpc.net/source/44528347
        (wider93, 56 ms) : DP on 10-th powers


        DP on (N, N/10), implemented in solve_2()
            https://www.acmicpc.net/source/15931127
            (ivymso13, 72 ms)
            https://www.acmicpc.net/source/52375083
            (logwns, 64 ms)
            https://www.acmicpc.net/source/44669471
            (allstar13188, 64 ms)
            https://www.acmicpc.net/source/15657188
            (rkm0959, 60 ms)
            https://www.acmicpc.net/source/15641167
            (jjwdi0, 56 ms)
            https://www.acmicpc.net/source/19493771
            (unagi44, 48 ms)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MAX_NUM = 10'000'000;
int N;
string N_str;
int cnt;

void solve_1(){
    for(int num=1; num<=N; ++num){
        int val = num;
        int sum = 0;
        while(val){
            sum += val % 10;
            val /= 10;
        }

        if(num % sum == 0){
            ++cnt;
        }
    }

    cout << cnt << endl;
}

int dp_sum[MAX_NUM + 1];
void solve_DP(){
    for(int num=1; num<=N; ++num){
        dp_sum[num] = dp_sum[num/10] + num%10;

        // if(num % dp_sum[num] == 0){
        //     ++cnt;
        // }

        // NOTE : no conditional branching
        cnt += !(num % dp_sum[num]);
    }

    cout << cnt << endl;
}

void solve(){
    // solve_1();

    solve_DP();

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
