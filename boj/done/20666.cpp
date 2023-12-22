/*
    https://www.acmicpc.net/problem/20666
    (monster game)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define NUM_MONSTER 100'000
#define MAX_LEVEL 1'000'000'000
#define NUM_TIPS 300'000
int N, M;   // _idx, # of targets
ll levels[NUM_MONSTER + 1];
int p;
ll a, b, t;
vector<pair<int, ll> > penalties[NUM_MONSTER + 1];  // penalties[idx] = {{monster, penalty}, ... }

/*
    (we need to clear M levels)
    increase levels first, pop-up from the priority queue, decrease later
    decrease values in priority queue may be difficult (can use set (BST) to update values)

    use 2 priority queues ?
        pq_max for already cleared (actually not necessary)
        pq_min for to be clear

    how to update (decrease) level?
    just push to pq_min, then check the duplicates

*/

priority_queue<pair<ll, int>, vector<pair<ll, int> >, less<pair<ll, int> > > pq_cleared;  // (level, index)
priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq_min;  // (level, index)
bool visited[NUM_MONSTER + 1];
void solve_pq(){
    for(int idx=1; idx<=N; ++idx){
        pq_min.push({levels[idx], idx});
    }

    ll clear_level = 0;
    for(int num=1; num<=M; ){
    // while(pq_cleared.size() < M){
        auto [level, idx] = pq_min.top();
        pq_min.pop();
        clear_level = max(clear_level, level);

        // if(levels[idx] < level){    // wrong
        // if(levels[idx] < level || levels[idx] == level && visited[idx]){    // AC
        // if(visited[idx]){
        if(levels[idx] < 0){
            continue;
        }

        // pq_cleared.push({level, idx});
        // visited[idx] = true;
        levels[idx] = -1;
        ++num;

        vector<pair<int, ll> > updates = penalties[idx];
        for(pair<int, ll> update : updates){
            auto [target, penalty] = update;

            if(levels[target] > level){
                levels[target] -= penalty;
                pq_min.push({levels[target], target});
            }
            // else{
            //     // already cleared, do nothing
            // }
        }
    }

    // cout << pq_cleared.top().first << endl;
    cout << clear_level << endl;
}


set<pair<ll, int> > set_min;        // (level, index)
set<pair<ll, int> > set_cleared;    // (level, index)
void solve_set(){
    for(int idx=1; idx<=N; ++idx){
        set_min.insert({levels[idx], idx});
    }

    for(int num=1; num<=M; ++num){
    // while(set_cleared.size() < M){
        auto [level, idx] = *(set_min.begin());
        set_min.erase({level, idx});

        set_cleared.insert({level, idx});

        vector<pair<int, ll> > updates = penalties[idx];
        while(!updates.empty()){
            auto [target, penalty] = updates.back();
            updates.pop_back();

            auto found = set_cleared.find({levels[target], target});
            if(found != set_cleared.end()){
                // NOTE : already cleared, so can't restore the past
                // set_cleared.erase({levels[target], target});
                // levels[target] -= penalty;
                // set_cleared.insert({levels[target], target});
            }
            else{
                set_min.erase({levels[target], target});
                levels[target] -= penalty;
                set_min.insert({levels[target], target});
            }
        }
    }

    cout << (set_cleared.rbegin())->first << endl;
}

void solve(){
    solve_pq();

    // solve_set();
}

void input(){
    cin >> N >> M;
    for(int i=1; i<=N; ++i){
        cin >> levels[i];
    }

    cin >> p;
    for(int i=1; i<=p; ++i){
        cin >> a >> b >> t;
        penalties[a].push_back({b, t});
        levels[b] += t;
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
