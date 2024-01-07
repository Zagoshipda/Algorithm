/*
    https://www.acmicpc.net/problem/3460
    (binary numbers)

    related with,
        https://www.acmicpc.net/problem/10829
        (binary transformation)


    solutions
        https://www.acmicpc.net/source/3808737

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    2^10 ~ 10^3
    10^6 ~ 2^20
        => max length ~ 20
*/

int d;
int n;

void solve_vector(){
    vector<int> binary;

    int pos = 0;
    while(n){
        if(n & 1){
            binary.push_back(pos);
        }
        else{
            // do nothing.
        }

        n = n >> 1;
        ++pos;
    }

    for(int bit : binary){
        cout << bit << " ";
    }
    cout << endl;
}

void solve_naive(){
    for(int pos=0; n; ++pos){
        if(n & 1){
            cout << pos << " ";
        }
        n = n >> 1;
    }
}

void solve(){
    // solve_vector();

    solve_naive();
}

void input(){

    cin >> d;
    while(d--){
        cin >> n;

        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
