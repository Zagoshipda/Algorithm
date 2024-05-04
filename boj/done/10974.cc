/*
    https://www.acmicpc.net/problem/10974
    (all permutation)

    similar problem
        https://www.acmicpc.net/problem/10972
        (next permutation)
        https://www.acmicpc.net/problem/10973
        (previous permutation)

    solution
        https://www.acmicpc.net/source/5067718
        (chogahui05, 0 ms) : printf("%s", char [])
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

int N;

void solve(){
    vector<int> perm;
    for(int i=1; i<=N; ++i){
        perm.push_back(i);
    }

    do{
        for(int num : perm){
            cout << num << " ";
        }
        cout << endl;
    }while(next_permutation(perm.begin(), perm.end()));
}

void input(){
    cin >> N;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
