/*

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

void solve(){

}

void input(){
    int sum = 0;
    int min_odd = INT_MAX;
    int num;
    for(int i=0; i<7; ++i){
        cin >> num;
        if(num&1){
            sum += num;
            min_odd = min(min_odd, num);
        }

    }

    if(sum){
        cout << sum << endl;
        cout << min_odd << endl;
    }
    else{
        cout << -1 << endl;
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
