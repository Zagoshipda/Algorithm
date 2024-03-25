/*
    https://www.acmicpc.net/problem/2565
    (wire 1)

    similar problem
        https://www.acmicpc.net/problem/1365
        (twisted wire)
        https://www.acmicpc.net/problem/1946
        (newbie)

    solutions
        https://www.acmicpc.net/source/17333898
        (cejung, 0 ms) : nlogn lis algorithm
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18


/*
    TODO : Dynamic programming strategy

    S ubproblem

    R ecursive relation

    T opological order

    B ase case

    O riginal problem

    T ime complexity

*/

#define SIZE 100
#define RANGE 500
int n;
vector<pair<int, int>> in;

vector<int> wire(SIZE + 1);

int lis_size;
vector<int> lis;

void initialize(){
    lis.push_back(wire[0]);
    lis_size = 1;
}

void solve_lis(){
    sort(in.begin(), in.end(), less<pair<int, int> >() );

    for(int i=0; i<n; ++i){
        wire[i] = in[i].second;
    }

    initialize();

    // find longest increasing subsequence

    // ex. 8 2 9 1 4 6 7 10

    for(int i=1; i<n; ++i){
        if(lis[lis_size-1] < wire[i]){
            lis_size += 1;
            lis.push_back(wire[i]);
        }
        else{
            auto pos = lower_bound(lis.begin(), lis.end(), wire[i]);
            if(pos != lis.end()){
                lis[pos - lis.begin()] = wire[i];
            }
        }
    }

    cout << n - lis_size << endl;
}

void solve(){
    solve_lis();
}

void input(){
    cin >> n;
    int a, b;
    for(int i=0; i<n; ++i){
        cin >> a >> b;
        in.push_back({a, b});
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
