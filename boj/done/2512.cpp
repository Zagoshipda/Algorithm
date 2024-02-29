/*
    https://www.acmicpc.net/problem/2512
    (budget)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int NUM_REGION = 10'000;
const int MAX_BUDGET = 100'000;
const int MAX_TOTAL_BUDGET = 1'000'000'000;
int N;
int budgets[NUM_REGION + 1];
int M;

void solve_binary_search(){
    sort(budgets+1, budgets+1+N, less<int>());

    int sum = 0;
    for(int idx=1; idx<=N; ++idx){
        sum += budgets[idx];
    }
    if(sum <= M){
        cout << budgets[N] << endl;
    }
    else{
        int max_budget = 0;
        for(int left=1, right=M; left<=right; ){
            int limit = (left + right) >> 1;
            int sum = 0;
            for(int idx=1; idx<=N; ++idx){
                if(budgets[idx] <= limit){
                    sum += budgets[idx];
                }
                else{
                    sum += limit;
                }
            }
            if(sum <= M){
                max_budget = max(max_budget, limit);
                left = limit + 1;
            }
            else{
                right = limit - 1;
            }
        }

        cout << max_budget << endl;
    }
}

void solve(){
    solve_binary_search();
}

void input(){
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> budgets[i];
    }
    cin >> M;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
