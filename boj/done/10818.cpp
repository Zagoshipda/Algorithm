/*
    https://www.acmicpc.net/problem/10818
    (min, max)
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
int min_val = INT_MAX, max_val = INT_MIN;

void solve(){

}

void input(){
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> num;
        min_val = min(min_val, num);
        max_val = max(max_val, num);
    }
    cout << min_val << " " << max_val << endl;
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
