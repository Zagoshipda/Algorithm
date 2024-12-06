/*
    https://www.acmicpc.net/problem/2493
    (tower)

    similar problem
        https://www.acmicpc.net/problem/17298
        (next greater element)

    solution
        https://www.acmicpc.net/source/82867172
        (ffvv0123, 88 ms)

        https://www.acmicpc.net/source/36375434
        (kimjerry, 84 ms) : parent pointer

        https://www.acmicpc.net/source/82593148
        (okmy729, 316 ms) : min priority queue
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int ARR_SIZE = 500'000;   // 5 * 10^5
const int MAX_NUM = 100'000'000;    // 10^8
const int INF = MAX_NUM + 1;

using p_ii = pair<int, int>;

int N;
int arr[ARR_SIZE + 1];
int ans[ARR_SIZE + 1];

void solve_1(){
    stack<p_ii> stk;    // (val, idx)
    for(int ith=N; ith>=1; --ith){
        while(!stk.empty()){
            auto [val, idx] = stk.top();
            if(val <= arr[ith]){
                stk.pop();
                ans[idx] = ith;
            }
            else{
                break;
            }
        }
        stk.push({arr[ith], ith});
    }

    for(int ith=1; ith<=N; ++ith){
        cout << ans[ith] << " ";
    }
    cout << endl;
}

void solve_2(){
    stack<p_ii> stk;    // (val, idx)
    stk.push({INF, 0});
    for(int ith=1; ith<=N; ++ith){
        // while(!stk.empty() && stk.top().first < arr[ith]){
        while(stk.top().first < arr[ith]){
            stk.pop();
        }

        cout << stk.top().second << " ";
        stk.push({arr[ith], ith});
    }
}

void solve(){
    // solve_1();

    solve_2();
}

void input(){
    cin >> N;
    for(int ith=1; ith<=N; ++ith){
        cin >> arr[ith];
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
