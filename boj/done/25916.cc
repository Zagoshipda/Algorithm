/*
    https://www.acmicpc.net/problem/25916
    (hamster)

    solution
        https://www.acmicpc.net/source/57716940
        (rootsquare, 108 ms) : implemented in solve_two_pointer_2()
        https://www.acmicpc.net/source/58972898
        (mujigae, 64 ms) : two pointer with prefix sum, implemented in solve_two_pointer_3()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    consecutive hamster !
*/

const int ARR_SIZE = 500'000;
const int MAX_HAMSTER = 1'000'000'000;  // 10^9 !!!
const int MAX_NUM = 1'000'000'000;      // 10^9

ll N, M;
ll arr[ARR_SIZE + 1];

ll sum;
ll max_sum;
// incrementing left end
void solve_two_pointer_1(){
    for(int left=1, right=1; left<=N; sum-=arr[left], ++left){
        right = max(left, right);
        sum = max(sum, (ll)0);
        while(right<=N && sum + arr[right] <= M){
            sum += arr[right];
            ++right;
        }
        max_sum = max(max_sum, sum);
        if(right > N){
            break;
        }
    }

    cout << max_sum << endl;
}

// incrementing right end
void solve_two_pointer_2(){
    for(int left=1, right=1; right<=N; ++right){
        sum += arr[right];
        while(left <= right && sum > M){
            sum -= arr[left];
            ++left;
        }
        max_sum = max(max_sum, sum);
    }

    cout << max_sum << endl;
}

void solve_two_pointer_3(){
    for(int left=1, right=1; right<=N; ){
        if(sum + arr[right] <= M){
            sum += arr[right];
            max_sum = max(max_sum, sum);
            ++right;
        }
        else{
            sum -= arr[left];
            ++left;
        }
    }
    cout << max_sum << endl;
}

void solve(){
    // solve_two_pointer_1();
    solve_two_pointer_2();
    // solve_two_pointer_3();
}

void input(){
    cin >> N >> M;
    for(int i=1; i<=N; ++i){
        cin >> arr[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
