/*
    // 1. top down dp (dfs)
    (16ms)
    https://www.acmicpc.net/source/47347793
    (12ms)
    https://www.acmicpc.net/source/47670277

    // 2. bottom up dp
    (16ms)
    https://www.acmicpc.net/source/37549672

    // NOT reviewed yet
    (12ms)
    https://www.acmicpc.net/source/44786165
    (8ms)
    https://www.acmicpc.net/source/52487301

    (16ms)
    https://www.acmicpc.net/source/28375440

    (4ms)
    https://www.acmicpc.net/source/44749425
    (4ms)
    https://www.acmicpc.net/source/25712743

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

// #define SIZE 17 // 32ms
#define SIZE 16 // 24ms ~ 32ms
#define MAX_COST 1'000'000
#define CANT_MOVE 0
// #define DP_MAX_VALUE INT_MAX-(MAX_COST*SIZE)
#define DP_MAX_VALUE (MAX_COST*100)
// #define DP_INITIAL_VALUE -1
#define START_CITY 0
#define START_BIT (1<<START_CITY)
int N;
int cost[SIZE][SIZE];
int dp[SIZE][1<<SIZE];

// timeout
// int solve_traveling_salesman_problem(int city, int bit){
//     if(bit == (1<<N+1)-2){
//         if(cost[city][START_CITY] != 0){
//             return cost[city][START_CITY];
//         }
//         else{
//             return MAX_VALUE;
//         }
//     }

//     if(dp[city][bit] < MAX_VALUE){
//         return dp[city][bit];
//     }

//     for(int next=1; next<=N; ++next){
//         if(!(bit>>next & 1)){
//             if(cost[city][next] > 0){
//                 dp[city][bit] = min(dp[city][bit], solve_traveling_salesman_problem(next, bit | 1<<next) + cost[city][next]);
//             }
//         }
//     }

//     return dp[city][bit];
// }

int solve_traveling_salesman_problem_dfs(int city, int bit){
    // if(bit == (1<<N+1)-2){
    if(bit == (1<<N)-1){
        // if(cost[city][START_CITY] != CANT_MOVE){
        //     return cost[city][START_CITY];
        // }
        // else{
        //     return DP_MAX_VALUE;
        // }
        return cost[city][START_CITY] == CANT_MOVE ? DP_MAX_VALUE : cost[city][START_CITY];
    }

    // if(dp[city][bit] != DP_INITIAL_VALUE){
    if(dp[city][bit] != 0){
        return dp[city][bit];
    }

    // NOTE : minimize the number of access to the array
    // dp[city][bit] = DP_MAX_VALUE;
    int val = DP_MAX_VALUE;
    // for(int next=1; next<=N; ++next){
    for(int next=0; next<N; ++next){
        if(!(bit>>next & 1) && cost[city][next] != CANT_MOVE){
            val = min(val, solve_traveling_salesman_problem_dfs(next, bit | 1<<next) + cost[city][next]);
            // dp[city][bit] = min(dp[city][bit], solve_traveling_salesman_problem(next, bit | 1<<next) + cost[city][next]);
        }
    }

    return dp[city][bit] = val;
}

// void initialize_dfs(){
//     for(int i=0; i<N; ++i){
//         for(int j=0; j<(1<<N); ++j){
//             dp[i][j] = DP_INITIAL_VALUE;
//         }
//     }
//     // memset(dp, INITIAL_VALUE, sizeof(dp));
// }

void initialize(){
    // wrong
    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<(1<<N); ++j){
    //         // if(j == i){
    //         if(j == 0){
    //             dp[i][j] = 0;
    //         }
    //         else{
    //             dp[i][j] = DP_MAX_VALUE;
    //         }
    //     }
    // }

    for(int i=0; i<N; ++i){
        for(int j=0; j<(1<<N); ++j){
            dp[i][j] = DP_MAX_VALUE;
        }
    }
    dp[0][0] = 0;
}

int solve_traveling_salesman_problem(){

    for(int bit=0; bit<(1<<N)-1; ++bit){
        for(int current=0; current<N; ++current){
            for(int next=0; next<N; ++next){
            // for(int bit=0; bit<(1<<N); ++bit){  // wrong
                // connected && not visited yet
                if(cost[current][next] != 0 && !(bit>>next & 1)){
                    dp[next][bit | 1<<next] = min(dp[next][bit | 1<<next], dp[current][bit] + cost[current][next]);
                }
            }
        }
    }

    // return dp[1][(1<<N)-1];  // wrong
    return dp[0][(1<<N)-1];
}

int main(){
    IOS;

    cin >> N;
    // for(int i=1; i<=N; ++i){
    //     for(int j=1; j<=N; ++j){
    //         cin >> cost[i][j];
    //     }
    // }
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin >> cost[i][j];
        }
    }

    // initialize_dfs();
    initialize();

    // cout << solve_traveling_salesman_problem_dfs(START_CITY, START_BIT) << endl;
    cout << solve_traveling_salesman_problem() << endl;

    return 0;
}
