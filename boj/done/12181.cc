/*
    https://www.acmicpc.net/problem/12181
    (googlander 2)

    solutions
        https://www.acmicpc.net/source/10493902
        (alex9801, 0 ms) : top-down dfs with memoization, implemented in solve_dfs_2()

        https://www.acmicpc.net/source/5667973
        (dotorya, 0 ms) : bottom-up dp, implemented in solve_dp_2()

        https://www.acmicpc.net/source/26626954
        (jinhan814, 0 ms) : dp solution with binomial coefficients

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        - must choose either one of moves that is (not un)fashionable
            (a) go straight 1 step
            (b) go right 1 step
        - unfashionable move : off of the stage or onto a square that already visited
        - must keep moving until both possible moves become unfashionable
        - If at any point both of the possible moves are unfashionable, the show immediately ends
*/

const int MAX_ROW = 25;
const int MAX_COL = 25;
const int START_ROW = 1;
const int START_COL = 1;
const int NUM_MOVES = 4;

pair<int, int> moves[NUM_MOVES] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
int move_type;
int T;
int R, C;
int cnt;

bool visited[(MAX_ROW << 1) + 1][(MAX_COL << 1) + 1];
int paths;
ll dp_path[(MAX_ROW << 1) + 1][(MAX_COL << 1) + 1];
ll dp_path_2[(MAX_ROW << 1) + 1][(MAX_COL << 1) + 1];

bool check_range(int row, int col){
    return (1<=row && row<=R) && (1<=col && col<=C);
}

bool check_range(pair<int, int> pos){
    return check_range(pos.first, pos.second);
}

bool check_visited(pair<int, int> pos){
    return check_range(pos) && visited[pos.first][pos.second];
}

void initialize(){
    paths = 0;
    move_type = 0;
    for(int row=1; row<=R+C; ++row){
        for(int col=1; col<=R+C; ++col){
            assert(row <= (MAX_ROW << 1) && col <= (MAX_COL << 1));
            // visited[row][col] = false;
            dp_path[row][col] = 0;
            dp_path_2[row][col] = 0;
        }
    }
}

int solve_dfs(pair<int, int> curr, int type){
    // if(dp_path[curr.first][curr.second]){
    //     return ++dp_path[curr.first][curr.second];
    // }

    pair<int, int> move_forward = moves[type];
    pair<int, int> move_right = moves[(type+1)%NUM_MOVES];

    pair<int, int> next_forward = {
        curr.first + move_forward.first,
        curr.second + move_forward.second
    };
    pair<int, int> next_right = {
        curr.first + move_right.first,
        curr.second + move_right.second
    };

    // check unfashionable
    if((!check_range(next_forward) || check_visited(next_forward)) &&
        (!check_range(next_right) || check_visited(next_right))){
        // cout << curr.first << " " << curr.second << endl;
        ++paths;
        return 0;
        // return dp_path[curr.first][curr.second] = 1;
    }

    int val_1 = 0;
    int val_2 = 0;
    if(check_range(next_forward) && !visited[next_forward.first][next_forward.second]){
        visited[next_forward.first][next_forward.second] = true;
        val_1 = solve_dfs(next_forward, type);
        visited[next_forward.first][next_forward.second] = false;
    }
    if(check_range(next_right) && !visited[next_right.first][next_right.second]){
        visited[next_right.first][next_right.second] = true;
        val_2 = solve_dfs(next_right, (type+1)%NUM_MOVES);
        visited[next_right.first][next_right.second] = false;
    }
    // dp_path[curr.first][curr.second] = val_1 + val_2;
    // cout << curr.first << "," << curr.second << " : " << dp_path[curr.first][curr.second] << endl;
    // return dp_path[curr.first][curr.second] = val_1 + val_2;
    return 0;
}

