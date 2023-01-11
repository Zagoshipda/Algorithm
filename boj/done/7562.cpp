#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int n;
int l;
bool visited[300][300];
int dist[300][300];
pair<int, int> starting;
pair<int, int> ending;
int dir[8][2] = { {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1} };

bool check_range(int row, int col){
    return (0 <= row && row < l) && (0 <= col && col < l);
}


void bfs(pair<int, int> starting, pair<int, int> ending){
    queue<pair<int, int>> nodes;

    visited[starting.first][starting.second] = true;
    dist[starting.first][starting.second] = 0;
    nodes.push(make_pair(starting.first, starting.second));

    pair<int, int> now;
    int _row, _col;
    while(!nodes.empty()){
        now = nodes.front();
        nodes.pop();
        // cout << "   now : " << now.first << " " << now.second << endl;

        if(now.first == ending.first && now.second == ending.second){
            break;
        }

        for(int i=0; i<8; ++i){
            _row = now.first + dir[i][0];
            _col = now.second + dir[i][1];
            // cout << "next " << _row  << " " << _col << endl;

            if(check_range(_row, _col) && !visited[_row][_col]){
                visited[_row][_col] = true;
                dist[_row][_col] = dist[now.first][now.second] + 1;
                nodes.push(make_pair(_row, _col));
            }
        }
    }
}

void initialize(){
    for(int i=0; i<l; ++i){
        for(int j=0; j<l; ++j){
            visited[i][j] = false;
            dist[i][j] = 0;
        }
    }
}

int main(){
    IOS;

    cin >> n;
    while(n--){
        initialize();

        cin >> l;
        cin >> starting.first >> starting.second;
        cin >> ending.first >> ending.second;

        bfs(starting, ending);

        cout << dist[ending.first][ending.second] << endl;
    }

    return 0;
}
