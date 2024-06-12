/*
    https://www.acmicpc.net/problem/14225
    (sum of subarray)

    similar problem
        https://www.acmicpc.net/problem/1182
        (sum of subarray/subsequence 1)
        https://www.acmicpc.net/problem/1208
        (sum of subarray/subsequence 2)

    solution
        https://www.acmicpc.net/source/21290925
        (jnus100, 8 ms) : implemented in solve_recursive()
        https://www.acmicpc.net/source/19843537
        (xiaowuc1, 4 ms) : implemented in solve_bitset()
            (observation) since all numbers are positive, addition always increases
            => considering each elements itself is just enough

        https://www.acmicpc.net/source/11867624
        (dotorya, 0 ms) : implemented in solve_greedy()

    reference
        https://thought-process-ing.tistory.com/123
            greedy approach
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        2^20 ~ 10^6 => brute force
*/

const int ARR_SIZE = 20;        // 10^2
const int MAX_NUM = 100'000;    // 10^5
const int MAX_SUM = ARR_SIZE * MAX_NUM; // 10^7

int N;
int arr[ARR_SIZE + 1];

bool hashes[MAX_SUM + 1];
void print_answer(){
    for(int num=1; num<=MAX_SUM; ++num){
        if(!hashes[num]){
            cout << num << endl;
            break;
        }
    }
}

void solve_brute_force(){
    const int MAX_BIT = 1 << N;
    for(int bitmask=1; bitmask<MAX_BIT; ++bitmask){
        int sum = 0;
        for(int bit=0; bit<N; ++bit){
            if((bitmask >> bit) & 1){
                sum += arr[bit+1];
            }
        }
        hashes[sum] = true;
    }

    print_answer();
}

// bool visited[ARR_SIZE + 1][MAX_SUM + 1];
void recursive(int nth, int sum){
    if(nth > N){
        hashes[sum] = true;
        return;
    }

    // if(visited[nth][sum]){
    //     return;
    // }

    recursive(nth + 1, sum);
    recursive(nth + 1, sum + arr[nth]);
    // visited[nth][sum] = true;
}

void solve_recursive(){
    recursive(1, 0);

    print_answer();
}

const int MAX_BIT = 20;     // 2^20 ~ 10^6
// const int MAX_BIT = 5;     // only for debugging
const int BS_SIZE = 1 << (MAX_BIT + 1);
bitset<BS_SIZE> bs(1);  // NOTE : initialize 0th bit for the base case
void solve_bitset(){
    for(int idx=1; idx<=N; ++idx){
        // NOTE : bit accumulation
        bs |= (bs << arr[idx]);
    }

    for(int num=1; ; ++num){
        if(!bs[num]){
            cout << num << endl;
            break;
        }
    }
}

void solve_greedy(){
    sort(arr+1, arr+1+N, less<int>());

    int sum = 0;
    for(int idx=1; idx<=N; ++idx){
        if(arr[idx] <= sum + 1){
            sum += arr[idx];
        }
        else{
            break;
        }
    }
    cout << sum + 1 << endl;
}

void solve(){
    // solve_brute_force();    // 56 ms

    // solve_recursive();      // 8 ms

    // solve_bitset();         // 4 ms

    solve_greedy();         // 0 ms
}

void input(){
    cin >> N;
    for(int idx=1; idx<=N; ++idx){
        cin >> arr[idx];
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
