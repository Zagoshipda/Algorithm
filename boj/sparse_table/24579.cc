/*
    https://www.acmicpc.net/problem/24579
    (concert rehearsal)

    solution
        sparse table
            considering only the remainders on each day, implemented in solve_sparse_table_2()
            https://www.acmicpc.net/source/39875971
            (xiaowuc1, 332 ms)
            https://www.acmicpc.net/source/41071893
            (index, 128 ms)

        https://www.acmicpc.net/source/69316526
        (rootcucu, 32 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        At any moment if the next student’s performance cannot complete before the recital hall closes, all the remaining performances, within the current rehearsal pass, will be "moved to the next day".

    Algorithm
        WANT : for each starting student, who will be the next starting student ?
        => find the k-th next starting student using a sparse table

        nexts[k][current] : k-th next starting from the current starting

        max day ~ O(10^9) ~ O(2^30)

        1 2 3
        1 : 1 2 3 1 2
        2 : 3 1 2 3
        3 : 1 2 3 1 2
        4 : 3 1 2 3
        5 : 1 2 3 1 2
        => 7 cycles
*/

const int NUM_STUDENT = 200'000;        // 2 * 10^5
const int MAX_DURATION = 1'000'000'000; // 10^9
const int MAX_DAYS = 1'000'000'000;      // 10^9

const int MAX_POWER = 30;

ll n, p, k;
ll durations[NUM_STUDENT + 1];

int nexts[MAX_POWER + 1][NUM_STUDENT + 1];  // nexts[k][n] = 2^k-th next of n
ll passes[MAX_POWER + 1][NUM_STUDENT + 1];  // passes[k][n] = # of passes from n to nexts[k][n]

// caching differences, not the next pointer
ll performances[MAX_POWER + 1][NUM_STUDENT + 1];

void solve_sparse_table_1(){
    // sweeping
    ll sum = 0;
    int start = 1;
    for(int next=1; ; ++next){
        if(next > n){
            next = 1;
            ++passes[0][start];     // count the end of one rehearsal pass
        }

        if(sum + durations[next] <= p){
            sum += durations[next];
        }
        else{
            nexts[0][start] = next;
            break;
        }
    }

    for(start=2; start<=n; ++start){
        // sum = 0;
        sum -= durations[start - 1];
        passes[0][start] = passes[0][start - 1];
        // TODO : not enough only for a counter, pointer to (start, end) required ?
        // for(int next=start; ; ++next){
        for(int next=nexts[0][start - 1]; ; ++next){
            if(next > n){
                next = 1;
                ++passes[0][start];     // count the end of one rehearsal pass
            }

            if(sum + durations[next] <= p){
                sum += durations[next];
            }
            else{
                nexts[0][start] = next;
                break;
            }
        }
    }

    // bottom up DP
    // int limit = static_cast<int>(ceil(log2(k)));
    // for(int power=1; power<=limit; ++power){
    for(int power=1; power<=MAX_POWER; ++power){
        for(int student=1; student<=n; ++student){
            nexts[power][student] = nexts[power-1][nexts[power-1][student]];
            passes[power][student] = passes[power-1][nexts[power-1][student]] + passes[power-1][student];
        }
    }

    // calculate result
    // cout << passes[k][1] << endl;
    // cout << passes[static_cast<int>(log2(k))][1] << endl;
    int pos = 1;
    int power = 0;
    ll cnt = 0;
    while(k){
        if(k & 1){
            cnt += passes[power][pos];
            pos = nexts[power][pos];
        }
        k >>= 1;
        power += 1;
    }

    cout << cnt << endl;
}

void solve_sparse_table_2(){
    ll sum = 0;

    // NOTE : time exceeded without this -> large p will make a loop iteration (A) much longer
    sum = accumulate(durations, durations+n, sum);
    int div = p / sum;
    // considering only remainders on each day
    p %= sum;

    // sweeping
    // NOTE : index starts from 0 for modular n
    int next = 0;
    sum = 0;
    for(int start=0; start<n; ++start){
        for( ; ; ++next){
            if(sum + durations[next % n] <= p){     // (A)
                sum += durations[next % n];
            }
            else{
                performances[0][start] = next - start;
                break;
            }
        }
        sum -= durations[start];
    }

    // bottom up DP
    for(int power=1; power<=MAX_POWER; ++power){
        for(int student=0; student<n; ++student){
            performances[power][student] = (
                performances[power-1][student] +
                performances[power-1][(student + performances[power-1][student]) % n]
            );
        }
    }

    // calculate result
    ll pos = 0;
    int power = 0;
    int days = k;
    while(days){
        if(days & 1){
            pos += performances[power][pos % n];
        }
        days >>= 1;
        power += 1;
    }

    // cout << (pos / n) << endl;

    // NOTE : passes = # of multiples of n
    // # of entire passes + # of combined passes from remainders
    cout << (div * k) + (pos / n) << endl;
}

void solve(){
    // solve_sparse_table_1();

    solve_sparse_table_2();
}

void input(){
    cin >> n >> p >> k;
    // for(int ith=1; ith<=n; ++ith){
    //     cin >> durations[ith];
    // }
    for(int ith=0; ith<n; ++ith){
        cin >> durations[ith];
    }
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
