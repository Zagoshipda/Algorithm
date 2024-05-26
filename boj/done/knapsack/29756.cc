/*
    https://www.acmicpc.net/problem/29756
    (DDR)

    solution
        implemented in solve_dp_4()
            https://www.acmicpc.net/source/66694976
            (dbrua1222, 0 ms)
            https://www.acmicpc.net/source/66694680
            (blast, 4 ms)
            https://www.acmicpc.net/source/67756529
            (hibye1217, 0 ms)

        implemented in solve_dp_1()
            https://www.acmicpc.net/source/77822482
            (pcmaster0228, 128 ms)
            https://www.acmicpc.net/source/66696280
            (clrmt, 0 ms)
            https://www.acmicpc.net/source/66697247
            (hithere314, 0 ms)

        recursive solution : implemented in solve_recursive()
            https://www.acmicpc.net/source/67113797
            (imax, 0 ms)
            https://www.acmicpc.net/source/71596924
            (gazebo1, 0 ms)
            https://www.acmicpc.net/source/66695021
            (newb, 0 ms)
            https://www.acmicpc.net/source/66693820
            (hyperbolic, 0 ms)

        https://www.acmicpc.net/source/66695239
        (asp1939, 180 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        - (0-1 knapsack) can choose to play certain part or NOT
        - initial health = 100
        - recovery K before each part, regardless of play or not
        - (upper bound) health + K <= 100 : always adjust to maximum 100
        - (lower bound) 0 <= health + K - part[i].health : give up part with bigger health requirement
        => calculate the maximum sum of scores

    Algorithm
        DP
            just simulate ?
            how to represent each state ?
            => maximum health 100
        S ubproblem
            prefix
            dp[i][k] : max score from part[:i] with health k
            2 choices : use part[i] or not
                use part[i] : (min(100 + K, 100) - part[1].health, part[1].score)
                not use part[i] : (min(100 + K, 100), 0)

            (subproblem constraint / expansion)
                what is the last use ? or what is the next use ?
                    dp[j][k] : max score of part[:j], starting with health k
                suppose not choose i...j-1
                index  i  ... j-1 j
                health x+K        x+K*(j-i+1) - part[j].health
                score  y          y + part[j].score

                dp[j][k] = max(
                    dp[j][k],
                    dp[i][k] + part[j].score
                )

        R ecurrence relation
        T opological order
        B ase case
        O riginal problem
        T ime complexity
            O(N) * O(10^4)

5 10
70 90 80 100 60
60 60 60 60 60

// 190

*/

const int NUM_PART = 1'000;     // 10^3
const int MAX_SCORE = 1'000;    // 10^3
const int MAX_HEALTH = 100;     // 10^2
const int MAX_RECOVERY = 10;    // 10^1
const int INITIAL_HEALTH = 100;

int N, K;
struct Part{
    int score;
    int health;
};

Part parts[NUM_PART + 1];

int dp[INITIAL_HEALTH + 1];
int dp_2[NUM_PART + 2][INITIAL_HEALTH + 1];

void solve_dp_1(){
    // TODO

    // for(int i=1; i<MAX_HEALTH; ++i){
    //     dp[i] = -1;
    // }

    int curr_health;
    int next_health;
    // NOTE : suffix
    for(int idx=N; idx>=1; --idx){                          // O(N) ~ O(10^3)
    // for(int idx=1; idx<=N; ++idx){                          // O(N) ~ O(10^3)
        // not using parts[idx]
        // for(int health=MAX_HEALTH-K; health>=0; --health){
        for(int health=MAX_HEALTH; health>=0; --health){
        // for(int health=0; health+K<=MAX_HEALTH; ++health){
            curr_health = min(MAX_HEALTH, health + K);
            dp[curr_health] = max({
                dp[curr_health],
                // dp[min(MAX_HEALTH, curr_health + K)],
                dp[health],
            });
        }

        // using parts[idx]
        // for(int health=MAX_HEALTH; min(MAX_HEALTH, health + K)>=parts[idx].health && min(MAX_HEALTH, health + K) - parts[idx].health + K<=MAX_HEALTH; --health){
        // health + K - parts[idx].health + K = MAX_HEALTH
        // for(int health=parts[idx].health-K; health<=MAX_HEALTH; ++health){
        for(int health=parts[idx].health; health<=MAX_HEALTH; ++health){
        // for(int health=parts[idx].health-K;
        //     min(MAX_HEALTH, health + K) >= parts[idx].health
        //     /* && min(MAX_HEALTH, health + K) - parts[idx].health + K<=MAX_HEALTH */;
        //     ++health){

            dp[health - parts[idx].health] = max({
                dp[health - parts[idx].health],
                dp[health] + parts[idx].score,
            });

            // curr_health = min(MAX_HEALTH, health + K);
            // next_health = min(MAX_HEALTH, curr_health - parts[idx].health + K);
            // dp[curr_health] = max({
            //     dp[curr_health],
            //     dp[next_health] + parts[idx].score,
            // });
            // // if(next_health == MAX_HEALTH){
            // if(next_health == curr_health){
            //     break;
            // }
        }



        // for(int health=MAX_HEALTH; health>=0; --health){    // O(10^2)
        //     curr_health = min(MAX_HEALTH, health + K);

        //     // 2. using parts[idx]
        //     if(curr_health >= parts[idx].health){
        //         next_health = max(MAX_HEALTH, curr_health - parts[idx].health + K);
        //         dp[next_health] = max({
        //             dp[next_health],
        //             dp[curr_health] + parts[idx].score,
        //         });
        //     }

        //     // 1. NOT using parts[idx]
        //     dp[curr_health] = max({
        //         dp[curr_health],
        //         dp[min(MAX_HEALTH, curr_health + K)],
        //     });

        //     // 2. using parts[idx]
        //     // if(curr_health >= parts[idx].health){
        //     //     next_health = min(MAX_HEALTH, curr_health - parts[idx].health + K);
        //     //     dp[next_health] = max({
        //     //         dp[next_health],
        //     //         // dp[curr_health] + parts[idx].score,
        //     //         dp[health] + parts[idx].score,
        //     //     });
        //     //     // dp[curr_health] = max({
        //     //     //     dp[curr_health],
        //     //     //     dp[next_health] + parts[idx].score,
        //     //     // });

        //     //     // for(int next=N; next>=idx; --next){         // O(N) ~ O(10^3)
        //     //     // // for(int next=idx; next<=N; ++next){         // O(N) ~ O(10^3)
        //     //     //     next_health = min({
        //     //     //         MAX_HEALTH,
        //     //     //         curr_health - parts[idx].health + K * (next - idx),
        //     //     //     });
        //     //     //     dp[curr_health] = max({
        //     //     //         dp[curr_health],
        //     //     //         dp[next_health] + parts[idx].score,
        //     //     //     });
        //     //     // }
        //     // }
        // }
    }

    // cout << dp[INITIAL_HEALTH] << endl;
    cout << *max_element(dp+1, dp+1+MAX_HEALTH) << endl;
}

