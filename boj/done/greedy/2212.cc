/*
    https://www.acmicpc.net/problem/2212
    (sensor)

    similar problem
        https://www.acmicpc.net/problem/10058
        (sensor network)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int ARR_SIZE = 10'000;    // 10^4
const int MIN_NUM = -1'000'000;  // -10^6
const int MAX_NUM = +1'000'000;  // +10^6

int N;
int K;
int arr[ARR_SIZE + 1];

priority_queue<int, vector<int>, less<int> > pq_max;
void solve(){
    sort(arr+1, arr+1+N, less<int>());

    for(int idx=1; idx<N; ++idx){
        pq_max.push(arr[idx + 1] - arr[idx]);
    }

    // ll len = *max_element(arr+1, arr+1+N) - *min_element(arr+1, arr+1+N);
    ll len = arr[N] - arr[1];
    for(int ith=1; ith<K; ++ith){
        if(pq_max.empty()){
            break;
        }
        len -= pq_max.top();
        pq_max.pop();
    }
    cout << len << endl;
}

void input(){
    cin >> N;
    cin >> K;
    for(int idx=1; idx<=N; ++idx){
        cin >> arr[idx];
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
