#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18


int tomato[100][100][100];
int dist[100][100][100];
bool visited[100][100][100];

int M, N, H;

bool check_range(int row, int col, int height){
    return (0 <= row && row < N) && (0 <= col && col < M) && (0 <= height && height < H);
}


// E, W, S, N, U, D
int dir[6][3] = { {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}, {0, 0, 1}, {0, 0, -1} };
queue<tuple<int, int, int>> nodes;
void bfs(){
    int _row, _col, _height;
    while(!nodes.empty()){
        tuple<int, int, int> now = nodes.front();
        nodes.pop();

        for(int i=0; i<6; ++i){
            _row = get<0>(now) + dir[i][0];
            _col = get<1>(now) + dir[i][1];
            _height = get<2>(now) + dir[i][2];

            if(check_range(_row, _col, _height) && tomato[_row][_col][_height] == 0 && !visited[_row][_col][_height]){
                nodes.push(make_tuple(_row, _col, _height));
                visited[_row][_col][_height] = true;
                dist[_row][_col][_height] = dist[get<0>(now)][get<1>(now)][get<2>(now)] + 1;
            }
        }
    }
}

int main(){
    IOS;

    cin >> M >> N >> H;
    int input;
    for(int i=0; i<H; ++i){
        for(int j=0; j<N; ++j){
            for(int k=0; k<M; ++k){
                cin >> input;
                tomato[j][k][i] = input;
                if(input == 1){
                    nodes.push(make_tuple(j, k, i));
                    visited[j][k][i] = true;
                    dist[j][k][i] = 0;
                }
            }
        }
    }

    bfs();

    int ans = -1;

    for(int i=0; i<H; ++i){
        for(int j=0; j<N; ++j){
            for(int k=0; k<M; ++k){
                if(tomato[j][k][i] == 0 && !visited[j][k][i]){
                    cout << -1 << endl;
                    return 0;
                }
                ans = max(ans, dist[j][k][i]);
            }
        }
    }

    cout << ans << endl;


    return 0;
}
