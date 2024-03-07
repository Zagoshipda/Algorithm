/*
    https://www.acmicpc.net/problem/9506
    (perfect number)

    solutions
        https://www.acmicpc.net/source/329652
        (yukariko, 0 ms) : brute force
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MAX_NUM = 100'000;
ll n;

void solve(){
    ll sum = 1; // NOTE : 1 is always a factor
    set<int> factors;
    // factors.insert(1);
    for(ll factor=2; factor*factor<=n; ++factor){
        if(n % factor == 0){
            factors.insert(factor);
            factors.insert(n / factor);

            if(factor*factor == n){
                sum += factor;
            }
            else{
                sum += factor;
                sum += n / factor;
            }
        }
    }

    // for(auto it=factors.begin(); it!=factors.end(); ++it){
    //     sum += *it;
    // }
    if(sum == n){
        cout << n << " = 1";
        for(auto it=factors.begin(); it!=factors.end(); ++it){
            cout << " + " << *it;
        }
        cout << endl;
    }
    else{
        cout << n << " is NOT perfect." << endl;
    }
}

void input(){
    while(true){
        cin >> n;
        if(n < 0){  // -1 denotes the end of input
            break;
        }
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
