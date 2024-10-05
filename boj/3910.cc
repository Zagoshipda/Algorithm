/*
    https://www.acmicpc.net/problem/3910
    (power calculus)

    similar problem
        https://www.acmicpc.net/problem/2074
        (power hungry cows)

    solutions
        https://www.acmicpc.net/source/28864147
        (artichoke42, 128 ms) : queue

        https://www.acmicpc.net/source/23941023
        (xkdlaldfjtnl, 172 ms) : priority queue

        https://www.acmicpc.net/source/39866477
        (mjhmjh1104, 220 ms) : priority queue

        https://www.acmicpc.net/source/28866484
        (jthis, 148 ms) : dfs, implemented in solve_dfs()

        https://www.acmicpc.net/source/6990076
        (gub115, 280 ms) : dfs

    reference
        https://github.com/pkkj/ACM-ICPC-OJ-Code/blob/master/ICPC.Regional/2006.Yokohama/3621.cpp
*/

#include <bits/stdc++.h>
#include <chrono>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        - find the least number of operations to compute x^n by multiplication and division starting with x for the given positive integer n
        - Products and quotients appearing in the sequence of operations should be x to a positive integer's power (x^k : k > 0)

    Algorithm
        1'000 ~ 2^10
        at most 20 steps

        multiplication <-> add
        division <-> subtract

        1 2 4  8  16 32 64 128 256 512 1024 ...
        3 6 12 24 48 96 192 ...

        7(4) = 4(2) + 3(2)

        10(4) = 4(2) + 6(3)

        28(6) = 4(2) + 24(5)

        1  10  100  1000 ...
        11 110 1100 11000 ...
        111


        1
        2
        3 4
        5 6 7
        8 9 10 11
        12 13 14 15 16
        17...22
        23...29
        30...37



1
31  11111       5       6
70  1000110     7       8
91  1011011     7       9
473 111011001   9       11
512 1000000000  9       9
811 1100101011  10      13
953 1110111001  10      12

0001000110
000
0




*/

// const int MAX_POWER = 1'000 << 1;
const int MAX_POWER = 1'000;
const int INF = 15;
// const int MAX_SEARCH = MAX_POWER << 1;
const int MAX_SEARCH = 2'000;
// const int MAX_STEP = 15;    // 352 ms
const int MAX_STEP = 14;    // 168 ms

int T;
int n;

int dp[MAX_POWER << 2];
bool visited[MAX_SEARCH + 1];

// vector<pair<int, int> > powers; // (power, cnt)
// queue<pair<int, int> > nodes;   // (power, cnt)


void initialize(){

    // powers.push_back({1, 0});
    // nodes.push({1, 0});

    // for(int power=1; power<=MAX_POWER; ++power){
    //     dp[power] = INF;
    // }
    // dp[1] = 0;
}

// set<int> hashes;


void solve_bfs(){
    // initialize();

    vector<int> powers;
    queue<int> nodes;
    unordered_set<int> hashes;

    int step = 0;
    hashes.insert(1);
    powers.push_back(1);
    nodes.push(1);

    while(!nodes.empty()){
        // auto [curr, cnt] = nodes.front();
        // ++step;
        int len = nodes.size();
        while(len--){
            int curr = nodes.front();
            nodes.pop();

            ++step;
            int len_p = powers.size();

            // int next = curr << 1;
            // if(0 < next && next <= MAX_POWER && hashes.count(next) == 0){
            //     hashes.insert(next);
            //     dp[next] = step;
            //     powers.push_back(next);
            //     nodes.push(next);
            // }

            for(int ith=0; ith<len_p; ++ith){
                int next_1 = powers[ith] + curr;
                int next_2 = abs(powers[ith] - curr);
                if(0 < next_1 && next_1 <= MAX_POWER && hashes.count(next_1) == 0){
                    hashes.insert(next_1);
                    dp[next_1] = step;
                    powers.push_back(next_1);
                    nodes.push(next_1);
                }
                if(0 < next_2 && next_2 <= MAX_POWER && hashes.count(next_2) == 0){
                    hashes.insert(next_2);
                    dp[next_2] = step;
                    powers.push_back(next_2);
                    nodes.push(next_2);
                }
            }
        }


        // if(curr >= MAX_POWER){
        //     break;
        // }


        // ++step;
        // if(step >= MAX_POWER){
        //     break;
        // }
        // if(curr == n){
        //     cout << cnt << endl;
        //     break;
        // }

        // int next = curr + curr;
        // if(next <= MAX_POWER && cnt + 1 < dp[next]){
        //     dp[next] = cnt + 1;
        //     nodes.push({next, dp[next]});
        //     powers.push_back({next, dp[next]});
        // }

        // int len = powers.size();
        // for(int ith=0; ith<len; ++ith){
        //     next = powers[ith].first + curr;
        //     if(1 < next && next <= MAX_POWER && max(powers[ith].second, cnt) + 1 < dp[next]){
        //         // dp[next] = min(dp[next], powers[ith].second + cnt + 1);
        //         // dp[next] = powers[ith].second + cnt + 1;
        //         dp[next] = max(powers[ith].second, cnt) + 1;
        //         nodes.push({next, dp[next]});
        //         powers.push_back({next, dp[next]});
        //     }

        //     next = abs(powers[ith].first - curr);
        //     if(1 < next && next <= MAX_POWER && max(powers[ith].second, cnt) + 1 < dp[next]){
        //         // dp[next] = min(dp[next], powers[ith].second + cnt + 1);
        //         // dp[next] = powers[ith].second + cnt + 1;
        //         dp[next] = max(powers[ith].second, cnt) + 1;
        //         nodes.push({next, dp[next]});
        //         powers.push_back({next, dp[next]});
        //     }
        // }
    }
}

