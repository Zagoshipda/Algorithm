#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int M, N;
int tomato[1000][1000];
int dist[1000][1000];
bool visited[1000][1000];

bool check_range(int row, int col){
    return (0 <= row && row < N) && (0 <= col && col < M);
}

// E, W, S, N
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
queue<pair<int, int>> nodes;


void bfs(){
    int _row, _col;
    while(!nodes.empty()){
        pair<int, int> now = nodes.front();
        nodes.pop();
        // cout << "   now : " << now.first << " " << now.second << endl;

        for(int i=0; i<4; ++i){
            _row = now.first + dir[i][0];
            _col = now.second + dir[i][1];

            if(check_range(_row, _col) && tomato[_row][_col] == 0 && !visited[_row][_col]){
                nodes.push(make_pair(_row, _col));
                visited[_row][_col] = true;
                dist[_row][_col] = dist[now.first][now.second] + 1;
            }
        }
    }
}

int main(){
    IOS;

    cin >> M >> N;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin >> tomato[i][j];
            if(tomato[i][j] == 1){
                nodes.push(make_pair(i, j));
                visited[i][j] = true;
                dist[i][j] = 0;
            }
        }
    }

    bfs();

    int ans = -1;

    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(tomato[i][j] == 0 && !visited[i][j]){
                cout << -1 << endl;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans << endl;

    return 0;
}
