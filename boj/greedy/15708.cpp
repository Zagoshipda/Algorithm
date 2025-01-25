/*
    https://www.acmicpc.net/problem/15708
    (minecraft)

    solution
        priority queue
            https://www.acmicpc.net/source/19750893
            (queued_q, 16 ms)
            https://www.acmicpc.net/source/8648173
            (ntopia, 16 ms)

            https://www.acmicpc.net/board/view/105286
            https://blog.naver.com/rdd573/221270203173
            (official solution) : implemented in solve_greedy_2()

        parametric search, implemented in solve_parametric_search()
            https://www.acmicpc.net/source/56951413
            (tlsgusrb314, 532 ms)
            https://www.acmicpc.net/source/17889591
            (akswnd98, 176 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

const int NUM_ROCKS = 100'000;          // 10^5
const int MAX_TIME = 1'000'000'000;     // 10^9
const ll MAX_COST = 100'000;            // 10^5
const int START_POS = 1;

using p_li = pair<ll, int>;

ll N, T, P;
ll rocks[NUM_ROCKS + 1];

/*
    2 priority queues : pq_min_left, pq_min_right
    stack? (X)
    pq_min_left - current position - pq_min_right

    move from i to i+1
        pq_min_left.push(i)
        pq_min_right.pop()

    1st current_pos
        nth current_pos cost = (n-1) * P + rocks[nth]

    2nd current_pos
        nth current_pos cost = abs(n-2) * P + rocks[nth]

    3rd current_pos
        nth current_pos cost = abs(n-3) * P + rocks[nth]

    time complexity
    N ~ 1e5
    N^2 ~ 1e10 > 1s (X)

    can we go left(backwards)? (X)

    Observation
        minimum cost does not change
            since relative order (idx-1)*P + rocks[idx] does not change

    Idea 1.
        1. pick minimum costs from idx=1...N, in ascending index order
        2. pick minimum costs from idx=1...(current position) to fufill time T as much as possible

    Idea 2.
        use 2 priority queues
        make 1st priority queue with cost (idx-1)*P + rocks[idx] of each rocks
        make 2nd priority queue with cost rocks[idx] with idx < current position
            considering passed rocks, only need to consider its own cost
            cost for moving to such rock is now free (idx-1)*P = 0
        get rocks with the minimum cost for each 2 priority queues,
        take the one with smaller cost



    Algorithm
        ki + (P per moves)
        assume max rock[k1...kj]
        => greedy choice for each position
        N ~ 10^5
        move to right => cost order NOT change

        (range query)
        take k-minimum rocks in range [1...x]

6 1 1
3 5 2 6 9 1

// 0


7 25 2
3 1 5 2 4 1 1

0 2 4 6 8 10 12
3 3 9 8 12 11 13
// 6 (O)
// 5 (X)


*/

int cap;
void solve_wrong_2(){
    priority_queue<p_li, vector<p_li>, greater<p_li> > pq_min_3;  // (cost, index)
    for(int ith=1; ith<=N; ++ith){
        pq_min_3.push({rocks[ith] + P * (ith - 1), ith});
    }

    int width = 0;
    ll moves = 0;
    ll sum_rocks = 0;
    while(cap && !pq_min_3.empty()){
        auto [cost, idx] = pq_min_3.top();
        pq_min_3.pop();

        width = max(width, idx - 1);
        moves = P * width;
        sum_rocks += rocks[idx];

        if(cap < moves + sum_rocks){
            cout << N - (pq_min_3.size() + 1) << endl;
            break;
        }
    }
}

priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq_min;
priority_queue<ll, vector<ll>, greater<ll> > pq_min_2;
void solve_wrong_1(){
    for(int idx=START_POS; idx<=N; ++idx){
        pq_min.push({(idx-1)*P + rocks[idx], idx});
    }

    int max_rock = 0;
    int current_pos = 0;    // initialize as 0
    while(T > 0){
        // 1. find next greedy choice
        ll cost_1;
        int idx = -1;
        while(!pq_min.empty()){
            cost_1 = pq_min.top().first;
            idx = pq_min.top().second;
            if(current_pos < idx){
                break;
            }
            pq_min.pop();
        }

        // 2. if there are no previously unchosen rocks
        if(pq_min_2.empty()){
            if(idx < 0){
                break;
            }
            else{
                // NOTE : convert to real distance
                cost_1 = (idx-current_pos)*P + rocks[idx];
                if(cost_1 <= T){
                    ++max_rock;
                    T -= cost_1;
                    pq_min.pop();
                    for(int pos=current_pos+1; pos<idx; ++pos){
                        pq_min_2.push(rocks[pos]);
                    }
                    current_pos = idx;
                }
                else{   // cost_1 > T
                    break;
                }
            }
        }
        // 3. if there exist previously unchosen rocks
        else{
            ll cost_2 = pq_min_2.top();
            // only previous choice is possible
            if(idx < 0){
                if(cost_2 <= T){
                    ++max_rock;
                    T -= cost_2;
                    pq_min_2.pop();
                }
                else{
                    break;
                }
            }
            else{
                // NOTE : convert to real distance
                cost_1 = (idx-current_pos)*P + rocks[idx];
                // compare next greedy choice vs previous greedy choice
                if(cost_1 <= cost_2 && cost_1 <= T){
                    ++max_rock;
                    T -= cost_1;
                    pq_min.pop();
                    for(int pos=current_pos+1; pos<idx; ++pos){
                        pq_min_2.push(rocks[pos]);
                    }
                    current_pos = idx;
                }
                else if(cost_2 < cost_1 && cost_2 <= T){
                    ++max_rock;
                    T -= cost_2;
                    pq_min_2.pop();
                }
                else{
                    break;
                }
            }
        }

    }

    cout << max_rock << endl;
}

