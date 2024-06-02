/*
    https://www.acmicpc.net/problem/19539
    (apple tree)

    solution
        https://www.acmicpc.net/source/21252070
        (evenharder, 8 ms) : author
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        possible cases
        at different positions : 1 2
        at the same positions : 3

        2 2 2 : possible
        (observation) count possible 2's

        # = sum / 3
*/

const int ARR_SIZE = 100'000;   // 10^5
const int MAX_NUM = 10'000;     // 10^4

int N;
ll h;
// int arr[ARR_SIZE + 1];
ll cnt;
ll sum;

void solve(){
    if(sum % 3){
        cout << "NO" << endl;
    }
    else{
        if(cnt * 3 >= sum){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}

void input(){
    cin >> N;
    for(int i=1; i<=N; ++i){
        // cin >> arr[i];
        cin >> h;
        sum += h;
        cnt += h >> 1;
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
