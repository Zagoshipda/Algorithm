#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int T;
int M, N, K;
int X, Y;
int ans;

int graph[50][50];
bool visited[50][50];

bool check_range(int row, int col){
    return (0 <= row && row <= N-1) && (0 <= col && col <= M-1);
}

// E, W, S, N
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
void dfs(int row, int col){
    visited[row][col] = true;

    for(int i=0; i<4; ++i){
        int _row = row + dir[i][0];
        int _col = col + dir[i][1];

        if(check_range(_row, _col) && graph[_row][_col] == 1 && !visited[_row][_col]){
            dfs(_row, _col);
        }
    }
}

void initialize(){
    memset(graph, 0, sizeof(graph));
    memset(visited, false, sizeof(visited));
    // for(int i=0; i<50; ++i){
    //     for(int j=0; j<50; ++j){
    //         graph[i][j] = 0;
    //         visited[i][j] = false;
    //     }
    // }
}

int main(){
    IOS;

    cin >> T;
    while(T--){
        // Note : initialize every testcase.
        initialize();

        cin >> M >> N >> K;
        for(int i=0; i<K; ++i){
            cin >> X >> Y;
            graph[Y][X] = 1;
        }

        ans = 0;

        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(graph[i][j] == 1 && !visited[i][j]){
                    dfs(i, j);
                    ++ans;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
