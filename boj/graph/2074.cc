/*
    https://www.acmicpc.net/problem/2074
    (power hungry cows)

    solution
        https://www.acmicpc.net/source/48520084
        (lycka, 80 ms) : array index error ?

    reference
        https://blog.csdn.net/tigerisland45/article/details/105542684
*/

#include <bits/stdc++.h>
#include <chrono>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        two work variables for intermediate results
        all results are stored as integers

        start : 0, 1
        target : P
        operation : +, - (power)
            multiply <=> add
            divide <=> subtract
        => find the minimum number of operations to calculate the power P

    Algorithm
        P range
            20'000 ~ 2 * 10^4 ~ 2 * 10 * 10^3 ~ 2 * 2^4 * 2^10 ~ 2^15

        NOTE : only 2 variables

        space
            128 MB ~ 10^2 * 10^6 ~ 10^8

        time
            1's ~ 10^8

        ex.
        31 = 11111 (2) = 100000 - 1 (2)
            1 + 1 = 2
            2 + 2 = 4
            4 + 4 = 8
            8 + 8 = 16
            16 + 16 = 32
            32 - 1 = 31
            => 6 steps

        (observation)
            max # operation
            considering a binary representation,
            1 <=> add 1
            0 <=> bit shift left (add itself, multiply by 2)

            naive approach : 2 steps for each 1 bit
            => max 2 log(P) steps for given P
            => max 30 steps

            ex.
            31 = 11111 (2)


        graph traversal ?
            nodes as each power
            for each power k, can go to k-1 k-2 ... ?
            for each pair (a, b)
                (a + a, b)
                (a, a + a)
                (b + b, b)
                (a, b + b)
                (a + b, b)
                (a, a + b)
                => 6 choices
                => brute force

                (x y) => P

            2^20 = 1'048'576 ~ O(10^6)

        DP ?
        S ubproblem
            dp[k] : min operations to k
        R eucurrence relation
            how to become k ?
                add
                    k-1 + 1
                    k-2 + 2
                    ...
                    k/2 + k/2
                    ...
                    2 + k-2
                    1 + k-1

                subtract
                    k+1 - 1
                    k+2 - 2
                    k+3 - 3
                    ...
                    k+k-1 - k-1
                    k+k - k (non-sense, since we are finding k)

            dp[k] =
                min(dp[k-i] + i) for i=1...k/2
                min(dp[k+i] - i) for i=1...k-1
        T opological order
            for k=0...P
        B ase case
            dp[0] = 0
            dp[1] = 0
        O riginal problem
            dp[P]
        T ime complexity
            P ~ O(10^4)
            # subproblems : O(P)
            operations per subproblem : O(P)
            total : O(P^2) ~ O(10^8) ?


ex.

4813	15
7763	16
9311	16
14159	17
14709	17
14719	17
15281	17
17651	17
17893	17
18047	17
18071	17
18385	17
18815	17
18817	17
19839	17


4813
7763
9311
14159
14709
14719
15281
17651
17893
18047
18071
18385
18815
18817
19839

*/

const int MAX_POWER = 21'000;      // 2 * 10^4
// const int MIN_POWER = MAX_POWER >> 1;  // 1 * 10^4
const int MIN_POWER = 10'000;  // 1 * 10^4

const int MAX_STEP = 18;    // heuristic limit

struct State{
    int power_1;
    int power_2;
    int step;

    bool operator<(const State& state) const {
        return this->step < state.step;
    }
};

int P;
ll steps;

pair<int, int> weights[] = {
    {2, 0},
    {0, 2},
    {1, 1},
    {1, -1},
};

queue<State> nodes;
// priority_queue<State, vector<State>, greater<State> > pq_min;

// bool visited[MIN_POWER + 1][MAX_POWER + 1];     // 2 * 10^8
// set<pair<int, int> > hashes;
unordered_set<int> hashes[MIN_POWER + 1];

