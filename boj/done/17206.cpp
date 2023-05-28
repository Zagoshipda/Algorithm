#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 100'000
#define MAX_NUM 80'001
int T;
int N;
int ans[MAX_NUM];

int calculate_sum(int n){
    return n * (n+1) / 2;
}

int solve(int n){

    int num_3 = n / 3;
    int num_7 = n / 7;
    int num_21 = n / 21;

    int val_3 = 3 * calculate_sum(num_3);
    int val_7 = 7 * calculate_sum(num_7);
    int val_21 = 21 * calculate_sum(num_21);

    return val_3 + val_7 - val_21;
}

void solve_dp(){
    int val = 0;
    // ans[0] = val;
    for(int num=1; num<MAX_NUM; ++num){
        if(num % 3 == 0 || num % 7 == 0){
            // ans[num] = ans[num-1] + num;
            val += num;
        }
        // else{
        //     ans[num] = ans[num-1];
        // }
        ans[num] = val;
    }
}

int main(){
    IOS;

    solve_dp();

    cin >> T;
    for(int i=0; i<T; ++i){
        cin >> N;

        // cout << solve(N) << endl;
        cout << ans[N] << endl;
    }

    return 0;
}
