/*
    https://www.acmicpc.net/problem/2813
    (fence)

    similar problem
        https://www.acmicpc.net/problem/2395
        (number of permutations)

    solution
        https://www.acmicpc.net/source/22921540
        (gunwookim, 148 ms)

    reference
        https://hsin.hr/coci/archive/2011_2012/
        https://chw0501.tistory.com/14
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        - niceness : sum of height differences between adjacent boards
        - two fences are "similar" if ordering of adjacent boards is the same in both fences
        - all numbers are "distinct"
        => which configuration gets the maximum possible niceness ?

    Algorithm
*/

const int ARR_SIZE = 300'000;   // 3 * 10^5
const int MAX_NUM = 1'000'000'000;  // 10^9

int N;
int arr_1[ARR_SIZE + 1];
int arr_2[ARR_SIZE + 1];

ll ans[ARR_SIZE + 1];
void print_answer(){
    ll val = 0;
    for(int idx=1; idx<N; ++idx){
        val += abs(ans[idx] - ans[idx+1]);
    }

    cout << val << endl;
    for(int idx=1; idx<=N; ++idx){
        cout << ans[idx] << " ";
    }
    cout << endl;
}

void solve(){
    sort(arr_2+1, arr_2+1+N, less<int>());
    int left = 1, right = N;
    // in-between
    for(int idx=2; idx<N; ++idx){
        if(arr_1[idx-1] > arr_1[idx] && arr_1[idx] < arr_1[idx+1]){
            ans[idx] = arr_2[left];
            ++left;
        }
        else if(arr_1[idx-1] < arr_1[idx] && arr_1[idx] > arr_1[idx+1]){
            ans[idx] = arr_2[right];
            --right;
        }
    }
    // first
    if(arr_1[1] > arr_1[2]){
        ans[1] = arr_2[right];
        --right;
    }
    else if(arr_1[1] < arr_1[2]){
        ans[1] = arr_2[left];
        ++left;
    }
    // last
    if(arr_1[N-1] < arr_1[N]){
        ans[N] = arr_2[right];
        --right;
    }
    else if(arr_1[N-1] > arr_1[N]){
        ans[N] = arr_2[left];
        ++left;
    }

    // leftovers
    for(int idx=2; idx<N; ++idx){
        if(!ans[idx]){
            if(arr_1[idx-1] > arr_1[idx]){
                ans[idx] = arr_2[right];
                --right;
            }
            else{
                ans[idx] = arr_2[left];
                ++left;
            }
        }
    }

    print_answer();
}

void input(){
    cin >> N;
    for(int idx=1; idx<=N; ++idx){
        cin >> arr_1[idx];
    }
    for(int idx=1; idx<=N; ++idx){
        cin >> arr_2[idx];
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
