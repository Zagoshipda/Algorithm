/*
    https://www.acmicpc.net/problem/16953
    (number transition)

    solutions
        implemented in solve_dfs()
            https://www.acmicpc.net/source/11974939
            (ajttnd, 0 ms)
            https://www.acmicpc.net/source/15483009
            (dkw9700, 0 ms)
            https://www.acmicpc.net/source/17318096
            (leedongbin, 0 ms)

        https://www.acmicpc.net/source/18244261
        (ggi411, 0 ms) : implemented in solve_bfs_2()

        implemented in solve_greedy()
            https://www.acmicpc.net/source/11879283
            (sangdo913, 0 ms)
            https://www.acmicpc.net/source/11831716
            (kipa00, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        2 operations
        op 1. * 2
        op 2. * 10 + 1

    Algorithm
        number range ~ 10^9 ~ 2^32
        => at most 32 operations

        bfs + dp ?
            start from A, move to B step by step

        greedy ?
            think of recovering from B to A
            B must be the multiple of 2 (by op 1.) or end with 1 (by op 2.)
*/

const int MAX_NUM = INT_MAX;
const int MAX_OPERATION = 50;
const int INITIAL_CNT = 1;

ll A, B;

unordered_map<int, bool> visited;
void solve_bfs_1(){
    queue<pair<ll, int> > nodes;    // (num, cnt) pair
    nodes.push({A, INITIAL_CNT});
    visited[A] = true;
    while(!nodes.empty()){
        auto [num, cnt] = nodes.front();
        nodes.pop();
        if(num == B){
            cout << cnt << endl;
            return;
        }
        // if(num > B){
        //     break;
        // }

        ll next_1 = num << 1;
        ll next_2 = num * 10 + 1;
        if(next_1 <= B && !visited[next_1]){
            nodes.push({next_1, cnt + 1});
            visited[next_1] = true;
        }

        if(next_2 <= B && !visited[next_2]){
            nodes.push({next_2, cnt + 1});
            visited[next_2] = true;
        }
    }
    cout << -1 << endl;
}

void solve_bfs_2(){
    queue<ll> nodes;
    nodes.push(A);
    int cnt = INITIAL_CNT;

    while(!nodes.empty()){
        int len = nodes.size();
        for(int ith=1; ith<=len; ++ith){
            ll num = nodes.front();
            nodes.pop();

            if(num == B){
                cout << cnt << endl;
                return;
            }

            ll next_1 = num << 1;
            ll next_2 = num * 10 + 1;
            if(next_1 <= B){
                nodes.push(next_1);
            }
            if(next_2 <= B){
                nodes.push(next_2);
            }
        }
        ++cnt;
    }

    cout << -1 << endl;
}

int min_op = MAX_OPERATION;
void solve_dfs(ll num, int cnt){
    if(num == B){
        min_op = min(min_op, cnt);
        return;
    }
    else if(num > B){
        return;
    }

    solve_dfs(num << 1, cnt + 1);
    solve_dfs(num * 10 + 1, cnt + 1);
}

void solve_greedy(){
    int cnt = INITIAL_CNT;
    while(A < B){
        if(B % 10 == 1){
            // B -= 1;
            B /= 10;
            ++cnt;
        }
        else if((B & 1) == 0){    // WRONG : == precedes &
            B >>= 1;
            ++cnt;
        }
        else{
            // cout << -1 << endl;
            // return;
            break;
        }
    }

    if(A == B){
        cout << cnt << endl;
    }
    else{
        cout << -1 << endl;
    }
}

void solve(){
    // solve_bfs_1();  // 16 ms
    // solve_bfs_2();  // 0 ms

    // solve_dfs(A, INITIAL_CNT);
    // min_op == MAX_OPERATION ? cout << -1 << endl : cout << min_op << endl;

    solve_greedy();
}

void input(){
    cin >> A >> B;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
