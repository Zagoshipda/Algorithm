/*
    https://www.acmicpc.net/problem/10973
    (previous permutation)

    similar problem
        https://www.acmicpc.net/problem/10972
        (next permutation)
        https://www.acmicpc.net/problem/10974
        (all permutation)

    solution
        https://www.acmicpc.net/source/1225606
        (zlzmsrhak, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

int N;
int num;
vector<int> permutation;

void solve_brute_force(){

}

void solve_stl(){
    if(prev_permutation(permutation.begin(), permutation.end())){
        for(int n : permutation){
            cout << n << " ";
        }
        cout << endl;
    }
    else{
        cout << -1 << endl;
    }
}

void solve(){
    solve_stl();
}

void input(){
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> num;
        permutation.push_back(num);
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
