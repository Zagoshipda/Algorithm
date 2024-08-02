/*
    https://www.acmicpc.net/problem/11659
    (range sum 4)

    similar problem
        https://www.acmicpc.net/problem/11441
        (range sum)

    references
        https://book.acmicpc.net/algorithm/prefix-sum
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

#define NUM 100'000
int N, M;
int i, j;
int arr[NUM + 1];
int prefix_sum[NUM + 1];

void solve(){
    cout << prefix_sum[j] - prefix_sum[i-1] << endl;
}

void input(){
    cin >> N >> M;

    for(int idx=1; idx<=N; ++idx){
        cin >> arr[idx];
        prefix_sum[idx] = arr[idx] + prefix_sum[idx-1];
    }

    for(int k=0; k<M; ++k){
        cin >> i >> j;

        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