void process(int num_1, int num_2, int cnt){
    // if(num_1 == P || num_2 == P){
    //     return true;
    // }

    if(num_1 == 0 && num_2 == 0){
        return;
    }
    if(P % gcd(num_1, num_2)){
        return;
    }

    int max_num = max(num_1, num_2);
    int min_num = min(num_1, num_2);

    // if(max_num < (P >> (MAX_STEP - cnt))){   // 1568 ms
    if(max_num < (P >> (17 - cnt))){            // 388 ms
        return;
    }
    // if(!hashes.count({min_num, max_num})){
    //     hashes.insert({min_num, max_num});
    //     nodes.push({min_num, max_num, cnt});
    // }

    // if(min_num <= MIN_POWER && max_num <= MAX_POWER && !visited[min_num][max_num]){
    // if(min_num <= MIN_POWER && max_num <= MAX_POWER && hashes[min_num].count(max_num) == 0){
    if(min_num <= MIN_POWER && hashes[min_num].count(max_num) == 0){
        nodes.push({min_num, max_num, cnt});
        // visited[min_num][max_num] = true;
        hashes[min_num].insert(max_num);
    }
}

void solve_bfs(){
    nodes.push({0, 1, 0});
    // visited[0][1] = true;
    // hashes.insert({0, 1});
    hashes[0].insert(1);

    while(!nodes.empty()){
        auto [val_1, val_2, cnt] = nodes.front();
        nodes.pop();
        ++steps;

        // if(val_1 == P || val_2 == P){
        //     // cout << nodes.size() << endl;
        //     cout << cnt << endl;
        //     break;
        // }
        // if(val_1 == 0 && val_2 == 0){
        //     continue;
        // }
        // if(val_2 < (P >> (MAX_STEP - cnt))){
        //     continue;
        // }

        // if(val_1 > MIN_POWER || val_2 > MAX_POWER){
        //     continue;
        // }

        // int next_max, next_min;

        // next_max = max(val_1 + val_1, val_2);
        // next_min = min(val_1 + val_1, val_2);

        // if(next_min <= MIN_POWER && next_max <= MAX_POWER && !visited[next_min][next_max]){
        //     visited[next_min][next_max] = true;
        //     nodes.push({next_min, next_max, cnt});
        // }

        bool is_found = false;

        for(int ith=0; ith<4; ++ith){
            int num_1 = abs(weights[ith].first * val_1 + weights[ith].second * val_2);
            int num_2 = val_2;
            if(num_1 == P || num_2 == P){
                cout << cnt + 1 << endl;
                is_found = true;
                break;
            }
            else{
                process(num_1, num_2, cnt + 1);
            }
        }
        if(is_found){
            break;
        }
        for(int ith=0; ith<4; ++ith){
            int num_1 = val_1;
            int num_2 = abs(weights[ith].first * val_1 + weights[ith].second * val_2);
            if(num_1 == P || num_2 == P){
                cout << cnt + 1 << endl;
                is_found = true;
                break;
            }
            else{
                process(num_1, num_2, cnt + 1);
            }
        }
        if(is_found){
            break;
        }

        // if(process(val_1, val_1 + val_1, cnt + 1)){
        //     cout << cnt + 1 << endl;
        //     break;
        // }

        // if(process(val_2 + val_2, val_2, cnt + 1)){
        //     cout << cnt + 1 << endl;
        //     break;
        // }
        // if(process(val_1, val_2 + val_2, cnt + 1)){
        //     cout << cnt + 1 << endl;
        //     break;
        // }

        // if(process(val_1 + val_2, val_2, cnt + 1)){
        //     cout << cnt + 1 << endl;
        //     break;
        // }
        // if(process(val_1, val_1 + val_2, cnt + 1)){
        //     cout << cnt + 1 << endl;
        //     break;
        // }

        // if(process(abs(val_1 - val_2), val_2, cnt + 1)){
        //     cout << cnt + 1 << endl;
        //     break;
        // }
        // if(process(val_1, abs(val_1 - val_2), cnt + 1)){
        //     cout << cnt + 1 << endl;
        //     break;
        // }

        // is_found = is_found || process(val_1 + val_1, val_2, cnt + 1);
        // is_found = is_found || process(val_1, val_1 + val_1, cnt + 1);

        // is_found = is_found || process(val_2 + val_2, val_2, cnt + 1);
        // is_found = is_found || process(val_1, val_2 + val_2, cnt + 1);

        // is_found = is_found || process(val_1 + val_2, val_2, cnt + 1);
        // is_found = is_found || process(val_1, val_1 + val_2, cnt + 1);

        // is_found = is_found || process(abs(val_1 - val_2), val_2, cnt + 1);
        // is_found = is_found || process(val_1, abs(val_1 - val_2), cnt + 1);

        // if(is_found){
        //     // cout << "size : " << nodes.size() << endl;
        //     cout << cnt + 1 << endl;
        //     break;
        // }
    }

    // cout << "steps : " << steps << endl;
}

