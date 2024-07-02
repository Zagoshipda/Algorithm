/*
    https://www.acmicpc.net/problem/24035
    (impartial offerings)

    similar problem
        https://www.acmicpc.net/problem/18870
        (coordinate compression)

    solution
        https://www.acmicpc.net/source/37162802
        (dotorya, 0 ms) : implemented in solve_map()
        https://www.acmicpc.net/source/73936611
        (macneil, 0 ms) : implemented in solve_array()

    reference
        https://restudycafe.tistory.com/612
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int ARR_SIZE = 100;

int T;
int ith;
int N;
vector<int> arr;

int ans;
void print_answer(){
    cout << "Case #" << ith << ": " << ans << endl;
}

void solve_map(){
    map<int, int> numbers;  // (number, cnt)
    for(int idx=1; idx<=N; ++idx){
        ++numbers[arr[idx]];
    }
    int cnt = 1;
    ans = 0;
    for(auto it=numbers.begin(); it!=numbers.end(); ++it){
        ans += cnt * it->second;
        ++cnt;
    }

    print_answer();
}

void solve_array(){
    sort(arr.begin(), arr.end(), less<int>());

    ans = 0;
    for(int idx=1, cnt=0; idx<=N; ++idx){
        if(arr[idx-1] != arr[idx]){
            ++cnt;
        }
        ans += cnt;
    }

    print_answer();
}

void solve(){
    // solve_map();

    solve_array();
}

void input(){
    cin >> T;
    for(ith=1; ith<=T; ++ith){
        cin >> N;

        arr.resize(N + 1);
        for(int idx=1; idx<=N; ++idx){
            cin >> arr[idx];
        }

        solve();
    }
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    // solve();

    return 0;
}
