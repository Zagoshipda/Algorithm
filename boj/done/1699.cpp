#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 100'001
int N;
int squares_sum[SIZE];

int main(){
    IOS;

    cin >> N;

    // initialize
    for(int i=1; i<=N; ++i){
        squares_sum[i] = i;
    }

    // duplicate in DP
    // for(int i=1; i*i<=N; ++i){
    //     squares_sum[i*i] = 1;
    // }

    // DP(bottom-up)
    for(int i=2; i<=N; ++i){
        for(int j=1; j*j<=i; ++j){
            squares_sum[i] = min(squares_sum[i], squares_sum[i-j*j] + 1);
        }
    }

    cout << squares_sum[N] << endl;

    return 0;
}
