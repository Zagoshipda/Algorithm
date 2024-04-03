/*
    https://www.acmicpc.net/problem/17088
    (sequence to arithmetic)

    solutions
        https://www.acmicpc.net/source/22159987
        (rasauq1122, 12 ms) : using common difference to calculate a[k]

        https://www.acmicpc.net/source/19027751
        (mook0227, 12 ms) : save only previous element and compare it with the current element
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    only 2 operations (+ 1 / - 1)
    3 choices for each element (-1 / 0 / +1)
    but, common difference should be the same to be the arithmetic sequence

    try all => DP ?

    a1 a2 ... aN = a1 + (N-1)d
    possible common difference : d = a1-a2 +- 2
        => 9 cases for (a1, a2) pairs
        => arithmetic sequence is fully determined by the first 2 numbers
        => check the common difference condition satisfies for a3 ... aN

    time complexity
        N ~ 10^5
        => 9 * 10^5 = 10^6

*/

const int ARR_SIZE = 100'000;       // 10^5
const int MAX_NUM = 1'000'000'000;  // 10^9
const int NUM_MOVES = 9;

int N;
int arr_b[ARR_SIZE + 1];
int arr_a[ARR_SIZE + 1];
pair<int, int> moves[NUM_MOVES] = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1}, {0, 0}, {0, 1},
    {1, -1}, {1, 0}, {1, 1},
};

int min_op = (INT_MAX >> 1);
bool is_possible = false;
void solve_1(){
    int common;
    int op;
    for(int ith=0; ith<NUM_MOVES; ++ith){
        // initialize
        for(int idx=1; idx<=N; ++idx){
            arr_a[idx] = arr_b[idx];
        }

        auto [first, second] = moves[ith];
        arr_a[1] = arr_b[1] + first;
        arr_a[2] = arr_b[2] + second;

        common = arr_a[2] - arr_a[1];
        op = abs(first) + abs(second);
        int jdx;
        int diff;
        for(jdx=3; jdx<=N; ++jdx){
            diff = arr_a[jdx] - arr_a[jdx-1];
            if(abs(common - diff) > 1){
                // impossible;
                break;
            }
            if(diff == common + 1){
                arr_a[jdx] -= 1;
                ++op;
            }
            else if(diff == common - 1){
                arr_a[jdx] += 1;
                ++op;
            }
            else{
                // do nothing
            }
        }

        if(jdx > N){
            is_possible = true;
            min_op = min(min_op, op);
        }
    }

    if(is_possible){
        cout << min_op << endl;
    }
    else{
        cout << -1 << endl;
    }
}

void solve_2(){
    int common;
    int op;
    // for(int ith=0; ith<NUM_MOVES; ++ith){
    for(int first=-1; first<=1; ++first){
        for(int second=-1; second<=1; ++second){
            // initialize
            for(int idx=1; idx<=N; ++idx){
                arr_a[idx] = arr_b[idx];
            }

            // auto [first, second] = moves[ith];
            arr_a[1] = arr_b[1] + first;
            arr_a[2] = arr_b[2] + second;

            common = arr_a[2] - arr_a[1];
            op = abs(first) + abs(second);
            int jdx;
            int diff;
            for(jdx=3; jdx<=N; ++jdx){
                diff = arr_a[jdx] - arr_a[jdx-1];
                if(abs(common - diff) > 1){
                    // impossible;
                    break;
                }
                if(diff == common + 1){
                    arr_a[jdx] -= 1;
                    ++op;
                }
                else if(diff == common - 1){
                    arr_a[jdx] += 1;
                    ++op;
                }
                else{
                    // do nothing
                }
            }

            if(jdx > N){
                is_possible = true;
                min_op = min(min_op, op);
            }
        }
    }

    if(is_possible){
        cout << min_op << endl;
    }
    else{
        cout << -1 << endl;
    }
}

void solve(){
    // solve_1();
    solve_2();
}

void input(){
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> arr_b[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