void solve_bfs_wrong(){
    vector<int> numbers;

    int step = 0;
    numbers.push_back(1);
    visited[1] = true;
    dp[1] = step;
    int cnt = 1;

    int len, next;

    while(cnt < MAX_SEARCH){
        // WRONG
        ++step;
        len = numbers.size();
        for(int first=0; first<len; ++first){
            for(int second=0; second<len; ++second){
                next = numbers[first] + numbers[second];
                if(1 < next && next <= MAX_SEARCH && !visited[next]){
                    visited[next] = true;
                    numbers.push_back(next);
                    // WRONG : step can be step[numbers[first]] + step[numbers[second]] or else ... (ex. 31 -> 6)
                    dp[next] = step;
                    ++cnt;
                }

                next = abs(numbers[first] - numbers[second]);
                if(1 < next && next <= MAX_SEARCH && !visited[next]){
                    visited[next] = true;
                    numbers.push_back(next);
                    dp[next] = step;
                    ++cnt;
                }
            }
        }
    }
    cout << "cnt : " << cnt << endl;
}

struct Node{
    int step;               // == numbers.size() - 1
    vector<int> numbers;
    // int numbers[INF + 1];

    bool operator>(const Node& node) const {
        return step > node.step;
    }
};

void solve_dijkstra_vector(){
    for(int num=1; num<=MAX_POWER; ++num){
        dp[num] = INF;
    }
    dp[1] = 0;

    priority_queue<Node, vector<Node>, greater<Node> > pq_min;
    pq_min.push({0, { 1 }});

    while(!pq_min.empty()){
        auto [cnt, nums] = pq_min.top();
        // auto curr = pq_min.top();
        pq_min.pop();

        int curr = nums.back();
        // int curr_num = curr.numbers[curr.step];

        // if(curr > MAX_POWER){
        //     continue;
        // }

        // WRONG
        // if(dp[curr] < cnt){
        // if(dp[curr] <= cnt){
        //     continue;
        // }

        // if(cnt < dp[curr]){
        //     dp[curr] = cnt;
        // }
        // dp[curr] = min(dp[curr], cnt);

        int len = nums.size();
        // int len = step + 1;
        vector<int> next_nums;
        next_nums = nums;
        int next_cnt = cnt + 1;
        // Node next = curr;
        for(int idx=0; idx<len; ++idx){
            int next_1 = curr + nums[idx];
            // next_nums = nums;

            if(1 < next_1 && next_1 <= MAX_POWER && next_cnt <= dp[next_1]){
            // if(1 < next_1 && next_1 <= MAX_POWER && next_cnt < dp[next_1]){
            // if(1 < next_1 && next_1 <= MAX_POWER && next_cnt < INF){
                next_nums.push_back(next_1);
                // dp[next_1] = min(dp[next_1], next_cnt);
                dp[next_1] = next_cnt;
                pq_min.push({next_cnt, next_nums});
                next_nums.pop_back();
            }


            int next_2 = abs(curr - nums[idx]);
            // int next_2 = curr - nums[idx];
            // next_nums = nums;
            // next_nums.push_back(next_2);
            if(1 < next_2 && next_2 <= MAX_POWER && next_cnt <= dp[next_2]){
            // if(1 < next_2 && next_2 <= MAX_POWER && next_cnt < dp[next_2]){
            // if(1 < next_2 && next_2 <= MAX_POWER && next_cnt < INF){
                next_nums.push_back(next_2);
                // dp[next_2] = min(dp[next_2], next_cnt);
                dp[next_2] = next_cnt;
                pq_min.push({next_cnt, next_nums});
                next_nums.pop_back();
            }
            // next_nums.pop_back();
        }
    }
}



struct Node_2{
    int size;
    int numbers[MAX_STEP << 1];
    int step;   // == size - 1

    bool operator>(const Node_2& node) const {
        return size > node.size;
    }
};

