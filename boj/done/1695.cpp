#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // -9*10^18 ~ 9*10^18

const int size = 5050;
int dp[size][size];

int pal(int arr[], int start, int end){
    if(start >= end){
        return 0;
    }

    if(dp[start][end] != 0){
        return dp[start][end];
    }

    if(arr[start] == arr[end]){
        // return pal(arr, start+1, end-1);
        return dp[start][end] = pal(arr, start+1, end-1);
    }   
    else{
        // return min(pal(arr, start+1, end) + 1, pal(arr, start, end-1) + 1);
        return dp[start][end] = min(pal(arr, start+1, end), pal(arr, start, end-1)) + 1;
    }

}

int N;
int main(void){
    IOS;

    cin >> N;
    int input[N];
    for(int i=0; i<N; ++i){
        cin >> input[i];
    }

    int ans = pal(input, 0, N-1);
    cout << ans << endl;

    return 0;
}
