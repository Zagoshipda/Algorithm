/*
    https://www.acmicpc.net/problem/12738
    (lis 3)

    similar problem
        https://www.acmicpc.net/problem/11053
        (lis 1)

        https://www.acmicpc.net/problem/25343
        (maximum lis) : 2-D lis

    solutions
        https://www.acmicpc.net/source/11573715
        (h2oche, 184 ms)

        https://www.acmicpc.net/source/12006328
        (jaimemin, 184 ms) : array implementation

    reference
        https://jason9319.tistory.com/113

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

6
-1000000000 1000000000 2 -10000 1000000000 -100000000

// 3 : -1000000000 -100000000 1000000000

*/

const int ARR_SIZE = 1'000'000;
const int MIN_NUM = -1'000'000'000;
const int MAX_NUM = 1'000'000'000;

int N;
int arr[ARR_SIZE + 1];
void solve_lis_nlogn_1(){
    vector<int> lis;
    lis.push_back(arr[1]);
    for(int idx=2; idx<=N; ++idx){
        int pos = distance(lis.begin(), lower_bound(lis.begin(), lis.end(), arr[idx]));
        if(lis.size() <= pos){
            lis.push_back(arr[idx]);
        }
        else{
            lis[pos] = arr[idx];
        }
    }

    cout << lis.size() << endl;
    // for(auto it=lis.begin(); it!=lis.end(); ++it){
    //     cout << *it << " ";
    // }
    // cout << endl;
}

void solve_lis_nlogn_2(){
    vector<int> lis;
    lis.push_back(arr[1]);
    for(int idx=2; idx<=N; ++idx){
        if(lis.back() < arr[idx]){
            lis.push_back(arr[idx]);
        }
        else{
            auto it = lower_bound(lis.begin(), lis.end(), arr[idx]);
            *it = arr[idx];
        }
    }
    cout << lis.size() << endl;
    // for(auto it=lis.begin(); it!=lis.end(); ++it){
    //     cout << *it << " ";
    // }
    // cout << endl;
}

// TODO
void solve_segment_tree(){

}

void solve(){
    // solve_lis_nlogn_1();
    solve_lis_nlogn_2();
}

void input(){
    cin >> N;
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
