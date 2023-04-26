#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 1001
int n, m;
int arr[SIZE][SIZE];
int dp[SIZE][SIZE];
int max_square;

void calculate_max_square(){
    for(int row=1; row<=n; ++row){
        for(int col=1; col<=m; ++col){
            if(arr[row][col] == 1){
                dp[row][col] = min({dp[row-1][col-1], dp[row-1][col], dp[row][col-1]}) + 1;
            }
            max_square = max(max_square, dp[row][col]);
        }
    }

    // for(int i=1; i<=n; ++i){
    //     for(int j=1; j<=m; ++j){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << max_square * max_square << endl;
}

int main(){
    IOS;

    cin >> n >> m;
    string s;
    for(int i=1; i<=n; ++i){
        cin >> s;
        for(int j=1; j<=m; ++j){
            arr[i][j] = s[j-1] - '0';
        }
    }

    // for(int i=1; i<=n; ++i){
    //     for(int j=1; j<=m; ++j){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    calculate_max_square();

    return 0;
}
