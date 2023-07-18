/*
    knapsack problem
    https://www.acmicpc.net/problem/12865

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

#define SIZE 100
#define MAX_WEIGHT 100'000
int N, K;
int W, V;   // weight & value
pair<int, int> item[SIZE + 1];

// time exceeded
bool visited[SIZE + 1];
int max_value;
void knapsack_backtracking(int position, int current_value, int weight_left){
    for(int i=position; i<N; ++i){
        if(!visited[i] && weight_left >= item[i].first){
            visited[i] = true;
            weight_left -= item[i].first;
            current_value += item[i].second;
            knapsack_backtracking(i+1, current_value, weight_left);
            visited[i] = false;
            weight_left += item[i].first;
            current_value -= item[i].second;
        }
    }

    max_value = max(max_value, current_value);
}

int dp[SIZE + 1][MAX_WEIGHT + 1];

// dp[M][N] max value at item 1...M, with N [weight left]
void knapsack_DP_prefix_1(){

    for(int i=0; i<N; ++i){
        int weight = item[i].first;
        int value = item[i].second;
        // 1. NOT using i-th item
        for(int weight_left=0; weight_left<=K; ++weight_left){
            dp[i+1][weight_left] = dp[i][weight_left];
        }
        // 2. using i-th item
        for(int weight_left=weight; weight_left<=K; ++weight_left){
            dp[i+1][weight_left-weight] = max(dp[i+1][weight_left-weight], dp[i][weight_left] + value);
        }
    }

    // take maximum value among all possible states
    for(int weight_left=0; weight_left<=K; ++weight_left){
        // max value at item 0...N-1, with m weights left
        max_value = max(max_value, dp[N][weight_left]);
    }

}

// dp[M][N] max value at item 1...M, with N [weight capacity]
void knapsack_DP_prefix_2(){

    for(int weight_left=item[0].first; weight_left<=K; ++weight_left){
        dp[0][weight_left] = item[0].second;
    }

    for(int i=1; i<N; ++i){
        for(int weight_left=0; weight_left<=K; ++weight_left){
            if(weight_left >= item[i].first){
                dp[i][weight_left] = max(dp[i-1][weight_left-item[i].first] + item[i].second, dp[i-1][weight_left]);
            }
            else{
                dp[i][weight_left] = dp[i-1][weight_left];
            }
        }
    }

    max_value = dp[N-1][K]; // max value at item 0...N-1, using K weight capacity
}

// NOTE : optimize space complexity
int dp_opt[MAX_WEIGHT + 1];   // dp[n] : max value at item n
void knapsack_DP_prefix_3(){
    for(int i=0; i<N; ++i){
        // for(int weight_left=0; weight_left<=K; ++weight_left){  // wrong answer
        // for(int weight_left=K; weight_left>=0; --weight_left){  // (12 ms)
        //     if(weight_left >= item[i].first){
        //         dp_opt[weight_left] = max(dp_opt[weight_left], dp_opt[weight_left-item[i].first] + item[i].second);
        //     }
        // }

        // (8 ms)
        for(int weight_left=K; weight_left>= item[i].first; --weight_left){
            dp_opt[weight_left] = max(dp_opt[weight_left], dp_opt[weight_left - item[i].first] + item[i].second);
        }
    }

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

void knapsack_DP_suffix(){

    for(int i=item[N-1].first; i<=K; ++i){
        dp[N-1][i] = item[N-1].second;
    }

    for(int i=N-2; i>=0; --i){
        for(int weight=0; weight<=K; ++weight){
            // 1. can use i-th item, decide whether to use or not
            if(weight - item[i].first >= 0){
                dp[i][weight] = max(dp[i+1][weight - item[i].first] + item[i].second, dp[i+1][weight]);
            }
            // 2. can't using i-th item
            else{
                dp[i][weight] = dp[i+1][weight];
            }
        }
    }

    max_value = dp[0][K];
}

void solve(){

    // knapsack_backtracking(0, 0, K);

    ///////////////////////////////////////////////////////////////

    // knapsack_DP_prefix_1();
    // knapsack_DP_prefix_2();
    knapsack_DP_prefix_3();

    // knapsack_DP_suffix();

    cout << max_value << endl;
}

int main(){
    IOS;

    cin >> N >> K;
    for(int i=0; i<N; ++i){
        cin >> W >> V;
        // item[i].first = W;
        // item[i].second = V;

        for(int weight_left=K; weight_left>=W; --weight_left){
            dp_opt[weight_left] = max(dp_opt[weight_left], dp_opt[weight_left - W] + V);
        }
    }

    cout << dp_opt[K] << endl;

    // solve();

    return 0;
}
