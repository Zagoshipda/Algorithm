/*
    https://www.acmicpc.net/problem/16509
    (catch the king)

    solution
        implemented in solve_bfs_2()
            https://www.acmicpc.net/source/54183805
            (cnocycle, 0 ms)
            https://www.acmicpc.net/source/30099419
            (isvara, 0 ms) : shortest path relax

        https://www.acmicpc.net/source/13205187
        (sjsjsj1246, 0 ms) : using struct
        https://www.acmicpc.net/source/10824921
        (jwvg0425, 0 ms) : array with 1, 2, 3 moves
        https://www.acmicpc.net/source/39527237
        (notlce, 0 ms) : one step forward, two steps diagonal
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MAX_ROW = 9;
const int MAX_COL = 8;
const int NUM_MOVES = 8;
const int NUM_OBSTACLES = 2;
const int INF_DIST = 1'000;

int r_1, c_1;
int r_2, c_2;

enum DIRECTIONS{
    EAST = 0,
    WEST = 1,
    SOUTH = 2,
    NORTH = 3,
};

pair<int, int> moves[NUM_MOVES] = {
    {-2, 3}, {2, 3},
    {-2, -3}, {2, -3},
    {3, -2}, {3, 2},
    {-3, -2}, {-3, 2},
};

pair<int, int> obstacles[NUM_MOVES][NUM_OBSTACLES] = {
    { {0, 1}, {-1, 2} },
    { {0, 1}, {1, 2} },
    { {0, -1}, {-1, -2} },
    { {0, -1}, {1, -2} },
    { {1, 0}, {2, -1} },
    { {1, 0}, {2, 1} },
    { {-1, 0}, {-2, -1} },
    { {-1, 0}, {-2, 1} },
};

bool check_range(int row, int col){
    return (0 <= row && row <= MAX_ROW) && (0 <= col && col <= MAX_COL);
}

bool visited[MAX_ROW + 1][MAX_COL + 1];
void solve_bfs_1(){
    queue<pair<pair<int, int>, int> > nodes;    // (row, col, moves)
    nodes.push({{r_1, c_1}, 0});
    visited[r_1][c_1] = true;

    while(!nodes.empty()){
        auto [curr_pos, curr_move] = nodes.front();
        nodes.pop();

        if(curr_pos.first == r_2 && curr_pos.second == c_2){
            cout << curr_move << endl;
            return;
        }

        for(int idx=0; idx<NUM_MOVES; ++idx){
            int next_row = curr_pos.first + moves[idx].first;
            int next_coi = curr_pos.second + moves[idx].second;

            if(check_range(next_row, next_coi) && !visited[next_row][next_coi]){
                bool can_move = true;
                for(int jdx=0; jdx<NUM_OBSTACLES; ++jdx){
                    if(curr_pos.first + obstacles[idx][jdx].first == r_2 &&
                        curr_pos.second + obstacles[idx][jdx].second == c_2){
                        can_move = false;
                        break;
                    }
                }
                if(can_move){
                    visited[next_row][next_coi] = true;
                    nodes.push({{next_row, next_coi}, curr_move + 1});
                }
            }
        }
    }

    cout << -1 << endl;
}

int min_dist[MAX_ROW + 1][MAX_COL + 1];
void solve_bfs_2(){
    for(int row=0; row<=MAX_ROW; ++row){
        for(int col=0; col<=MAX_COL; ++col){
            min_dist[row][col] = INF_DIST;
        }
    }
    min_dist[r_1][c_1] = 0;

    queue<pair<int, int> > nodes;   // (row, col)
    nodes.push({r_1, c_1});

    while(!nodes.empty()){
        auto [curr_row, curr_col] = nodes.front();
        nodes.pop();

        if(curr_row == r_2 && curr_col == c_2){
            cout << min_dist[r_2][c_2] << endl;
            return;
        }

        for(int idx=0; idx<NUM_MOVES; ++idx){
            bool can_move = true;
            for(int jdx=0; jdx<NUM_OBSTACLES; ++jdx){
                int _row = curr_row + obstacles[idx][jdx].first;
                int _col = curr_col + obstacles[idx][jdx].second;
                if(!check_range(_row, _col) || (_row == r_2 && _col == c_2)){
                    can_move = false;
                    break;
                }
            }

            if(can_move){
                int next_row = curr_row + moves[idx].first;
                int next_col = curr_col + moves[idx].second;

                // if(check_range(next_row, next_col) && min_dist[next_row][next_col] == INF_DIST){
                if(check_range(next_row, next_col) && min_dist[next_row][next_col] > min_dist[curr_row][curr_col] + 1){
                    nodes.push({next_row, next_col});
                    // relax
                    min_dist[next_row][next_col] = min_dist[curr_row][curr_col] + 1;
                }
            }
        }
    }

    cout << -1 << endl;
}

void solve(){
    // solve_bfs_1();

    solve_bfs_2();
}

void input(){
    cin >> r_1 >> c_1;
    cin >> r_2 >> c_2;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
