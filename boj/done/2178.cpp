#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int N, M;
char graph[101][101];
int dist[101][101];
// int graph[101][101];
bool visited[101][101];

int ans = INT_MAX;
int cnt = 0;

// E, W, S, N
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

bool check_range(int row, int col){
    return (0 <= row && row <= N-1) && (0 <= col && col <= M-1);
}

// timeout for dfs.
void dfs(int row, int col){
    visited[row][col] = true;
    ++cnt;
    // cout << row << " " << col << endl;
    if(row == N-1 && col == M-1 && cnt < ans){
        ans = cnt;
        return;
    }
    for(int i=0; i<4; ++i){
        int _row = row + dir[i][0];
        int _col = col + dir[i][1];

        if(check_range(_row, _col) && graph[_row][_col] == '1' && !visited[_row][_col]){
            dfs(_row, _col);
            --cnt;
            visited[_row][_col] = false;
        }
    }
}

queue<pair<int,int>> nodes;
void bfs(int row, int col){
    nodes.push(make_pair(row, col));
    visited[row][col] = true;
    dist[row][col] = 1;

    while(!nodes.empty()){
        pair<int, int> node = nodes.front();
        nodes.pop();
        row = node.first;
        col = node.second;

        if(row == N-1 && col == M-1){
            break;
        }

        for(int i=0; i<4; ++i){
            int _row = row + dir[i][0];
            int _col = col + dir[i][1];
            if(check_range(_row, _col) && graph[_row][_col] == '1' && !visited[_row][_col]){
                nodes.push(make_pair(_row, _col));
                visited[_row][_col] = true;
                dist[_row][_col] = dist[row][col] + 1;
            }
        }
    }
}

int main(){
    // IOS;

    cin >> N >> M;
    for(int i=0; i<N; ++i){
        scanf("%s", graph[i]);
        // scanf("%d", graph[i]);
    }
    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<M; ++j){
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // dfs(0, 0);
    bfs(0, 0);

    // cout << ans << endl;
    cout << dist[N-1][M-1] << endl;

    return 0;
}
