/*
    https://www.acmicpc.net/problem/1715
    card arrangement (priority queue)

    similar problem
        https://www.acmicpc.net/problem/11066
        (merging files, DP, Knuth optimization)

    solutions (vs 24ms)
        https://www.acmicpc.net/source/7264126
        (12ms, using normal queue)
        https://www.acmicpc.net/source/43903731
        (8ms, using map - red black tree, basically BST)
        https://www.acmicpc.net/source/36306111
        (8ms, using array and recursion)
        https://www.acmicpc.net/source/31145287
        (12ms, using queue and std::deque (double-ended queue))

        https://www.acmicpc.net/source/62261841
        (12ms, using sorted array) implemented below

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define NUM_CARD 100'000
#define SIZE_CARD 1'000
int N;
ll cards[NUM_CARD + 1];
ll ans;

priority_queue<ll, vector<ll>, greater<ll> > pq_min;
void greedy_wrong(){
    ans = pq_min.top() * (N-1);
    pq_min.pop();
    for(int i=1, cnt=N-1; i<=N-1; ++i, --cnt){
        ans += pq_min.top() * cnt;
        pq_min.pop();
    }

    cout << ans << endl;
}

void greedy_pq(){
    ans = 0;
    ll val_1, val_2, val_3;

    while(pq_min.size() > 1){
        val_1 = pq_min.top();
        pq_min.pop();
        val_2 = pq_min.top();
        pq_min.pop();

        val_3 = val_1 + val_2;
        ans += val_3;
        pq_min.push(val_3);
    }

    cout << ans << endl;
}

int idx=1, pos_current=1, pos_end=1;    // always pos_current <= pos_end (loop invariant)
int cards_sum[2 * NUM_CARD + 1];        // sorted cards sums
void merge_cards(){
    // reserve enough cards (at least 2 cards must be taken) for each step
    while(pos_end-pos_current<2){
        cards_sum[pos_end] = cards[idx];
        ++pos_end;
        ++idx;
    }

    int current_sum = cards_sum[pos_current] + cards_sum[pos_current+1];
    pos_current += 2;
    ans += current_sum;

    while(cards[idx]<=current_sum && idx<=N){
        cards_sum[pos_end] = cards[idx];
        ++pos_end;
        ++idx;
    }
    cards_sum[pos_end] = current_sum;
    ++pos_end;
}

void solve_array(){
    sort(cards+1, cards+N+1);

    for(int i=1; i<=N-1; ++i){
        merge_cards();
    }

    cout << ans << endl;
}

void solve(){
    // greedy_wrong();

    // greedy_pq();

    solve_array();
}

void input(){
    cin >> N;
    ll size;
    for(int i=1; i<=N; ++i){
        cin >> size;
        cards[i] = size;
        // pq_min.push(size);
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
