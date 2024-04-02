/*
    https://www.acmicpc.net/problem/2487
    (mix sequence)

    similar problem
        https://www.acmicpc.net/problem/10451
        (permutation cycles)

    solutions
        https://www.acmicpc.net/source/16286611
        (YunGoon, 0 ms) : use array value as the visited flag, while() loop for dfs
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        orbit = lcm of cycles
*/

const int MAX_NUM = 20'000;             // 2 * 10^4
const int MAX_ORBIT = 2'000'000'000;    // 2 * 10^9

int N;
int arr[MAX_NUM + 1];

int visited[MAX_NUM + 1];
vector<int> cycles;
void dfs(int pos, int cnt){
    if(visited[pos]){
        cycles.push_back(cnt);
        return;
    }

    visited[pos] = true;
    dfs(arr[pos], cnt+1);
}

void solve(){
    for(int idx=1; idx<=N; ++idx){
        if(!visited[idx]){
            dfs(idx, 0);
        }
    }

    int orbit = 1;
    for(int cycle : cycles){
        orbit = lcm(orbit, cycle);
    }
    cout << orbit << endl;
}

void input(){
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> arr[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
