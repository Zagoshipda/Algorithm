/*
    https://www.acmicpc.net/problem/2670
    (largest consecutive product)

    solutions
        https://www.acmicpc.net/source/3153856
        (ls4154, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    brute force time complexity
        array size              : N ~ 10^4
        # of subarrays          : N^2 ~ 10^8
        products per subarray   : N ~ 10^4
        => total operations     : N^3 ~ 10^12

    => DP
4
6.1
4.3
0.5
6.1

// 80.002 (80.0015)

6
3.0
5.0
0.7
1.7
1.7
2.9

// 88.001 (88.0005)

*/

const int MAX_NUM = 10'000; // 10^4
int N;
double numbers[MAX_NUM + 1];

double dp_product[MAX_NUM + 1]; // dp[k] = max product s.t. ends with numbers[k]
void solve(){
    double max_product = numbers[1];
    dp_product[1] = numbers[1];
    for(int idx=2; idx<=N; ++idx){
        if(dp_product[idx-1] * numbers[idx] > numbers[idx]){
            dp_product[idx] = dp_product[idx-1] * numbers[idx];
        }
        else{
            dp_product[idx] = numbers[idx];
        }
        max_product = max(max_product, dp_product[idx]);
    }

    // max_product *= 1000;
    // max_product = round(max_product);
    // max_product /= 1000;
    // cout << max_product << endl;
    cout << fixed << setprecision(3) << max_product << endl;
}

void input(){
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> numbers[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
