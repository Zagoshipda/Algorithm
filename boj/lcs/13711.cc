/*
    https://www.acmicpc.net/problem/13711
    (lcs 4)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        N ~ 10^5
        N^2 ~ 10^10

        A[1...N], B[1...N] : permutation { 1, ..., N }

        consider a bijection f : A -> B s.t. f(x) = x
        let g : A -> B which assigns index k from B s.t. f(x) = x = B[k]
        let lcs = A[i1...ik] = B[j1...jk] = g(j1)...g(jk)
        therefore it is sufficient to find lis in g
*/

const int ARR_SIZE = 100'000;   // 10^5
const int MAX_NUM = 100'000;    // 10^5

int N;
int arr[ARR_SIZE + 1];
int brr[ARR_SIZE + 1];

// int hash_a[ARR_SIZE + 1];
int hash_b[ARR_SIZE + 1];   // hash_b = brr^-1 : hash_b[x] = j <=> brr[j] = x

void solve_lis(){
    vector<int> lis = { MAX_NUM + 1 };  // lis of indices

    for(int ith=1; ith<=N; ++ith){
        int pos = hash_b[arr[ith]];
        // if(lis.back() <= pos){
        if(lis.back() < pos){       // NOTE : all numbers are distinct in permutation
            lis.push_back(pos);
        }
        else{
            auto it = lower_bound(lis.begin(), lis.end(), pos);
            *it = pos;
        }
    }

    cout << lis.size() << endl;
}

void solve(){
    solve_lis();
}

void input(){
    cin >> N;
    for(int ith=1; ith<=N; ++ith){
        cin >> arr[ith];
    }
    for(int ith=1; ith<=N; ++ith){
        cin >> brr[ith];
        hash_b[brr[ith]] = ith;
    }
}

void debug(){

}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    // debug();

    input();

    solve();

    return 0;
}
