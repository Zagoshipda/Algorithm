/*
    https://www.acmicpc.net/problem/12865
    (knapsack problem 1)
        NOTE : here, all values integer
        what happens when weights or values are real-numbers ?
        time complexity O(N K) is pseudo-polynomial,
        => depends on the size of the input,
        and the numbers(numeric value) in the inputs (here, the size of the knapsack)
        therefore the time complexity may depend on the input type (integer or not)

    similar problem
        https://www.acmicpc.net/problem/12920
        (knapsack problem 2) : can pick object multiple times

    solution
        optimizing space complexity
        https://www.acmicpc.net/source/22254620 (12 ms)
        https://www.acmicpc.net/source/23753141 (12 ms)
        https://www.acmicpc.net/source/30163906 (8 ms)
        https://www.acmicpc.net/source/13130759 (4 ms)
        https://www.acmicpc.net/source/30741285 (4 ms)

    references
        https://gsmesie692.tistory.com/113
        https://jeonyeohun.tistory.com/86
        https://steadev.tistory.com/33
        https://rujang.tistory.com/entry/%EB%B0%B1%EC%A4%80-12865%EB%B2%88-%ED%8F%89%EB%B2%94%ED%95%9C-%EB%B0%B0%EB%82%AD-CC

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

const int SIZE = 100;           // 10^2
const int MAX_WEIGHT = 100'000; // 10^5
const int MAX_VALUE = 1'000;    // 10^3
int N, K;
int W, V;
pair<int, int> item[SIZE + 1];  // (weight, value)

// time exceeded
bool visited[SIZE + 1];
int max_value;
void backtracking_time_exceeded(int position, int current_value, int weight_left){
    // if(position >= N){   // WRONG
        max_value = max(max_value, current_value);
    //     return;
    // }

    for(int i=position; i<N; ++i){
        if(!visited[i] && weight_left >= item[i].first){
            visited[i] = true;
            weight_left -= item[i].first;
            current_value += item[i].second;
            backtracking_time_exceeded(i+1, current_value, weight_left);
            visited[i] = false;
            weight_left += item[i].first;
            current_value -= item[i].second;
        }
    }
}

int dp[SIZE + 2][MAX_WEIGHT + 1];

// dp[M+1][N] max value at item 1...M, with [N weight left]
void knapsack_DP_prefix_1(){

    for(int i=0; i<N; ++i){
        int weight = item[i].first;
        int value = item[i].second;
        // 1. NOT using i-th item
        // NOTE : initialization starts from 0
        for(int weight_left=0; weight_left<=K; ++weight_left){
            dp[i+1][weight_left] = dp[i][weight_left];
        }
        // 2. using i-th item
        for(int weight_left=weight; weight_left<=K; ++weight_left){
            dp[i+1][weight_left - weight] = max(
                dp[i+1][weight_left - weight],
                dp[i][weight_left] + value
            );
        }
    }

    // take maximum value among all possible states
    for(int weight_left=0; weight_left<=K; ++weight_left){
        // max value at item 0...N-1, with m weights left
        // NOTE : index here at N
        max_value = max(max_value, dp[N][weight_left]);
    }

}

// dp[M][N] max value at item 1...M, with [N weight capacity]
void knapsack_DP_prefix_2(){
    // NOTE : initialization starts from item[0].weight to full capacity K
    for(int capacity=item[0].first; capacity<=K; ++capacity){
        dp[0][capacity] = item[0].second;
    }

    for(int i=1; i<N; ++i){
        for(int capacity=0; capacity<=K; ++capacity){
            if(capacity >= item[i].first){
                dp[i][capacity] = max(
                    dp[i-1][capacity - item[i].first] + item[i].second,
                    dp[i-1][capacity]
                );
            }
            else{
                dp[i][capacity] = dp[i-1][capacity];
            }
        }
    }

    max_value = dp[N-1][K]; // max value at item 0...N-1, using K weight capacity
}

// NOTE : optimize space complexity, dp on [possible weight value space]
int dp_opt[MAX_WEIGHT + 1];   // dp[n] : max value at item n
void knapsack_DP_prefix_3(){
    for(int i=0; i<N; ++i){
        // // for(int weight_left=0; weight_left<=K; ++weight_left){  // wrong answer
        // for(int weight_left=K; weight_left>=0; --weight_left){  // (12 ms)
        //     if(weight_left >= item[i].first){
        //         dp_opt[weight_left] = max(
        //             dp_opt[weight_left],
        //             dp_opt[weight_left - item[i].first] + item[i].second
        //         );
        //     }
        // }

        // (8 ms)
        for(int capacity=K; capacity>=item[i].first; --capacity){
            dp_opt[capacity] = max(
                dp_opt[capacity],
                dp_opt[capacity - item[i].first] + item[i].second
            );
        }
    }

    // original problem
    max_value = dp_opt[K];
}

// NOTE : dp[M][N] max-value at item M, with N capacity
// dp[i][weight_left] = max(
//     // 1. if we take i-th item, then for i+1-th item we have
//         // (weight_left - item[i].weight) capacity left,
//         // with value increased by item[i].value
//     dp[i+1][weight_left - item[i].weight] + item[i].value,
//     // 2. if we do not take i-th item, then we have same max-value as i+1-th item
//     dp[i+1][weight_left]
// )

void knapsack_dp_suffix_1(){

    for(int capacity=item[N-1].first; capacity<=K; ++capacity){
        dp[N-1][capacity] = item[N-1].second;
    }

    for(int i=N-2; i>=0; --i){
        for(int capacity=0; capacity<=K; ++capacity){
            // 1. can use i-th item, decide whether to use or not
            if(capacity >= item[i].first){
                dp[i][capacity] = max(
                    dp[i+1][capacity - item[i].first] + item[i].second,
                    dp[i+1][capacity]
                );
            }
            // 2. can't using i-th item
            else{
                dp[i][capacity] = dp[i+1][capacity];
            }
        }
    }

    // original problem
    max_value = dp[0][K];
}

/*
4 10
3 6
3 6
8 20
3 9

// 21 (O)
// 20 (X)

*/
void knapsack_dp_suffix_2(){
    for(int idx=N-1; idx>=0; --idx){
        // // WRONG
        // for(int capacity=item[idx].first; capacity<=K; ++capacity){
        //     dp[idx][capacity] = max({
        //         dp[idx+1][capacity],
        //         dp[idx+1][capacity - item[idx].first] + item[idx].second,
        //     });
        // }

        for(int capacity=0; capacity<=K; ++capacity){
            // NOTE : initialization necessary
            dp[idx][capacity] = dp[idx+1][capacity];

            if(item[idx].first <= capacity){
                dp[idx][capacity] = max({
                    dp[idx][capacity],
                    dp[idx+1][capacity - item[idx].first] + item[idx].second,
                });
            }
        }
    }

    max_value = dp[0][K];
}