/*
    1 1 : 1
    1 n : 1
    n 1 : 1
    2 2 : 2
    3 2 : 3
    2 3 : 3

    2 4 : 4

    3 3 : 6
    3 4 : 10

    dp simple solution, implemented in solve_dp_1()
        dp[r][c] = dp[r-1][c] + d[r][c-1]
            ~ also related to binomial coefficients
    recurrence relation, implemented in solve_dp_2() as bottom-up, in solve_dfs_2() as top-down
        dp[r][c] = sum(dp[c-1][k]) for k=1...r
                = sum(dp[c-1][k]) for k=1...r-1 + dp[c-1][r]
                = dp[r-1][c] + dp[c-1][r]
        dp[1][1] = 1
        dp[1][2] = dp[1][1] = 1;
        dp[2][1] = dp[0][1] + dp[0][2] = 1
        dp[2][2] = dp[1][1...2]
        dp[3][3] = dp[2][1...2]
        dp[4][4] = dp[3][1...4]
            dp[3][4] = dp[3][1...3]
    base case
        dp[1][c] = 1
        dp[r][1] = 1
    topological order
        increasing r+c order
        (2,2) (2,3 3,2) (2,4 3,3 4,2)

        25,3 = 325 = 25 + 300
        = 2,1...25


24
24 1
24 2
24 3
24 4
24 5
24 6
24 7
24 8
24 9
24 10
24 11
24 12
24 13
24 14
24 15
24 16
24 17
24 18
24 19
24 20
24 21
24 22
24 23
24 24

50
25 1
25 2
25 3
25 4
25 5
25 6
25 7
25 8
25 9
25 10
25 11
25 12
25 13
25 14
25 15
25 16
25 17
25 18
25 19
25 20
25 21
25 22
25 23
25 24
25 25
1 25
2 25
3 25
4 25
5 25
6 25
7 25
8 25
9 25
10 25
11 25
12 25
13 25
14 25
15 25
16 25
17 25
18 25
19 25
20 25
21 25
22 25
23 25
24 25
25 25

*/

void solve_dp_1(){
    dp_path[1][1] = 1;
    for(int row=1; row<=R; ++row){
        for(int col=1; col<=C; ++col){
            if(row <= 1 && col <= 1){
                continue;
            }
            dp_path[row][col] = dp_path[row-1][col] + dp_path[row][col-1];
        }
    }
    cout << "Case #" << cnt << ": " << dp_path[R][C] << endl;
}

void solve_dp_2(){
    for(int row=1; row<=R+C; ++row){
        dp_path_2[row][1] = 1;
    }
    for(int col=1; col<=R+C; ++col){
        dp_path_2[1][col] = 1;
    }

    for(int sum=4; sum<=R+C; ++sum){
        for(int row=2; 2<=sum-row; ++row){
            int col = sum - row;
            for(int next_col=1; next_col<=row; ++next_col){
                assert(1<=row && row<=(MAX_ROW << 1) && 1<=col && col<=(MAX_COL << 1));
                dp_path_2[row][col] += dp_path_2[col-1][next_col];
            }
        }
    }
    cout << "Case #" << cnt << ": " << dp_path_2[R][C] << endl;
}

ll solve_dfs_2(int row, int col){
    // base case
    if(row == 1 || col == 1){
        return dp_path_2[row][col] = 1;
    }

    // memoization
    if(dp_path_2[row][col]){
        return dp_path_2[row][col];
    }

    // recurrence relation
    for(int next_col=1; next_col<=row; ++next_col){
        dp_path_2[row][col] += solve_dfs_2(col-1, next_col);
    }
    return dp_path_2[row][col];
}

void solve(){
    initialize();
    // visited[START_ROW][START_COL] = true;
    // solve_dfs({START_ROW, START_COL}, move_type);
    // cout << "Case #" << cnt << ": " << paths << endl;
    // dp_path[START_ROW][START_COL] = solve_dfs({START_ROW, START_COL}, move_type);
    // cout << "Case #" << cnt << ": " << dp_path[START_ROW][START_COL] << endl;



    // solve_dp_1();
    // solve_dp_2();

    cout << "Case #" << cnt << ": " << solve_dfs_2(R, C) << endl;
}

void input(){
    cin >> T;
    for(cnt=1; cnt<=T; ++cnt){
        cin >> R >> C;
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
