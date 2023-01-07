#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int N;
int graph[25][25];
bool visited[25][25];
vector<int> out;
int cnt = 0;

bool check_range(int row, int col){
    return (0 <= row && row < N) && (0 <= col && col < N);
}

// check E, W, S, N
int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
void dfs(int row, int col){
    visited[row][col] = true;
    ++cnt;

    for(int i=0; i<4; ++i){
        int _row = row + dir[i][0];
        int _col = col + dir[i][1];
        if(check_range(_row, _col) && graph[_row][_col] == 1 && !visited[_row][_col]){
            dfs(_row, _col);
        }
    }
}

int main(){
    IOS;

    cin >> N;
    string input;
    for(int i=0; i<N; ++i){
        cin >> input;
        for(int j=0; j<N; ++j){
            graph[i][j] = input[j] - '0';
        }
    }
    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<N; ++j){
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(graph[i][j] == 1 && !visited[i][j]){
                cnt = 0;
                dfs(i, j);
                out.push_back(cnt);
            }
        }
    }

    sort(out.begin(), out.end());
    cout << out.size() << endl;
    for(int o : out){
        cout << o << endl;
    }

    return 0;
}
