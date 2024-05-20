/*
    https://www.acmicpc.net/problem/23061
    (travel plan)

    solution
        DP on values, implemented in solve_dp_value()
            https://www.acmicpc.net/source/33555574
            (n99joon, 20 ms) : 1d-array
            https://www.acmicpc.net/source/37546820
            (yuja, 60 ms) : 2d-array
            https://www.acmicpc.net/source/33767961
            (p_ce1052, 16 ms) : not using double, b/a < d/c <=> bc < ad
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

2 2
3 4
5 9
2 4

// 2 (O)
// 1 (X)

*/

const int NUM_OBJECT = 100;         // 10^2
const int NUM_BAG = 100;            // 10^2
const int MAX_WEIGHT = 100'000;     // 10^5
const int MAX_VALUE = 1'000;        // 10^3
const int MAX_SUM_WEIGHT = NUM_BAG * MAX_WEIGHT;    // 10^7
const int MAX_SUM_VALUE = NUM_BAG * MAX_VALUE;  // 10^5
const int MAX_CAPACITY = 1'000'000;   // 10^6

int N, M;

struct Object{
    int weight;
    int value;
};

Object objects[NUM_OBJECT + 1];
int bags_arr[NUM_BAG + 1];
// double ratios[NUM_BAG + 1];

int dp[NUM_BAG + 1][MAX_CAPACITY + 1];
void solve_dp_time_exceeded(){
    double max_ratio = 0.0;
    int pos = -1;
    double ratio;
    for(int idx=1; idx<=M; ++idx){      // O(M) ~ O(10^2)
        for(int jdx=1; jdx<=N; ++jdx){  // O(N) ~ O(10^2)
            for(int capacity=bags_arr[idx]; capacity>=objects[jdx].weight; --capacity){     // O(K) ~ O(10^6)
                dp[idx][capacity] = max({
                    dp[idx][capacity],
                    dp[idx][capacity - objects[jdx].weight] + objects[jdx].value,
                });
            }
        }
        ratio = static_cast<double>(dp[idx][bags_arr[idx]]) / bags_arr[idx];
        if(max_ratio < ratio){
            max_ratio = ratio;
            pos = idx;
        }
    }
    cout << pos << endl;
}

int dp_2[MAX_CAPACITY + 1];     // dp_2[k] : max value with capacity k
void solve_dp_weight(){
    int max_bag = *max_element(bags_arr+1, bags_arr+1+M);
    // int min_bag = *min_element(bags_arr+1, bags_arr+1+M);
    for(int jdx=1; jdx<=N; ++jdx){
        for(int capacity=max_bag; capacity>=objects[jdx].weight; --capacity){
            dp_2[capacity] = max({
                dp_2[capacity],
                dp_2[capacity - objects[jdx].weight] + objects[jdx].value,
            });
        }
    }

    double max_ratio = 0.0;
    double ratio;
    int pos = 1;
    for(int idx=1; idx<=M; ++idx){
        ratio = static_cast<double>(dp_2[bags_arr[idx]]) / bags_arr[idx];
        if(max_ratio < ratio){
            max_ratio = ratio;
            pos = idx;
        }
    }
    cout << pos << endl;
}

int sum_weight;
int sum_value;
int dp_3[MAX_SUM_VALUE + 1];    // dp_3[k] : min weight for value k
void solve_dp_value(){
    // initialize
    for(int value=1; value<=sum_value; ++value){
        dp_3[value] = sum_weight + 1;
    }

    // DP
    for(int idx=1; idx<=N; ++idx){
        for(int value=sum_value; value>=objects[idx].value; --value){
            dp_3[value] = min({
                dp_3[value],
                dp_3[value - objects[idx].value] + objects[idx].weight,
            });
        }
    }

    // find maximum (efficiency / ratio)
    int pos = 1;
    double max_ratio = 0.0;
    double ratio;
    for(int idx=1; idx<=M; ++idx){
        for(int value=0; value<=sum_value; ++value){
            // if(dp_3[value] == bags_arr[idx]){
                // WRONG : sum of weights can NOT be the same as the capacity of bags[idx]
                // i.e. bags[idx] may not be full
            if(dp_3[value] <= bags_arr[idx]){   // AC
                // ratio = static_cast<double>(value) / dp_3[value];
                ratio = static_cast<double>(value) / bags_arr[idx];
                if(max_ratio < ratio){
                    max_ratio = ratio;
                    pos = idx;
                }
                // break;
            }
        }
    }

    cout << pos << endl;
}

void solve(){
    // solve_dp_time_exceeded();

    // solve_dp_weight();   // 100 ms
    solve_dp_value();   // 20 ms
}

void input(){
    cin >> N >> M;
    for(int i=1; i<=N; ++i){
        cin >> objects[i].weight >> objects[i].value;
        sum_weight += objects[i].weight;
        sum_value += objects[i].value;
    }
    for(int i=1; i<=M; ++i){
        cin >> bags_arr[i];
    }
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
