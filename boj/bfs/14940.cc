/*
    https://www.acmicpc.net/problem/14940
    (shortest distance)

    solution
        https://www.acmicpc.net/source/34702045
        (55murphy, 36 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MIN_ROW = 2;
const int MAX_ROW = 1'000;  // 10^3
const int MIN_COL = 2;
const int MAX_COL = 1'000;  // 10^3

const int NUM_MOVES = 4;

pair<int, int> target_pos;

int n, m;
int maps[MAX_ROW + 1][MAX_COL + 1];

int dist[MAX_ROW + 1][MAX_COL + 1];
int visited[MAX_ROW + 2][MAX_COL + 2];
pair<int, int> moves[] = {
    { -1, 0 },
    { +1, 0 },
    { 0, -1 },
    { 0, +1 },
};

enum TYPES{
    impossible = 0,
    possible = 1,
    target = 2,
};

bool check_range(int row, int col){
    return (1 <= row && row <= n) && (1 <= col && col <= m);
}

bool can_move(int row, int col){
    return maps[row][col];
}

void initialize(){
    for(int row=1; row<=n; ++row){
        for(int col=1; col<=m; ++col){
            if(can_move(row, col)){
                dist[row][col] = - 1;
            }
        }
    }
}

void solve_bfs(){
    initialize();

    // bfs
    queue<pair<pair<int, int>, int > > nodes;   // (position, distance)
    nodes.push({target_pos, 0});

    while(!nodes.empty()){
        auto [curr, cnt] = nodes.front();
        nodes.pop();

        if(visited[curr.first][curr.second]){
            continue;
        }

        visited[curr.first][curr.second] = true;
        dist[curr.first][curr.second] = cnt;

        for(int ith=0; ith<NUM_MOVES; ++ith){
            int next_row = curr.first + moves[ith].first;
            int next_col = curr.second + moves[ith].second;
            if(check_range(next_row, next_col) && can_move(next_row, next_col)){
                nodes.push({
                    {next_row, next_col},
                    cnt + 1
                });
            }
        }
    }

    // print answer
    for(int row=1; row<=n; ++row){
        for(int col=1; col<=m; ++col){
            cout << dist[row][col] << " ";
        }
        cout << endl;
    }
}

void solve(){
    solve_bfs();
}

void input(){
    cin >> n >> m;
    for(int row=1; row<=n; ++row){
        for(int col=1; col<=m; ++col){
            cin >> maps[row][col];
            if(maps[row][col] == 2){
                target_pos = { row, col };
            }
        }
    }
}

void debug(){

}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    // debug();

    input();

    solve();

    return 0;
}
