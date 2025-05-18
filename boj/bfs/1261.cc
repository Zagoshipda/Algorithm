/*
    https://www.acmicpc.net/problem/1261
    (algospot)
*/

#include <iostream>
#include <queue>
#include <climits>
#include <deque>

#define endl '\n'

/*
    Algorithm

6 6
000000
011110
010000
110111
000010
100010

*/

const int MAX_HEIGHT = 100;
const int MAX_WIDTH = 100;
const int NUM_MOVE = 4;
const int INF = INT_MAX >> 1;

using p_ii = std::pair<int, int>;
struct ROOM{
    int row;
    int col;
    int cnt;
};
enum TYPES{
    room_empty  = 0,
    room_wall   = 1,
};
p_ii moves[] = {
    {-1, 0},
    {+1, 0},
    {0, -1},
    {0, +1},
};

int M, N;
std::string state;
int maze[MAX_HEIGHT << 1][MAX_WIDTH << 1];
int min_cnt[MAX_HEIGHT << 1][MAX_WIDTH << 1];

bool check_range(int row, int col){
    return (1 <= row && row <= N) && (1 <= col && col <= M);
}

void initialize(){
    for(int row=1; row<=N; ++row){
        for(int col=1; col<=M; ++col){
            min_cnt[row][col] = INF;
        }
    }
    min_cnt[1][1] = 0;
}

void solve_bfs(){
    initialize();

    int min_wall = INF;

    std::queue<ROOM> que;
    que.push({1, 1, 0});
    while(!que.empty()){
        auto [curr_r, curr_c, curr_cnt] = que.front();
        que.pop();

        if(min_cnt[curr_r][curr_c] < curr_cnt){
            continue;
        }

        if(curr_r == N && curr_c == M){
            min_wall = std::min(min_wall, curr_cnt);
            continue;
        }

        for(int ith=0; ith<NUM_MOVE; ++ith){
            auto [move_r, move_c] = moves[ith];
            int next_r = curr_r + move_r;
            int next_c = curr_c + move_c;
            if(check_range(next_r, next_c)){
                if(maze[next_r][next_c] == room_empty && curr_cnt < min_cnt[next_r][next_c]){
                    min_cnt[next_r][next_c] = curr_cnt;
                    que.push({next_r, next_c, curr_cnt});
                }
                else if(maze[next_r][next_c] == room_wall && curr_cnt + 1 < min_cnt[next_r][next_c]){
                    min_cnt[next_r][next_c] = curr_cnt + 1;
                    que.push({next_r, next_c, curr_cnt + 1});
                }
            }
        }
    }

    std::cout << min_wall << endl;
}

void solve_01_bfs(){
    initialize();

    std::deque<ROOM> deq;
    deq.push_front({1, 1, 0});

    while(!deq.empty()){
        auto [curr_r, curr_c, curr_cnt] = deq.front();
        deq.pop_front();

        if(min_cnt[curr_r][curr_c] < curr_cnt){
            continue;
        }

        if(curr_r == N && curr_c == M){
            std::cout << curr_cnt << endl;
            break;
        }

        for(int ith=0; ith<NUM_MOVE; ++ith){
            int next_r = curr_r + moves[ith].first;
            int next_c = curr_c + moves[ith].second;
            if(check_range(next_r, next_c)){
                if(maze[next_r][next_c] == room_empty && curr_cnt < min_cnt[next_r][next_c]){
                    min_cnt[next_r][next_c] = curr_cnt;
                    deq.push_front({next_r, next_c, curr_cnt});
                }
                else if(maze[next_r][next_c] == room_wall && curr_cnt + 1 < min_cnt[next_r][next_c]){
                    min_cnt[next_r][next_c] = curr_cnt + 1;
                    deq.push_back({next_r, next_c, curr_cnt + 1});
                }
            }
        }
    }
}



struct Edge{
    int row;
    int col;
    int weight;
};
std::vector<Edge> graph[MAX_HEIGHT << 1][MAX_WIDTH << 1];
int min_dist[MAX_HEIGHT << 1][MAX_WIDTH << 1];

void build_graph(){
    for(int row=1; row<=N; ++row){
        for(int col=1; col<=M; ++col){
            for(int ith=0; ith<NUM_MOVE; ++ith){
                int next_r = row + moves[ith].first;
                int next_c = col + moves[ith].second;
                if(check_range(next_r, next_c)){
                    int weight = (maze[next_r][next_c] == room_empty) ? 0 : 1;
                    graph[row][col].push_back({next_r, next_c, weight});
                    weight = (maze[row][col] == room_empty) ? 0 : 1;
                    graph[next_r][next_c].push_back({row, col, weight});
                }
            }

            min_dist[row][col] = INF;
        }
    }
}

struct Node{
    int row;
    int col;
    int dist;

    bool operator>(const Node& node) const {
        return dist > node.dist;
    }
};

void solve_dijkstra(){
    build_graph();

    std::priority_queue<Node, std::vector<Node>, std::greater<Node> > pq_min;
    min_dist[1][1] = 0;
    pq_min.push({1, 1, 0});
    while(!pq_min.empty()){
        auto [curr_r, curr_c, curr_dist] = pq_min.top();
        pq_min.pop();

        if(min_dist[curr_r][curr_c] < curr_dist){
            continue;
        }

        if(curr_r == N && curr_c == M){
            std::cout << curr_dist << endl;
            break;
        }

        for(Edge edge : graph[curr_r][curr_c]){
            auto [next_r, next_c, edge_weight] = edge;
            int next_dist = min_dist[curr_r][curr_c] + edge_weight;
            if(next_dist < min_dist[next_r][next_c]){
                min_dist[next_r][next_c] = next_dist;
                pq_min.push({next_r, next_c, next_dist});
            }
        }
    }
}

void solve(){
    // solve_bfs();            // 4 ms

    solve_01_bfs();         // 0 ms

    // solve_dijkstra();       // 4 ms
}

void input(){
    std::cin >> M >> N;
    for(int row=1; row<=N; ++row){
        std::cin >> state;
        for(int col=1; col<=M; ++col){
            maze[row][col] = state[col - 1] - '0';
        }
    }
}

int main(){

    input();

    solve();

    return 0;
}
