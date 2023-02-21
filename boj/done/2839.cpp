#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int DP[5001];
int N;

int main(){
    IOS;

    cin >> N;

    DP[3] = 1;
    DP[5] = 1;

    for(int i=6; i<=N; ++i){
        if(DP[i-3] > 0 && DP[i-5] > 0){
            DP[i] = min(DP[i-3], DP[i-5]) + 1;
        }
        else if(DP[i-3] > 0){
            DP[i] = DP[i-3] + 1;
        }
        else if(DP[i-5] > 0){
            DP[i] = DP[i-5] + 1;
        }
    }

    if(DP[N] > 0){
        cout << DP[N] << endl;
    }
    else{
        cout << -1 << endl;
    }

    return 0;
}
