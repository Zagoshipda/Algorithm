/*
    https://www.acmicpc.net/problem/30024
    (corn field)
*/


#include <iostream>
#include <queue>
#include <vector>

#define endl '\n'

/*
    Specification
        - distinct integer 1...N*M


ex.

1 3
1 2 3
3
// 1 3
// 1 2
// 1 2 (X)


3 1
3
2
1
3
// 1 1
// 1 1 (X)
// 2 1

*/

const int NUM_ROW = 1'000;
const int NUM_COL = 1'000;

using coord = std::pair<int, std::pair<int, int> >;   // (val, row, col)

int N, M;
int corns[NUM_ROW + 1][NUM_COL + 1];
int K;

bool visited[NUM_ROW + 1][NUM_COL + 1];
std::priority_queue<coord, std::vector<coord>, std::less<coord> > pq_max;

std::pair<int, int> moves[] = {
    {+1, 0},
    {-1, 0},
    {0, +1},
    {0, -1},
};

bool check_range(int row, int col){
    return (1 <= row && row <= N) && (1 <= col && col <= M);
}

void solve(){
    // WRONG
    // for(int row=1; row<=N; ++row){
    //     pq_max.push({corns[row][1], {row, 1}});
    //     pq_max.push({corns[row][M], {row, M}}); // error : 1 == M
    //     visited[row][1] = true;
    //     visited[row][M] = true;
    // }
    // for(int col=2; col<M; ++col){
    //     pq_max.push({corns[1][col], {1, col}});
    //     pq_max.push({corns[N][col], {N, col}}); // error : 1 == N
    //     visited[1][col] = true;
    //     visited[N][col] = true;
    // }

    while(K--){
        auto [val, curr] = pq_max.top();
        pq_max.pop();

        std::cout << curr.first << " " << curr.second << endl;

        for(auto move : moves){
            int next_row = curr.first + move.first;
            int next_col = curr.second + move.second;

            if(check_range(next_row, next_col) && !visited[next_row][next_col]){
                pq_max.push({corns[next_row][next_col], {next_row, next_col}});
                visited[next_row][next_col] = true;
            }
        }
    }
}

void input(){
    std::cin >> N >> M;
    for(int row=1; row<=N; ++row){
        for(int col=1; col<=M; ++col){
            std::cin >> corns[row][col];
            if(row == 1 || row == N || col == 1 || col == M){
                pq_max.push({corns[row][col], {row, col}});
                visited[row][col] = true;
            }
        }
    }
    std::cin >> K;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    input();

    solve();

    return 0;
}
