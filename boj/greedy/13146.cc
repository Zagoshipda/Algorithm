/*
    https://www.acmicpc.net/problem/13146
    (make the same number 2)

    similar problem
        https://www.acmicpc.net/problem/2374
        (make the same number 1)

        https://www.acmicpc.net/problem/2911
        (RAZGOVORI) : conversations

    solution
        https://www.acmicpc.net/source/38298829
        (flappybird, 128 ms)
        https://www.acmicpc.net/source/50866670
        (wjdgud0621, 124 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm

*/

const int ARR_SIZE = 1'000'000; // 10^6
const int MAX_NUM = 1'000'000'000;  // 10^9

int n;
int arr[ARR_SIZE + 1];
int max_arr;

void solve_greedy_1(){
    max_arr = *max_element(arr + 1, arr + 1 + n, less<int>());
    ll adds = 0;
    for(int ith=1; ith<n; ++ith){
        if(arr[ith] < arr[ith + 1]){
            adds += (arr[ith + 1] - arr[ith]);
        }
    }

    cout << adds + (max_arr - arr[n]) << endl;
}



void solve_greedy_2(){
    stack<int> stk;
    stk.push(arr[1]);

    ll adds = 0;
    for(int ith=2; ith<=n; ++ith){
        if(stk.top() >= arr[ith]){
            stk.push(arr[ith]);
        }
        else{
            adds += arr[ith] - stk.top();
            while(!stk.empty() && stk.top() < arr[ith]){
                stk.pop();
            }
            stk.push(arr[ith]);
        }
    }
    // process the remainings : stack with descending values
    if(!stk.empty()){
        int first = stk.top();
        // int last = 0;
        int last = stk.top();
        while(!stk.empty()){
            last = stk.top();
            stk.pop();
        }
        // if(last){
            adds += last - first;
        // }
    }

    cout << adds << endl;
}

void solve(){
    // solve_greedy_1();

    solve_greedy_2();
}

void input(){
    cin >> n;
    for(int ith=1; ith<=n; ++ith){
        cin >> arr[ith];
        // max_arr = max(arr[ith], max_arr);
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