/*
    WANT : maximum sum of values with fixed (integer) capacity
    S ubproblem
        if take i-th item,
            value += item[i].value
            capacity -= item[i].weight

        each array dimension represents some information about the problem
        (think n-dimensional array as n-dimensional matrix or cube)
        dp[i][x] : sum of values [AFTER] handling (1...i)-th item with capacity x left

    R ecurrence relation
        choice : choose i-th item or not
        prefix : we choose from 1...i-th item (left with i+1...n-th item)

        2 possibilities : whether there is enough capacity for i-th item or not
        i.e. we can take i-th item or not

        when we can take i-th item
        and if (weight_left + i-th weight) does not exceed the capacity K
        if(weight_left+item[i].weight <= K){
            dp[i][weight_left] = max(
                dp[i-1][weight_left+item[i].weight] + item[i].value,
                dp[i-1][weight_left]
            )
        }
        when we can't take i-th item
        else{
            dp[i][weight_left] = dp[i-1][weight_left]
        }

    T opological order
        think of DP as [local brute force]
        for(int ith=1; ith<=N; ++ith){
            for(int capacity=0...K){    // NOTE : capacity can start from 0
                do recurrence relation above
                    if(capacity+item[ith].weight <= K){
                        dp[ith][capacity] = max(
                            dp[ith-1][capacity+item[ith].weight] + item[ith].value,
                            dp[ith-1][capacity]
                        )
                    }
                    else{
                        dp[ith][capacity] = dp[ith-1][capacity]
                    }
            }
        }

    B ase case
        assume handlihng 0-th item with all capacities to be value of 0
        (not taking any item yet)
        for(int capacity=0...K){
            dp[0][capacity] = 0;
        }

    O riginal problem
        maximum sum of values
        max(dp[N][i] for i=0...K)

    T ime complexity
*/

void knapsack_prefix(){
    // for(int weight_left=0; weight_left<=K-item[0].first; ++weight_left){
    for(int weight_left=0; weight_left+item[0].first<=K; ++weight_left){
        dp[0][weight_left] = item[0].second;
    }

    // NOTE : item index starts from 0
    for(int ith=1; ith<N; ++ith){
        for(int weight_left=0; weight_left<=K; ++weight_left){
            if(weight_left + item[ith].first <= K){
                dp[ith][weight_left] = max(
                    dp[ith-1][weight_left + item[ith].first] + item[ith].second,
                    dp[ith-1][weight_left]
                );
            }
            else{
                dp[ith][weight_left] = dp[ith-1][weight_left];
            }
        }
    }

    for(int weight_left=0; weight_left<=K; ++weight_left){
        max_value = max(max_value, dp[N-1][weight_left]);
    }
}

void solve(){
    // backtracking_time_exceeded(0, 0, K);

    ///////////////////////////////////////////////////////////////

    // knapsack_DP_prefix_1();
    // knapsack_DP_prefix_2();
    // knapsack_DP_prefix_3();

    // knapsack_dp_suffix_1();
    knapsack_dp_suffix_2();

    // knapsack_prefix();

    cout << max_value << endl;
}

int main(){
    IOS;

    cin >> N >> K;
    for(int i=0; i<N; ++i){
        cin >> W >> V;
        item[i].first = W;
        item[i].second = V;

        // space-optimized dp, direct to input
        // for(int capacity=K; capacity>=W; --capacity){
        //     dp_opt[capacity] = max(dp_opt[capacity], dp_opt[capacity - W] + V);
        // }
    }

    // cout << dp_opt[K] << endl;

    solve();

    return 0;
}
