/*
    https://www.acmicpc.net/problem/2565
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
vector<int> wire(SIZE + 1);

int lis_size;
vector<int> lis;

void initialize(){
    lis.push_back(wire[0]);
    lis_size += 1;
}

void solve(){
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


vector<pair<int, int>> in;

void input(){
    cin >> n;
    int a, b;
    for(int i=0; i<n; ++i){
        cin >> a >> b;

        in.push_back({a, b});
    }
    sort(in.begin(), in.end(), less<pair<int, int> >() );

    for(int i=0; i<n; ++i){
        wire[i] = in[i].second;
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
