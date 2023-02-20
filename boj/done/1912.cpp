#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int n;
int DP[100001];
int arr[100001];
int sum, max_sum;

int main(){
    IOS;

    cin >> n;

    for(int i=1; i<=n; ++i){
        cin >> arr[i];
    }

    for(int i=1; i<=n; ++i){
        sum += arr[i];
        DP[i] = max(sum, arr[i]);
        if(sum <= arr[i]){
            sum = arr[i];
        }
    }
    max_sum = DP[1];
    for(int i=2; i<=n; ++i){
        if(max_sum < DP[i]){
            max_sum = DP[i];
        }
    }

    cout << max_sum << endl;

    return 0;
}
