#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 21
#define BIT 1<<21
int N;
int cost[SIZE][SIZE];   // cost[m][n] : mth person do nth work

int dp[SIZE][BIT];  // nth work, done with bit-masked people
int dp2[BIT];       // done with bit-masked people

// bfs, without memoization
// bfs : finish first [from the beginning]
int minimum_cost = INT_MAX;
void calculate_minimum_cost_timeout(int pos, int bit, int value){
    if(pos > N){
        minimum_cost = min(minimum_cost, value);
    }

    for(int person=1; person<=N; ++person){
        if(!(1<<person & bit)){
            int next_bit = 1<<person | bit;
            int next_value = value + cost[person][pos];
            if(next_value < dp[pos][next_bit]){
                dp[pos][next_bit] = next_value;
                calculate_minimum_cost_timeout(pos+1, next_bit, next_value);
            }
        }
    }
}

// dfs, with memoization
// dfs : finish first [at the end]
// dp[n][bit] : nth work, done with bit-masked people, depends on dp[n+1][next_bit]
int calculate_minimum_cost_dfs(int pos, int bit){
    if(pos > N){
        return 0;
    }

    if(dp[pos][bit] < INT_MAX){
        return dp[pos][bit];
    }

    for(int person=1; person<=N; ++person){
        if(!(1<<person & bit)){
            dp[pos][bit] = min(dp[pos][bit], calculate_minimum_cost_dfs(pos+1, 1<<person | bit) + cost[person][pos]);
        }
    }

    return dp[pos][bit];
}

// dp[bit] : (any work) done with bit-masked people, depends on dp[next_bit]

int calculate_minimum_cost_dfs2(int pos, int bit){
    if(pos > N){
        return 0;
    }

    if(dp2[bit] < INT_MAX){
        return dp2[bit];
    }

    // int work = 0;
    // for(int pos=1; pos<=N; ++pos){
    //     if(bit>>pos & 1){
    //         ++work;
    //     }
    // }

    for(int person=1; person<=N; ++person){
        if(!(1<<person & bit)){
            dp2[bit] = min(dp2[bit], calculate_minimum_cost_dfs2(pos+1, 1<<person | bit) + cost[person][pos]);
        }
    }

    return dp2[bit];
}

void initialize(){
    // for(int i=0; i<21; ++i){
    //     for(int j=0; j<BIT; ++j){
    //         dp[i][j] = INT_MAX;
    //     }
    // }
    // // only for dp
    // for(int bit=0; bit<BIT; ++bit){
    //     dp[0][bit] = 0;
    // }



    for(int bit=0; bit<BIT; ++bit){
        dp2[bit] = INT_MAX;
    }
    // only for dp
    // dp2[0] = 0;
}

void calculate_minimum_cost_dp(){

    // // timeout
    // for(int bit=0; bit<BIT; ++bit){
    //     for(int work=1; work<=N; ++work){
    //         for(int person=1; person<=N; ++person){
    //             if(!(1<<person & bit)){
    //                 dp[work][1<<person | bit] = min(dp[work][1<<person | bit], dp[work-1][bit] + cost[person][work]);
    //             }
    //         }
    //     }
    // }

    // // this passes...! (just by changing the loop order)
    // for(int work=1; work<=N; ++work){
    //     for(int person=1; person<=N; ++person){
    //         // for(int bit=0; bit<BIT; ++bit){
    //         for(int bit=0; bit<(1<<N+1); ++bit){    // a little bit faster with appropriate dimension
    //             if(!(1<<person & bit)){
    //                 dp[work][1<<person | bit] = min(dp[work][1<<person | bit], dp[work-1][bit] + cost[person][work]);
    //             }
    //         }
    //     }
    // }


    // // preprocessing with bit shifting
    // // cout << bitset<32>(BIT-1) << endl;   // 0100000000000000000000 (doubles)
    // // cout << bitset<32>(BIT) << endl;     // 1000000000000000000000
    // // cout << (BIT-1) << endl; // 1048576 (doubles)
    // // cout << (BIT) << endl;   // 2097152
    // // cout << (BIT)-1 << endl; // 2097151

    // // cout << dp[N][(BIT)-1] << endl;
    // // cout << dp[N][(1<<N+1)-1] << endl;
    // cout << dp[N][(1<<N+1)-2] << endl;



    // 1-dim array 3 times faster than above
    // for(int bit=0; bit<BIT; ++bit){
    for(int bit=0; bit<(1<<N+1); ++bit){
        int work = 0;
        for(int pos=1; pos<=N; ++pos){
            if(bit>>pos & 1){
            // if(bit & 1<<pos){
                ++work;
            }
        }
        for(int person=1; person<=N; ++person){
            if(!(1<<person & bit) /* && work<N */){
                // dp[work][1<<person | bit] = min(dp[work][1<<person | bit], dp[work-1][bit] + cost[person][work]);
                // cout << bitset<8>(1<<person | bit) << endl;
                dp2[1<<person | bit] = min(dp2[1<<person | bit], dp2[bit] + cost[person][work+1]);
            }
        }
    }

    // cout << dp2[(BIT)-1] << endl;
    // cout << dp2[(1<<N+1)-1] << endl;
    cout << dp2[(1<<N+1)-2] << endl;
}

int main(){
    IOS;

    cin >> N;
    for(int person=1; person<=N; ++person){
        for(int work=1; work<=N; ++work){
            cin >> cost[person][work];
        }
    }

    initialize();

    // calculate_minimum_cost_dp();

    // calculate_minimum_cost_dfs(1, 0);
    // cout << dp[1][0] << endl;

    calculate_minimum_cost_dfs2(1, 0);
    cout << dp2[0] << endl;

    return 0;
}
