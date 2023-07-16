/*
    downhill / descent
    https://www.acmicpc.net/problem/1520

    standard solution with dfs
    https://www.acmicpc.net/source/20563027 (24ms)
    https://www.acmicpc.net/source/7499870  (24ms)
    https://www.acmicpc.net/source/18991333 (24ms)
    https://www.acmicpc.net/source/11447879 (24ms)

    solution with max/min-height by sorting
    https://www.acmicpc.net/source/8755690  (8ms, using array)
    https://www.acmicpc.net/source/28660016 (4ms, using vector)
    https://www.acmicpc.net/source/15030283 (4ms, using priority queue)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 500
#define MAX_HEIGHT 10'000
#define POS_ROW 0
#define POS_COL 1
#define INITIAL_VALUE -1
using t_iii = tuple<int, int, int>;

int M, N;
int height_map[SIZE][SIZE];
ll dp[SIZE][SIZE];
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
vector<pair<int, int>> pos_with_heights[MAX_HEIGHT + 1];    // {row, col}

void input(){
    cin >> M >> N;
    for(int row=0; row<M; ++row){
        for(int col=0; col<N; ++col){
            cin >> height_map[row][col];
        }
    }
}

bool check_range(int row, int col){
    return (0 <= row && row < M) && (0 <= col && col < N);
}

// brute-force, time exceeded at 16%
// number of ways from (row, col) to (M-1, N-1)
void downhill_dfs_1(int row, int col){
    dp[row][col] += 1;

    if(row == M-1 && col == N-1){
        return;
    }

    for(int i=0; i<4; ++i){
        int next_row = row + dir[i][POS_ROW];
        int next_col = col + dir[i][POS_COL];
        if(check_range(next_row, next_col) && height_map[next_row][next_col] < height_map[row][col]){
            downhill_dfs_1(next_row, next_col);
        }
    }
}

// time exceeded at 33%
// number of ways from (row, col) to (M-1, N-1)
int downhill_dfs_2(int row, int col){
    if(row >= M-1 && col >= N-1){
        // return dp[M-1][N-1] = 1;
        return dp[row][col] = 1;
    }

    if(dp[row][col]){
        return dp[row][col];
    }

    for(int i=0; i<4; ++i){
        int next_row = row + dir[i][POS_ROW];
        int next_col = col + dir[i][POS_COL];
        if(check_range(next_row, next_col) && height_map[next_row][next_col] < height_map[row][col]){
            dp[row][col] += downhill_dfs_2(next_row, next_col);
        }
    }

    return dp[row][col];
}

// number of ways from (row, col) to (M-1, N-1)
bool no_way[SIZE][SIZE];
int downhill_dfs_3(int row, int col){
    if(row >= M-1 && col >= N-1){
        return dp[row][col] = 1;
    }

    if(dp[row][col]){
        return dp[row][col];
    }

    for(int i=0; i<4; ++i){
        int next_row = row + dir[i][POS_ROW];
        int next_col = col + dir[i][POS_COL];
        if(check_range(next_row, next_col) && height_map[next_row][next_col] < height_map[row][col]){
            if(!no_way[next_row][next_col]){
                dp[row][col] += downhill_dfs_2(next_row, next_col);
                if(dp[next_row][next_col] <= 0){
                    no_way[next_row][next_col] = true;
                }
            }
        }
    }

    return dp[row][col];
}

void initialize(){
    memset(dp, INITIAL_VALUE, sizeof dp);
}

int downhill_dfs_4(int row, int col){
    if(row >= M-1 && col >= N-1){
        return dp[row][col] = 1;
    }

    if(dp[row][col] != INITIAL_VALUE){
        return dp[row][col];
    }

    // dp[row][col] = 0;
    int val = 0;
    for(int i=0; i<4; ++i){
        int next_row = row + dir[i][POS_ROW];
        int next_col = col + dir[i][POS_COL];

        if(check_range(next_row, next_col) && height_map[next_row][next_col] < height_map[row][col]){
            // dp[row][col] += downhill_dfs_4(next_row, next_col);
            val += downhill_dfs_4(next_row, next_col);
        }
    }

    return dp[row][col] = val;
}

void downhill_array(){
    for(int row=0; row<M; ++row){
        for(int col=0; col<N; ++col){
            pos_with_heights[height_map[row][col]].push_back({row, col});
        }
    }

    // 1. (suffix) add up from lowest to highest
    // dp[row][col] : number of ways from (row, col) to (M-1, N-1)
    // dp[M-1][N-1] = 1;
    // for(int height=1; height<=MAX_HEIGHT; ++height){
    //     for(pair<int, int> pos : pos_with_heights[height]){
    //         int row = pos.first;
    //         int col = pos.second;
    //         for(int i=0; i<4; ++i){
    //             int next_row = row + dir[i][POS_ROW];
    //             int next_col = col + dir[i][POS_COL];

    //             if(check_range(next_row, next_col) && height_map[next_row][next_col] < height_map[row][col]){
    //                 // add up to current position.
    //                 dp[row][col] += dp[next_row][next_col];
    //             }
    //         }
    //     }
    // }
    // cout << dp[0][0] << endl;

    // 2. (prefix) add up from highest to lowest
    // dp[row][col] : number of ways from (0, 0) to (row, col)
    dp[0][0] = 1;
    for(int height=MAX_HEIGHT; height>0; --height){
        for(pair<int, int> pos : pos_with_heights[height]){
            int row = pos.first;
            int col = pos.second;
            for(int i=0; i<4; ++i){
                int next_row = row + dir[i][POS_ROW];
                int next_col = col + dir[i][POS_COL];

                if(check_range(next_row, next_col) && height_map[next_row][next_col] < height_map[row][col]){
                    // add up to next position.
                    dp[next_row][next_col] += dp[row][col];

                    // add up to current position.
                    // dp[row][col] += dp[next_row][next_col];ssssssss
                }
            }
        }
    }
    cout << dp[M-1][N-1] << endl;
}

void downhill_vector(){
    vector<t_iii> vec;  // (height, row, col)
    for(int row=0; row<M; ++row){
        for(int col=0; col<N; ++col){
            if(height_map[row][col] < height_map[0][0]){
                vec.push_back({height_map[row][col], row, col});
            }
        }
    }
    vec.push_back({height_map[0][0], 0, 0});

    // 1. prefix
    // sort(vec.begin(), vec.end(), greater<t_iii>());
    // dp[0][0] = 1;
    // for(t_iii now : vec){
    //     int row = get<1>(now);
    //     int col = get<2>(now);
    //     int height = get<0>(now);

    //     for(int i=0; i<4; ++i){
    //         int next_row = row + dir[i][POS_ROW];
    //         int next_col = col + dir[i][POS_COL];
    //         if(check_range(next_row, next_col) && height_map[next_row][next_col] < height_map[row][col]){
    //             dp[next_row][next_col] += dp[row][col];
    //         }
    //     }
    // }
    // cout << dp[M-1][N-1] << endl;

    // 2. suffix
    sort(vec.begin(), vec.end(), less<t_iii>());
    dp[M-1][N-1] = 1;
    for(t_iii now : vec){
        int row = get<1>(now);
        int col = get<2>(now);
        int height = get<0>(now);

        for(int i=0; i<4; ++i){
            int next_row = row + dir[i][POS_ROW];
            int next_col = col + dir[i][POS_COL];
            if(check_range(next_row, next_col) && height_map[next_row][next_col] < height){
                dp[row][col] += dp[next_row][next_col];
            }
        }
    }
    cout << dp[0][0] << endl;
}

// climbing down from the start to the end
priority_queue<t_iii, vector<t_iii>, less<t_iii> > pq_max;  // (height, row, col)
bool visited[SIZE][SIZE];
void downhill_pq_max(){

    dp[0][0] = 1;
    pq_max.push({height_map[0][0], 0, 0});
    visited[0][0] = true;
    while(!pq_max.empty()){
        t_iii current = pq_max.top();
        pq_max.pop();

        int height = get<0>(current);
        int row = get<1>(current);
        int col = get<2>(current);
        // NOTE : wrong answer
        // visited[row][col] = true;

        for(int i=0; i<4; ++i){
            int next_row = row + dir[i][POS_ROW];
            int next_col = col + dir[i][POS_COL];
            if(check_range(next_row, next_col) && height_map[next_row][next_col] < height){
                dp[next_row][next_col] += dp[row][col];
                if(!visited[next_row][next_col]){
                    pq_max.push({height_map[next_row][next_col], next_row, next_col});
                    visited[next_row][next_col] = true;
                }
            }
        }
    }
    cout << dp[M-1][N-1] << endl;
}

// climbing up back from the end to the start
priority_queue<t_iii, vector<t_iii>, greater<t_iii> > pq_min;  // (height, row, col)
void downhill_pq_min(){

    pq_min.push({height_map[M-1][N-1], M-1, N-1});
    visited[M-1][N-1] = true;
    dp[M-1][N-1] = 1;
    while(!pq_min.empty()){
        t_iii current = pq_min.top();
        pq_min.pop();

        int height = get<0>(current);
        int row = get<1>(current);
        int col = get<2>(current);

        for(int i=0; i<4; ++i){
            int next_row = row + dir[i][POS_ROW];
            int next_col = col + dir[i][POS_COL];
            // NOTE : climbing up
            if(check_range(next_row, next_col) && height_map[next_row][next_col] > height){
                // dp[row][col] += dp[next_row][next_col];

                // NOTE : add up to the next position
                dp[next_row][next_col] += dp[row][col];
                if(!visited[next_row][next_col]){
                    pq_min.push({height_map[next_row][next_col], next_row, next_col});
                    visited[next_row][next_col] = true;
                }
            }
        }
    }
    cout << dp[0][0] << endl;
}

void solve(){

    // downhill_dfs_1(0, 0);
    // cout << dp[M-1][N-1] << endl;

    // downhill_dfs_2(0, 0);
    // cout << dp[0][0] << endl;

    //////////////////////////////////////////////////////////////////

    // downhill_dfs_3(0, 0);
    // cout << dp[0][0] << endl;

    // initialize();
    // downhill_dfs_4(0, 0);
    // cout << dp[0][0] << endl;

    //////////////////////////////////////////////////////////////////

    // downhill_array();
    // downhill_vector();

    // downhill_pq_max();
    downhill_pq_min();

    //////////////////////////////////////////////////////////////////

    // for(int row=0; row<M; ++row){
    //     for(int col=0; col<N; ++col){
    //         cout << dp[row][col] << " ";
    //     }
    //     cout << endl;
    // }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
