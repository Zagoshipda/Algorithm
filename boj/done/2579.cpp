#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int num;
int stair[301];
int DP[301];

int main(){
    IOS;

    cin >> num;
    for(int i=1; i<=num; ++i){
        cin >> stair[i];
    }

    DP[0] = 0;
    DP[1] = stair[1];
    DP[2] = stair[1] + stair[2];

    int step_one, step_two;
    for(int i=1; i<=num; ++i){
        step_two = stair[i] + DP[i-2];
        step_one = stair[i] + stair[i-1] + DP[i-3];
        DP[i] = max(step_one, step_two);
    }

    cout << DP[num] << endl;

    return 0;
}
