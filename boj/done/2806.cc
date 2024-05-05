/*
    https://www.acmicpc.net/problem/2806
    (DNA)

    solution
        DP
            https://www.acmicpc.net/source/15854251
            (chw0501, 88 ms) : recursive
            https://www.acmicpc.net/source/28196230
            (smkim104, 52 ms) : implemented in solve_dp_1()
            https://www.acmicpc.net/source/33193811
            (asz2325, 8 ms) : 1d-array optimization, implemented in solve_dp_2()

        ad-hoc
            https://www.acmicpc.net/source/69251584
            (measurezero, 8 ms)

            https://www.acmicpc.net/source/7291854
            (beomsun0829, 12 ms)
            https://www.acmicpc.net/source/22110585
            (rubix, 12 ms)

            https://www.acmicpc.net/source/6532982
            (sk7755, 12 ms)
            https://www.acmicpc.net/source/133219
            (uranium235, 12 ms)
            https://www.acmicpc.net/source/22190259
            (YunGoon, 12 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        DNA mutation
        1. changing a single character of the sequence (A -> B or B -> A)
        2. changes a whole prefix[1...K] for K=1...N, replacing all characters in positions with the other character (A -> B or B -> A)
        3. Mutations can occur in any order.
        => Compute the least possible number of mutations that could convert the starting molecule to its end state (containing only A characters)

    Algorithm
        DP ? greedy ?
        prefix ?
        dp[i] : minimum # of mutations to end state for arr[:i]
        for each position k, 2 conversions possible : change arr[k] or prefix[:k]
        if arr[i+1] == 'A'
            dp[i+1] = dp[i] : no need to change
        else
            dp[i+1] = min(dp[i] + 1, reversed dp[i] + 1)
        => need a state to represent the reversed string

16
ABBABABBABAABBAB

// 8

12
ABABABAABBAB

// 6

7
ABBABBA

// 3
// BAABAAB : 3
// BBABB : 2

6
ABBABB

// 3

6
BAABAA

// 2

12
ABBABBABBABB

// 5

9
ABBABBABB

// 4

9
BAABAABAA

// 3

*/

const int ARR_SIZE = 1'000'000; // 10^6
string END_STATE = "A"; // string with only A's

int N;
string state;

string state_1;
string state_2;

int count_transition(string str, char ch){
    int cnt = 0;
    int transitions = 0;
    int len = str.size();
    for(int idx=0; idx<len; ++idx){
        if(str[idx] == ch){
            if(cnt >= 2){
                transitions += 2;
            }
            else if(cnt == 1){
                ++transitions;
            }
            else{
                // do nothing
            }
            cnt = 0;
        }
        else{
            ++cnt;
        }
    }
    transitions += min(cnt, 2);

    return transitions;
}

void solve_greedy(){
    state_1 = state;
    // int pos_1 = N-1;
    // for(int idx=N-1; idx>=0; --idx){
    //     if(state_1[idx] == 'B'){
    //         pos_1 = idx;
    //         break;
    //     }
    // }
    // cout << "   pos_1 : " << pos_1 << endl;

    for(int idx=0; idx<N; ++idx){
        if(state[idx] == 'A'){
            state_2.push_back('B');
        }
        else{
            state_2.push_back('A');
        }
    }

    // int pos_2 = N-1;
    // for(int idx=N-1; idx>=0; --idx){
    //     if(state_2[idx] == 'B'){
    //         pos_2 = idx;
    //         break;
    //     }
    // }
    // cout << "   pos_2 : " << pos_2 << endl;


    // int val_1 = count_transition(state_1.substr(0, pos_1+1), 'A');
    // int val_2 = count_transition(state_2.substr(0, pos_2+1), 'B');
    // cout << min(val_1, val_2 + 1) << endl;

    int val_1 = count_transition(state_1, 'A');
    int val_2 = count_transition(state_2, 'A');
    cout << val_1 << endl;
    cout << val_2 << endl;
    cout << min(val_1, val_2 + 1) << endl;
}

int dp[ARR_SIZE + 1][2];
void solve_dp_1(){
    for(int idx=1; idx<=N; ++idx){
        if(state[idx-1] == 'A'){
            dp[idx][0] = min(dp[idx-1][0], dp[idx-1][1] + 1);
            dp[idx][1] = min(dp[idx-1][0] + 1, dp[idx-1][1] + 1);
        }
        else{
            dp[idx][0] = min(dp[idx-1][0] + 1, dp[idx-1][1] + 1);
            dp[idx][1] = min(dp[idx-1][0] + 1, dp[idx-1][1]);
        }
    }
    cout << min(dp[N][0], dp[N][1] + 1) << endl;
}

void solve_dp_2(){

}

void solve(){
    solve_dp_1();
    // solve_dp_2();

    // solve_greedy();
}

void input(){
    cin >> N;
    cin >> state;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