void solve_dp_2(){
    int curr_health;
    int next_health;
    // NOTE : suffix
    for(int idx=N; idx>=1; --idx){                          // O(N) ~ O(10^3)
        for(int health=MAX_HEALTH; health>=0; --health){    // O(10^2)
            curr_health = min(MAX_HEALTH, health + K);
            // 1. NOT using parts[idx]
            // dp_2[idx][curr_health] = dp_2[idx+1][curr_health];
            dp_2[idx][curr_health] = dp_2[idx+1][min(MAX_HEALTH, curr_health + K)];

            // 2. using parts[idx]
            if(curr_health >= parts[idx].health){
                // for(int next=N; next>idx; --next){         // WRONG
                for(int next=N; next>=idx; --next){         // O(N) ~ O(10^3)
                // NOTE : if next = idx, itself is the last part being used
                    next_health = min({
                        MAX_HEALTH,
                        curr_health - parts[idx].health + K * (next - idx),
                    });
                    dp_2[idx][curr_health] = max({
                        dp_2[idx][curr_health],
                        dp_2[next][next_health] + parts[idx].score,
                    });
                }
            }
        }
    }

    cout << dp_2[1][INITIAL_HEALTH] << endl;
}

void solve_dp_3(){
    int curr_health;
    int next_health;
    for(int idx=N; idx>=1; --idx){
        for(int health=MAX_HEALTH; health>=0; --health){
            curr_health = min(MAX_HEALTH, health + K);
            // dp_2[idx][curr_health] = dp_2[idx+1][curr_health];  // WRONG
            dp_2[idx][curr_health] = dp_2[idx+1][min(MAX_HEALTH, curr_health + K)];    // AC
            if(curr_health >= parts[idx].health){
                next_health = min(MAX_HEALTH, curr_health - parts[idx].health + K);
                dp_2[idx][curr_health] = max({
                    dp_2[idx][curr_health],
                    dp_2[idx+1][next_health] + parts[idx].score,
                });
            }
        }
    }

    cout << dp_2[1][INITIAL_HEALTH] << endl;
}

void solve_dp_4(){

}

int recurse(int ith, int hp){
    if(ith > N){
        return 0;
    }

    if(dp_2[ith][hp]){
        return dp_2[ith][hp];
    }

    int new_hp = min(MAX_HEALTH, hp + K);
    dp_2[ith][hp] = recurse(ith+1, new_hp);

    if(new_hp >= parts[ith].health){
        dp_2[ith][hp] = max({
            dp_2[ith][hp],
            recurse(ith+1, new_hp - parts[ith].health) + parts[ith].score,
        });
    }

    return dp_2[ith][hp];
}

void solve_recursive(){
    cout << recurse(1, INITIAL_HEALTH) << endl;
}

void solve(){
    // TODO
        // solve_dp_1();

    // AC
    // solve_dp_2();
    // solve_dp_3();

    solve_recursive();
}

void input(){
    cin >> N >> K;
    for(int i=1; i<=N; ++i){
        cin >> parts[i].score;
    }
    for(int i=1; i<=N; ++i){
        cin >> parts[i].health;
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