int min_step = INT_MAX;
bool dfs(int num_1, int num_2, int cnt, int limit){
    ++steps;
    if(num_1 == 0 && num_2 == 0 || cnt > limit){
        return false;
    }
    if(num_2 < (P >> (limit - cnt))){
        return false;
    }
    if(P % gcd(num_1, num_2)){
        return false;
    }

    if(num_1 == P || num_2 == P){
        // cout << num_1 << " " << num_2 << " " << cnt << endl;
        // min_step = min(min_step, cnt);
        // min_step = cnt;
        return true;
    }

    // bool is_found = false;
    int next_1, next_2;

    next_1 = min(num_1, num_1 << 1);
    next_2 = max(num_1, num_1 << 1);
    // is_found = is_found || dfs(next_1, next_2, cnt + 1);
    // dfs(next_1, next_2, cnt + 1);
    if(dfs(next_1, next_2, cnt + 1, limit)){
        return true;
    }
    next_1 = min(num_1 << 1, num_2);
    next_2 = max(num_1 << 1, num_2);
    // is_found = is_found || dfs(next_1, next_2, cnt + 1);
    // dfs(next_1, next_2, cnt + 1);
    if(dfs(next_1, next_2, cnt + 1, limit)){
        return true;
    }

    next_1 = min(num_1, num_2 << 1);
    next_2 = max(num_1, num_2 << 1);
    // dfs(next_1, next_2, cnt + 1);
    // is_found = is_found || dfs(next_1, next_2, cnt + 1);
    if(dfs(next_1, next_2, cnt + 1, limit)){
        return true;
    }
    next_1 = min(num_2 << 1, num_2);
    next_2 = max(num_2 << 1, num_2);
    // dfs(next_1, next_2, cnt + 1);
    // is_found = is_found || dfs(next_1, next_2, cnt + 1);
    if(dfs(next_1, next_2, cnt + 1, limit)){
        return true;
    }

    next_1 = min(num_1, num_1 + num_2);
    next_2 = max(num_1, num_1 + num_2);
    // dfs(next_1, next_2, cnt + 1);
    // is_found = is_found || dfs(next_1, next_2, cnt + 1);
    if(dfs(next_1, next_2, cnt + 1, limit)){
        return true;
    }
    next_1 = min(num_1 + num_2, num_2);
    next_2 = max(num_1 + num_2, num_2);
    // dfs(next_1, next_2, cnt + 1);
    // is_found = is_found || dfs(next_1, next_2, cnt + 1);
    if(dfs(next_1, next_2, cnt + 1, limit)){
        return true;
    }

    next_1 = min(num_1, abs(num_1 - num_2));
    next_2 = max(num_1, abs(num_1 - num_2));
    // dfs(next_1, next_2, cnt + 1);
    // is_found = is_found || dfs(next_1, next_2, cnt + 1);
    if(dfs(next_1, next_2, cnt + 1, limit)){
        return true;
    }
    next_1 = min(abs(num_1 - num_2), num_2);
    next_2 = max(abs(num_1 - num_2), num_2);
    // dfs(next_1, next_2, cnt + 1);
    // is_found = is_found || dfs(next_1, next_2, cnt + 1);
    if(dfs(next_1, next_2, cnt + 1, limit)){
        return true;
    }

    return false;
}

void solve_dfs(){
    steps = 0;
    for(int limit=0; limit<=MAX_STEP; ++limit){
        if(dfs(0, 1, 0, limit)){
            cout << limit << endl;
            // cout << "steps : " << steps << endl;
            break;
        }
    }

    // cout << min_step << endl;
}

void solve(){
    // auto time_1 = chrono::high_resolution_clock::now();
    solve_bfs();    // 424 ms
    // auto time_2 = chrono::high_resolution_clock::now();
    // cout << "ns : " << (time_2 - time_1).count() << endl;

    // auto time_3 = chrono::high_resolution_clock::now();
    // solve_dfs(); // 48 ms
    // auto time_4 = chrono::high_resolution_clock::now();
    // cout << "ns : " << (time_4 - time_3).count() << endl;
}

void input(){
    cin >> P;
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
