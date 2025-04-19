/*
    https://www.acmicpc.net/problem/2911
    (RAZGOVORI) : conversations

    similar problem
        https://www.acmicpc.net/problem/13146
        (make it the same 2)

    solution
        https://www.acmicpc.net/source/89087879
        (YunGoon, 24 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm

    ex.
        3 9
        7 2
        8 3
        3 4

        1 2 3 4 5 6 7 8 9
             3       7 8
             4       2 3
        => 5




*/

const int ARR_SIZE = 100'000;       // 10^5
const int MAX_NUM = 1'000'000'000;  // 10^9
const int INF = MAX_NUM + 1;

using p_ii = pair<int, int>;

int N, M;
int P, C;
// p_ii arr[ARR_SIZE + 1];
vector<p_ii> arr;
int min_arr = INF;

void solve_greedy_1(){
    sort(arr.begin(), arr.end(), less<p_ii>());

    ll ans = min_arr;
    for(int ith=0; ith<N-1; ++ith){
        if(arr[ith].second > arr[ith + 1].second){
            ans += arr[ith].second - arr[ith + 1].second;
        }
    }

    cout << ans + (arr[N-1].second - min_arr) << endl;
}


void solve_greedy_2(){
    sort(arr.begin(), arr.end(), less<p_ii>());

    ll ans = arr.front().second;
    for(int ith=1; ith<N; ++ith){
        if(arr[ith - 1].second < arr[ith].second){
            ans += arr[ith].second - arr[ith - 1].second;
        }
    }
    cout << ans << endl;
}

void solve(){
    // solve_greedy_1();
    solve_greedy_2();
}

void input(){
    cin >> N >> M;
    for(int ith=1; ith<=N; ++ith){
        cin >> P >> C;
        min_arr = min(min_arr, C);
        arr.push_back({P, C});
    }
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
