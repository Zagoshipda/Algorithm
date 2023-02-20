#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int n;
int DP[100001];
int arr[100001];
int max_sum;

int main(){
    IOS;

    cin >> n;

    for(int i=1; i<=n; ++i){
        cin >> arr[i];
    }

    DP[0] = 0;
    max_sum = INT_MIN;

    for(int i=1; i<=n; ++i){
        DP[i] = max(DP[i-1] + arr[i], arr[i]);
        max_sum = max(max_sum, DP[i]);
    }

    cout << max_sum << endl;

    return 0;
}
