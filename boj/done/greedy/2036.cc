/*
    https://www.acmicpc.net/problem/2036
    (score of array)

    similar problem
        https://www.acmicpc.net/problem/1744
        (number together)

    solution
        https://www.acmicpc.net/source/71090193
        (xezoless, 72 ms)
        https://www.acmicpc.net/source/1557886
        (koosaga, 16 ms) : sort() + DP
        https://www.acmicpc.net/source/76010463
        (rain_detals, 12 ms) : implemented in solve_greedy_pq()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        x + y < xy (x > 0, y > 0)
        (x-1)(y-1) > 1 : false when x = 1 or y = 1

2
-1
0

// 0 (O)
// -1 (X)

5
5
4
3
0
-3


7
-2
-1
-1
0
1
2
3

// 9


3
-1 -2 -3

// 5 (O)
// 6 (X)

*/

const int ARR_SIZE = 100'000;   // 10^5
const int MIN_NUM = -1'000'000; // -10^6
const int MAX_NUM = +1'000'000; // +10^6

int n;
ll arr[ARR_SIZE + 1];

ll max_score = 0;

void solve_greedy_array(){
    sort(arr+1, arr+1+n, less<ll>());

    int pos = lower_bound(arr+1, arr+1+n, 0) - arr;
    for(int idx=1; idx<pos; ){
        // if(arr[idx] < 0 && arr[idx+1] <= 0){                // WRONG
        if(arr[idx] < 0 && idx+1 <= n && arr[idx+1] <= 0){  // AC
            max_score += arr[idx] * arr[idx+1];
            idx += 2;
        }
        else{
            max_score += arr[idx];
            idx += 1;
        }
    }
    for(int idx=n; idx>=pos && arr[idx]; ){
        // if(arr[idx] > 1 && arr[idx-1] > 1){
        if(arr[idx] > 1 && idx-1 >= 1 && arr[idx-1] > 1){
            max_score += arr[idx] * arr[idx-1];
            idx -= 2;
        }
        else{
            max_score += arr[idx];
            idx -= 1;
        }
    }

    cout << max_score << endl;
}

priority_queue<ll, vector<ll>, less<ll> > pq_max;
priority_queue<ll, vector<ll>, greater<ll> > pq_min;
int cnt_one = 0;
bool is_zero = false;
void solve_greedy_pq(){
    while(pq_max.size() > 1){
        ll pos_1 = pq_max.top();
        pq_max.pop();
        ll pos_2 = pq_max.top();
        pq_max.pop();

        max_score += pos_1 * pos_2;
    }
    if(!pq_max.empty()){
        max_score += pq_max.top();
    }

    while(pq_min.size() > 1){
        ll neg_1 = pq_min.top();
        pq_min.pop();
        ll neg_2 = pq_min.top();
        pq_min.pop();

        max_score += neg_1 * neg_2;
    }
    if(!pq_min.empty()){
        if(!is_zero){
            max_score += pq_min.top();
        }
    }

    cout << max_score + cnt_one << endl;
}

void solve(){
    // solve_greedy_array();

    solve_greedy_pq();
}

void input(){
    cin >> n;
    for(int idx=1; idx<=n; ++idx){
        cin >> arr[idx];

        if(arr[idx] < 0){
            pq_min.push(arr[idx]);
        }
        else if(arr[idx] > 1){
            pq_max.push(arr[idx]);
        }
        else if(arr[idx] == 1){
            ++cnt_one;
        }
        else if(arr[idx] == 0){
            is_zero = true;
        }
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
