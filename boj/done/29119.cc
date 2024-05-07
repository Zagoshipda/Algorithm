/*
    https://www.acmicpc.net/problem/29119
    (largest number)

    similar problem
        https://www.acmicpc.net/problem/16496
        (make a big number)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        - non-negative numbers
        - combine all the numbers into one, connected in series, get the largest possible
*/

const int ARR_SIZE = 100'000;   // 10^5
const int MAX_NUM = 1'000'000'000;  // 10^9
const int MAX_DIGIT = 10;

int N;
string arr[ARR_SIZE + 1];

struct cmp_numbers{
    bool operator()(string num_1, string num_2){
        return (num_1 + num_2) > (num_2 + num_1);
    }
};

void solve(){
    sort(arr+1, arr+1+N, cmp_numbers());

    for(int idx=1; idx<=N; ++idx){
        cout << arr[idx] << " ";
    }
    cout << endl;
}

void input(){
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> arr[i];
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