void solve_dijkstra_array(){
    for(int num=2; num<=MAX_POWER; ++num){
        dp[num] = MAX_STEP;
    }

    priority_queue<Node_2, vector<Node_2>, greater<Node_2> > pq_min;

    Node_2 start;
    start.size = 1;
    start.numbers[1] = 1;
    start.step = 0;

    pq_min.push(start);

    int cnt = 0;
    while(!pq_min.empty()){
        Node_2 curr = pq_min.top();
        pq_min.pop();
        // ++cnt;
        // cout << cnt << " ";

        // if(cnt > 1'000){
        //     cout << pq_min.size() << " " << curr.size << endl;
        //     cnt = 0;
        // }

        if(curr.size > MAX_STEP){
            break;
        }

        for(int pos=1; pos<=curr.size; ++pos){
            int next_num = curr.numbers[pos] + curr.numbers[curr.size];
            // if(1 < next_num && next_num <= MAX_SEARCH){
            // if(1 < next_num && next_num <= MAX_SEARCH && curr.size < dp[next_num]){
            if(1 < next_num && next_num <= MAX_SEARCH && curr.size <= dp[next_num]){
                // dp[next_num] = min(dp[next_num], curr.size);
                dp[next_num] = curr.size;

                Node_2 next = curr;
                next.size += 1;
                next.numbers[next.size] = next_num;
                next.step += 1;

                pq_min.push(next);
            }

            next_num = abs(curr.numbers[pos] - curr.numbers[curr.size]);
            // if(1 < next_num && next_num <= MAX_SEARCH){
            // if(1 < next_num && next_num <= MAX_SEARCH && curr.size < dp[next_num]){
            if(1 < next_num && next_num <= MAX_SEARCH && curr.size <= dp[next_num]){
                // dp[next_num] = min(dp[next_num], curr.size);
                dp[next_num] = curr.size;

                Node_2 next = curr;
                next.size += 1;
                next.numbers[next.size] = next_num;
                next.step += 1;

                pq_min.push(next);
            }
        }

        // for(int first=1; first<=curr.size; ++first){
        //     for(int second=first; second<=curr.size; ++second){
        //         int next_num = curr.numbers[first] + curr.numbers[second];
        //         // if(!visited[next_num]){
        //         //     visited[next_num] = true;
        //         // }
        //         if(1 < next_num && next_num <= MAX_SEARCH){
        //             dp[next_num] = min(dp[next_num], curr.size);

        //             Node_2 next = curr;
        //             next.size += 1;
        //             next.numbers[next.size] = next_num;
        //             next.step += 1;

        //             pq_min.push(next);
        //         }


        //         next_num = abs(curr.numbers[first] - curr.numbers[second]);
        //         // if(!visited[next_num]){
        //         //     visited[next_num] = true;
        //         // }
        //         if(1 < next_num && next_num <= MAX_SEARCH){
        //             dp[next_num] = min(dp[next_num], curr.size);

        //             Node_2 next = curr;
        //             next.size += 1;
        //             next.numbers[next.size] = next_num;
        //             next.step += 1;

        //             pq_min.push(next);
        //         }
        //     }
        // }
    }
}


// void dfs(int step, vector<int> path){   // 420 ms
void dfs(int step, vector<int>& path){  // 168 ms
    if(step >= MAX_STEP){
        return;
    }

    int len = path.size();
    for(int idx=0; idx<len; ++idx){
        int next_num = path[idx] + path[len - 1];
        if(1 < next_num && next_num <= MAX_SEARCH && step + 1 <= dp[next_num]){
            path.push_back(next_num);
            dp[next_num] = min(dp[next_num], step + 1);
            dfs(step + 1, path);
            path.pop_back();
        }

        next_num = abs(path[idx] - path[len - 1]);
        if(1 < next_num && next_num <= MAX_SEARCH && step + 1 <= dp[next_num]){
            path.push_back(next_num);
            dp[next_num] = min(dp[next_num], step + 1);
            dfs(step + 1, path);
            path.pop_back();
        }
    }

}

void solve_dfs(){
    for(int num=2; num<=MAX_SEARCH; ++num){
        dp[num] = 1'000;
    }

    vector<int> path;
    path.push_back(1);
    dfs(0, path);
}

void solve(){
    // solve_bfs();
    // solve_bfs_wrong();


    solve_dfs();


    // solve_dijkstra_vector();
    // solve_dijkstra_array();
}

void validate(){
    bitset<10> bs(31);
    cout << bs << endl;
    bs = 70;
    cout << bs << endl;
    bs = 91;
    cout << bs << endl;
    bs = 473;
    cout << bs << endl;
    bs = 512;
    cout << bs << endl;
    bs = 811;
    cout << bs << endl;
    bs = 953;
    cout << bs << endl;
}

void input(){
    cin >> T;

    auto time_3 = chrono::high_resolution_clock::now();
    solve();
    auto time_4 = chrono::high_resolution_clock::now();
    // cout << "ns : " << (time_4 - time_3).count() << endl;

    while(T--){
        cin >> n;

        cout << dp[n] << endl;
    }

    // for(int num=1; num<36; ++num){
    //     cout << dp[num] << " ";
    // }
    // cout << endl;
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    // solve();

    return 0;
}
