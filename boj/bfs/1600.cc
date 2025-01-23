/*
    https://www.acmicpc.net/problem/1600
    (horse monkey)

    solution
        https://www.acmicpc.net/source/20156560
        (jsing8, 56 ms)

    reference
        https://www.acmicpc.net/board/view/147221

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        NOTE : 3-dimensional bfs (row, column, ability)
            information on the number of ability K required
*/

const int MAX_ABILITY = 30;
const int MIN_ROW = 1;
const int MAX_ROW = 200;
const int MIN_COL = 1;
const int MAX_COL = 200;

const int NUM_HORSE = 8;
const int NUM_MONKEY = 4;

enum TYPES{
    nothing = 0,
    wall = 1,
};

int K;
int W, H;
int board[MAX_ROW + 1][MAX_COL + 1];

// int visited[MAX_ROW + 1][MAX_COL + 1];               // WRONG
int visited[MAX_ROW + 1][MAX_COL + 1][MAX_ABILITY + 1]; // AC
int min_dist[MAX_ROW + 1][MAX_COL + 1];

pair<int, int> horse[] = {
    {-2, -1},
    {-2, +1},
    {-1, -2},
    {-1, +2},
    {+1, -2},
    {+1, +2},
    {+2, -1},
    {+2, +1},
};

pair<int, int> monkey[] = {
    {-1, 0},
    {+1, 0},
    {0, -1},
    {0, +1},
};

bool check_range(int row, int col){
    return (1 <= row && row <= H) && (1 <= col && col <= W);
}

void solve_bfs(){
    pair<int, int> START = { 1, 1 };
    pair<int, int> END = { H, W };

    queue<pair<pair<int, int>, pair<int, int> > > nodes;    // (position, (cnt, ability))
    nodes.push({
        START, {0, K}
    });

    while(!nodes.empty()){
        auto [pos, val] = nodes.front();
        auto [cnt, ability] = val;
        nodes.pop();

        if(visited[pos.first][pos.second][ability]){
            continue;
        }

        if(pos == END){
            cout << cnt << endl;
            return;
        }

        visited[pos.first][pos.second][ability] = true;

        for(int ith=0; ith<NUM_MONKEY; ++ith){
            int next_row = pos.first + monkey[ith].first;
            int next_col = pos.second + monkey[ith].second;
            if(check_range(next_row, next_col) && board[next_row][next_col] == nothing){
                nodes.push({
                    {next_row, next_col},
                    {cnt + 1, ability}
                });
            }
        }

        if(ability){
            for(int ith=0; ith<NUM_HORSE; ++ith){
                int next_row = pos.first + horse[ith].first;
                int next_col = pos.second + horse[ith].second;
                if(check_range(next_row, next_col) && board[next_row][next_col] == nothing){
                    nodes.push({
                        {next_row, next_col},
                        {cnt + 1, ability - 1}
                    });
                }
            }
        }
    }

    cout << -1 << endl;
}

void solve(){
    solve_bfs();
}

void input(){
    cin >> K;
    cin >> W >> H;
    for(int row=1; row<=H; ++row){
        for(int col=1; col<=W; ++col){
            cin >> board[row][col];
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
