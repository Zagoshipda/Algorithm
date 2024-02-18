/*
    https://www.acmicpc.net/problem/14501
    (retirement)

    solutions
        DP
            O(N^2)
                https://www.acmicpc.net/source/16819863
                (dyk777, 0 ms) : implemented in solve_dp_1()
                https://www.acmicpc.net/source/15919431
                (dajinstory, 0 ms) : implemented in solve_dp_2()

            O(N)
            implemented in solve_dp_3()
                https://www.acmicpc.net/source/16563720
                (juhyuck0103, 0 ms)
                https://www.acmicpc.net/source/17092882
                (hansc0320, 0 ms)

            suffix, implemented in solve_dp_suffix()
                https://www.acmicpc.net/source/16366699
                (fineday9, 0 ms)

            prefix, NOT implemented in solve_dp_prefix()

        backtracking
            recursion on 2 branches, implemented in backtracking_2()
                https://www.acmicpc.net/source/16198277
                (shinkscon, 0 ms)
                https://www.acmicpc.net/source/17521858
                (dr_al, 0 ms)

            recursion on 2 branches, implemented in backtracking_3()
                https://www.acmicpc.net/source/16808010
                (6_6, 0 ms)
                https://www.acmicpc.net/source/17278053
                (qsewill4569, 0 ms)


        brute force

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    N ~ 15
    brute force = O(2^15) = O(10^3 * 2^5) = O(10^5)

*/

const int MAX_DAY = 15;
int N;
int T, P;
pair<int, int> counsels[MAX_DAY + 2];   // (days, reward)
int dp[MAX_DAY + 1];

void solve_dp_1(){
    for(int end_day=1; end_day<=N; ++end_day){
        for(int day=1; day<=end_day; ++day){
            if(day + (counsels[day].first-1) <= end_day){
                dp[end_day] = max({
                    dp[end_day],
                    dp[day-1] + counsels[day].second,
                });
            }
        }
    }

    cout << dp[N] << endl;
}

void solve_dp_2(){
    for(int start_day=1; start_day<=N; ++start_day){
        for(int end_day=start_day + (counsels[start_day].first-1); end_day<=N; ++end_day){
            dp[end_day] = max({
                dp[end_day],
                dp[start_day-1] + counsels[start_day].second,
            });
        }
    }

    cout << dp[N] << endl;
}

void solve_dp_3(){
    for(int day=1; day<=N; ++day){
        // dp[day] = max(dp[day], dp[day-1]);
        dp[day] = dp[day-1];

        int finish_day = day + (counsels[day].first-1);
        if(finish_day <= N){
            dp[finish_day] = max({
                dp[finish_day],
                dp[day-1] + counsels[day].second,
            });
        }
    }

    cout << dp[N] << endl;
}

void solve_dp_suffix(){
    for(int start_day=N; start_day>=1; --start_day){
        // dp[start_day] = max(dp[start_day], dp[start_day + 1]);
        dp[start_day] = dp[start_day + 1];

        int next_start_day = start_day + counsels[start_day].first;
        bool can_counsel = (next_start_day <= N+1);
        if(can_counsel){
            dp[start_day] = max({
                dp[start_day],
                dp[next_start_day] + counsels[start_day].second,
            });
        }
    }

    cout << dp[1] << endl;
}

void solve_dp_prefix(){
    // NOT appropriate for this problem
}

int max_reward;
// NOTE : recursion call on only 1 branch
void backtracking_1(int start_day, int reward){
    if(start_day > N){
        return;
    }

    for(int day=start_day; day<=N; ++day){
        int finish_day = day + (counsels[day].first - 1);
        int next_reward = reward + counsels[day].second;
        if(finish_day <= N){
            max_reward = max(max_reward, next_reward);
        }
        // NOTE : next start day = finish day + 1
        backtracking_1(finish_day + 1, next_reward);
    }
}

// NOTE : recursion call on 2 branches
void backtracking_2(int start_day, int reward){
    if(start_day > N){
        if(start_day <= N+1){
            max_reward = max(max_reward, reward);
        }
        return;
    }

    backtracking_2(start_day + 1, reward);
    backtracking_2(start_day + counsels[start_day].first, reward + counsels[start_day].second);
}

void backtracking_3(int start_day, int reward){
    if(start_day >= N+1){
        max_reward = max(max_reward, reward);
        return;
    }

    int next_start_day = start_day + counsels[start_day].first;
    bool do_counsel = (next_start_day <= N+1);
    if(do_counsel){
        backtracking_3(next_start_day, reward + counsels[start_day].second);
    }
    backtracking_3(start_day + 1, reward);
}

void solve_backtracking(){
    // backtracking_1(1, 0);

    // backtracking_2(1, 0);

    backtracking_3(1, 0);

    cout << max_reward << endl;
}


void solve(){
    // solve_dp_1();

    // solve_dp_2();

    // solve_dp_3();

    solve_dp_suffix();

    // solve_dp_prefix();

    // solve_backtracking();
}

void input(){
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> counsels[i].first >> counsels[i].second;
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
