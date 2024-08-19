/*
    https://www.acmicpc.net/problem/18783
    (swapity swapity swap)

    similar problem
        permutation cycle
            https://www.acmicpc.net/problem/22863
            (recovery - large)
            https://www.acmicpc.net/problem/6505
            (decode the strings)

        sparse table
            https://www.acmicpc.net/problem/3117
            (youtube)

    solutions
        permutation cycle
            https://www.acmicpc.net/source/20916682
            (alex9801, 16 ms)
            https://www.acmicpc.net/source/47817461
            (leeh18, 12 ms) : just calculate the remainder only once
            https://www.acmicpc.net/source/35395136
            (jh05013, 224 ms)

        sparse table
            https://www.acmicpc.net/source/23969869
            (palilo, 16 ms) : space optimization with online update
                jump[2][N]
                - log(K) => 2 : only using current & previous table
                - update each step while checking binary bit of K

            https://www.acmicpc.net/source/19042747
            (kdh9949, 16 ms) : operator overloading, change vector directly
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        (permutation) i-th cow from the left has label i for each 1 <= i <= N
        repeat K times:
            M-step process (reverse Li...Ri)

    Algorithm
        partial permutation (Li, Ri)
        reverse the order ?
        N ~ O(10^5)
        N^2 ~ O(10^10) => time exceeded

        IDEA : do M-step 1-time, find the "permutation rule" for (repeating M-step) K-times
            record a M-step result
            repaet K times

        - find (permutation) cycles,
        - take K modular the length of a cycle (remainder r = K % cycle),
        - place each item in each cycle using remainder r (process cycle r times is just enough)

    ex.
    1 2 3 4 5 6 7 (initial)

    1 5 4 3 2 6 7
    1 5 7 6 2 3 4 (M-step, 1-time)

    1 2 6 7 5 3 4
    1 2 4 3 5 7 6 (M-step, 2-time)

    ... (repetitive process)

*/

const int ARR_SIZE = 100'000;   // 10^5
const int NUM_RANGES = 100;             // 10^2
const int MAX_REPEAT = 1'000'000'000;   // 10^9

const int MAX_POWER = 30;

int N, M, K;
int L, R;
pair<int, int> ranges[NUM_RANGES + 1];  // (L_i, R_i)

int perm[ARR_SIZE + 1];
int result[ARR_SIZE + 1];

void initialize(){
    for(int idx=1; idx<=N; ++idx){
        perm[idx] = idx;
    }
}

void print_result(){
    for(int idx=1; idx<=N; ++idx){
        cout << result[idx] << endl;
    }
}

bool visited[ARR_SIZE + 1];
vector<int> graph[ARR_SIZE + 1];    // adjacency list with cycles

void dfs(int root, int curr){
    visited[curr] = true;
    graph[root].push_back(curr);

    if(!visited[perm[curr]]){
        dfs(root, perm[curr]);
    }
}

void solve_permutation_cycle_graph(){
    initialize();

    // 1 time (M-step) simulation
    for(int idx=1; idx<=M; ++idx){
        // NOTE : index [start, end)
        // reverse(perm + ranges[idx].first, perm + ranges[idx].second);     // WRONG
        reverse(perm + ranges[idx].first, perm + ranges[idx].second + 1);   // AC
    }

    // dfs to build graph with cycles of length = 1 2 3 ...
    for(int idx=1; idx<=N; ++idx){
        if(!visited[idx]){
            dfs(idx, idx);
        }
    }

    // apply (K % cycle)-step simulation (= K-step simulation) to each cycle
    for(int idx=1; idx<=N; ++idx){
        int len = graph[idx].size();
        if(len){
            int remainder = K % len;
            // if(remainder){  // WRONG : must consider identity permutation
                for(int jdx=0; jdx<len; ++jdx){
                    // graph[idx][jdx] : current position
                    // graph[idx][(jdx + remainder) % len] : k-th next position after the process
                    result[graph[idx][jdx]] = graph[idx][(jdx + remainder) % len];
                }
            // }
        }
    }

    print_result();
}

void solve_permutation_cycle_array(){
    // initialize
    initialize();

    // 1 time (M-step) process
    for(int ith=1; ith<=M; ++ith){
        auto [start, end] = ranges[ith];
        // for(int left=start, right=end; left<right; ++left, --right){
        //     swap(perm[left], perm[right]);
        // }
        reverse(perm + start, perm + end + 1);
    }

    // permutation cycle decomposition
    for(int ith=1; ith<=N; ++ith){
        vector<int> cycle;
        if(!visited[ith]){
            // find a cycle
            int pos = ith;
            while(!visited[pos]){
                visited[pos] = true;
                cycle.push_back(pos);

                pos = perm[pos];
            }

            // repeat K times the process on a cycle
            int len = cycle.size();
            // int remainder = K % len;
            for(int idx=0; idx<len; ++idx){
                // cycle[idx] : current position
                // cycle[(idx + remainder) % len] : k-th next position after the process
                // result[cycle[idx]] = cycle[(idx + remainder) % len];
                result[cycle[idx]] = cycle[(idx + K) % len];
            }
        }
    }

    // result after K times the process
    print_result();
}

int sparse_table[MAX_POWER + 1][ARR_SIZE + 1];
void solve_sparse_table(){
    initialize();

    // 1 time (M-step) process
    for(int ith=1; ith<=M; ++ith){
        reverse(perm + ranges[ith].first, perm + ranges[ith].second + 1);
    }
    for(int idx=1; idx<=N; ++idx){
        sparse_table[0][idx] = perm[idx];
    }

    // bottom up DP
    for(int power=1; power<=MAX_POWER; ++power){
        for(int ith=1; ith<=N; ++ith){
            sparse_table[power][ith] = sparse_table[power-1][sparse_table[power-1][ith]];
        }
    }

    // result after K times the process
    for(int ith=1; ith<=N; ++ith){
        int power = 0;
        int pos = ith;
        int repeat = K;
        while(repeat){
            if(repeat & 1){
                pos = sparse_table[power][pos];
            }
            repeat >>= 1;
            power += 1;
        }
        cout << pos << endl;
    }
}

void solve(){
    // solve_permutation_cycle_graph();

    solve_permutation_cycle_array();     // 12 ms

    // solve_sparse_table();                   // 52 ms
}

void input(){
    cin >> N >> M >> K;
    for(int ith=1; ith<=M; ++ith){
        cin >> L >> R;
        ranges[ith] = {L, R};
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