/*
    from idx=1...K
    take min values from sum(rocks[1...K]) <= T

    T for rocks[1]
    T-P*1 for rocks[1...2]
    T-P*2 for rocks[1...3]
    ...
    T-P*(N-1) for rocks[1...N]

    DP : choose ith rock or not
    greedy choice ?
        rocks[1...K] ~ rocks[1...K+1]
        T-P*(K-1) ~ T-P*(K)
        it is the same to choose the smallest numbers,
        just remove the biggest chosen numbers if (T-P*(K)) - (T-P*(K-1)) = -P exceeds remaining [T-P*(K-1) - rocks[1...K]]
*/

priority_queue<ll, vector<ll>, less<ll> > pq_max_yes;
priority_queue<ll, vector<ll>, greater<ll> > pq_min_no;
void solve_greedy_1(){
    int max_rock = 0;
    for(int idx=1; idx<=N; ++idx, T -= P){
        pq_min_no.push(rocks[idx]);

        while(true){
            ll lower = -1, upper = -1;
            if(pq_max_yes.empty()){
                upper = pq_min_no.top();
                if(upper <= T){
                    T -= upper;
                    ++max_rock;
                    pq_max_yes.push(upper);
                    pq_min_no.pop();
                }
                else{
                    break;
                }
            }
            else{
                if(pq_min_no.empty()){
                    break;
                }
                lower = pq_max_yes.top();
                upper = pq_min_no.top();

                if(lower <= upper){
                    if(upper <= T){
                        T -= upper;
                        ++max_rock;
                        pq_max_yes.push(upper);
                        pq_min_no.pop();
                    }
                    else{
                        break;
                    }
                }
                else{   // lower > upper
                    pq_max_yes.pop();
                    pq_min_no.pop();

                    // exchange values
                    pq_max_yes.push(upper);
                    pq_min_no.push(lower);
                    T += lower;
                    T -= upper;
                }
            }
        }
    }

    cout << max_rock << endl;
}

void solve_greedy_2(){
    priority_queue<ll, vector<ll>, less<ll> > pq_max;

    ll cost_1 = 0;
    ll cost_2 = 0;
    int max_rock = 0;
    for(int idx=1; idx<=N; ++idx){
        pq_max.push(rocks[idx]);

        cost_1 += rocks[idx];
        cost_2 = (idx - 1) * P;

        // if(T <= cost_2){
        //     break;
        // }

        // while(!pq_max.empty() && T < cost_1 + cost_2){
        if(!pq_max.empty() && T < cost_1 + cost_2){
            cost_1 -= pq_max.top();
            pq_max.pop();
        }

        max_rock = max(max_rock, static_cast<int>(pq_max.size()));
    }

    cout << max_rock << endl;
}

bool is_possible(int target){
    priority_queue<ll, vector<ll>, less<ll> > pq_max;
    ll cost_1 = 0;
    ll cost_2;
    for(int ith=1; ith<=N; ++ith){
        pq_max.push(rocks[ith]);
        cost_1 += rocks[ith];
        cost_2 = (ith - 1) * P;

        // if(T <= cost_2){
        //     break;
        // }

        while(!pq_max.empty() && T < cost_1 + cost_2){
            cost_1 -= pq_max.top();
            pq_max.pop();
        }

        if(pq_max.size() == target){
            return true;
        }
    }

    return false;
}

void solve_parametric_search(){
    int max_rock = 0;
    for(int left=1, right=N; left<=right; ){
        int middle = (left + right) >> 1;

        if(is_possible(middle)){
            max_rock = max(max_rock, middle);
            left = middle + 1;
        }
        else{
            right = middle - 1;
        }
    }

    cout << max_rock << endl;
}

void solve(){
    // solve_wrong_1();
    // solve_wrong_2();

    // solve_greedy_1();
    solve_greedy_2();

    // solve_parametric_search();
}

void input(){
    cin >> N >> T >> P;
    cap = T;
    for(int idx=1; idx<=N; ++idx){
        cin >> rocks[idx];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
