/*
    https://www.acmicpc.net/problem/1182
    (sum of subarray/subsequence 1)
        NOTE : NOT a consecutive substring

    similar problem
        https://www.acmicpc.net/problem/1208
        (sum of subarray/subsequence 2)
            N ~ 40, 2^40 ~ 10^12
            => NOT a direct brute force
            => use meet in the middle, then brute force twice
        https://www.acmicpc.net/problem/14225
        (sum of subarray)

    solution
        https://www.acmicpc.net/source/24502820
        (minsiwon00, 0 ms)
        https://www.acmicpc.net/source/1042797
        (wkdgudcjf, 0 ms)

        https://www.acmicpc.net/source/68830518
        (minjun0723, 56 ms) : bitset
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        - subarray with size > 0 s.t. sum of all its elements == target S

    Algorithm
        N ~ 20
        brute force ?
        choice for each element : choose or not
        total 2^20 ~ 10^6
        => brute force using a bitset / backtracking_2 by recursion

        NOTE : subarray size > 0

4 1
1 2 3 4

// 1 (O)
// 0 (X)

5 4
1 3 1 3 1

3 -1
-1 1 2

3 1
1 -1 2

3 0
0 -1 0

// 3

5 -2
-1 -1 -1 -1 -1

// 10

5 0
0 0 0 0 0

// 31

*/
#define SIZE 20
#define MAX_TARGET 1'000'000
int N, S;
int arr[SIZE + 1];

int ans;

int indices[SIZE + 1];
bool visited[SIZE + 1];
int length;
void backtracking_1(int choice){
    if(choice > length){
        int sum = 0;
        for(int i=1; i<=length; ++i){
            sum += arr[indices[i]];
        }
        if(sum == S){
            ++ans;
        }
        return;
    }

    for(int i=1; i<=N; ++i){
        if(!visited[i] && indices[choice-1] < i){
            visited[i] = true;
            indices[choice] = i;
            backtracking_1(choice + 1);
            visited[i] = false;
        }
    }
}

void backtracking_2(int nth, int sum){
    if(nth > N){
        if(sum == S){
            ++ans;
        }
        return;
    }

    backtracking_2(nth + 1, sum + arr[nth]);
    backtracking_2(nth + 1, sum);
}

void solve_backtracking(){
    // 492 ms
    // for(int i = 1; i <= N; ++i){
    //     length = i;
    //     backtracking_1(1);
    // }

    // 4 ms
    backtracking_2(1, 0);

    // NOTE : exclude the case when not taking any element
    if(S == 0){
        --ans;
    }

    cout << ans << endl;
}

void solve_bitset(){
    const int MAX_BIT = 1 << N;
    // for(int bit=0; bit<MAX_BIT; ++bit){
    for(int bit=1; bit<MAX_BIT; ++bit){
        int choice = bit;
        int pos = 0;
        int sum = 0;
        while(choice){
            if(choice & 1){
                sum += arr[pos + 1];
            }
            choice >>= 1;
            pos += 1;
        }

        if(sum == S){
            ++ans;
        }
    }

    // if(S == 0){
    //     --ans;
    // }

    cout << ans << endl;
}

void solve(){
    solve_backtracking();

    // solve_bitset();     // 48 ms
}

void input(){
    cin >> N >> S;

    for(int ith=1; ith<=N; ++ith){
        cin >> arr[ith];
        // sum[ith] = sum[ith-1] + arr[ith];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
