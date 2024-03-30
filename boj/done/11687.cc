/*
    https://www.acmicpc.net/problem/11687
    (smallest factorial with trailing zeros)

    solutions
        implemented in solve_parametric_search_2()
            https://www.acmicpc.net/source/7497328
            (Juno, 0 ms) : iterative implementation
            https://www.acmicpc.net/source/7954302
            (cea, 0 ms) : recursive implementation

        https://www.acmicpc.net/source/18663094
        (goooora, 0 ms) : binary search with [l, r)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    DP or parametric search (optimization -> decision)
*/

const int MIN_NUM = 1;
const int MAX_NUM = 100'000'000;    // 10^8
const int INF = 1'000'000'000;    // 10^8
const int IMPOSSIBLE = -1;

int M;

int count_trailing_zeros(int num){
    int cnt = 0;
    int div = 5;

    // for( ; div<=num; div*=5){
    //     cnt += num / div;
    // }

    while(num){
        cnt += num / div;
        num /= 5;
    }

    return cnt;
}

void solve_parametric_search_1(){
    for(int left=0, right=INF; left<=right; ){
        int mid = (left + right) >> 1;

        int cnt = count_trailing_zeros(mid);
        if(cnt == M){
            int target;
            for(target=mid; count_trailing_zeros(target) == M; --target){
                // do nothing.
            }
            // NOTE : + 1 to recover the last decrease
            cout << target + 1 << endl;
            return;
        }

        else if(cnt < M){
            left = mid + 1;
        }
        else if(M < cnt){
            right = mid - 1;
        }
    }

    cout << IMPOSSIBLE << endl;
}

void solve_parametric_search_2(){
    int ans = IMPOSSIBLE;
    int cnt_ans = INF;
    int mid;
    int cnt;
    for(int left=0, right=INF; left<=right; ){
        mid = (left + right) >> 1;
        cnt = count_trailing_zeros(mid);

        if(M <= cnt){
            ans = mid;
            cnt_ans = min(cnt_ans, cnt);
            right = mid - 1;
        }
        else if(cnt < M){
            left = mid + 1;
        }
    }

    if(cnt_ans == M){   // AC
    // if(count_trailing_zeros(mid) == M){ // WRONG
        cout << ans << endl;
    }
    else{
        cout << IMPOSSIBLE << endl;
    }
}

void solve(){
    // solve_parametric_search_1();
    solve_parametric_search_2();
}

void input(){
    cin >> M;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
