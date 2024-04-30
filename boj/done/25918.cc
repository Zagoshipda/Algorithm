/*
    https://www.acmicpc.net/problem/25918
    (polar bear parenthesis) feat. Bear Grylls

    solution
        https://www.acmicpc.net/source/51375340
        (eunlin, 0 ms) : using both min, max
        https://www.acmicpc.net/source/53419723
        (pizzaroot, 0 ms) : conditional addition
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

int N;
string S;

void solve(){
    int max_cnt = 0;
    int cnt = 0;
    for(int idx=0; idx<N; ++idx){
        // if(S[idx] == '('){
        //     ++cnt;
        // }
        // else{
        //     --cnt;
        // }
        cnt += (S[idx] == '(') - (S[idx] == ')');
        max_cnt = max(max_cnt, abs(cnt));
    }

    if(cnt){
        cout << -1 << endl;
    }
    else{
        cout << max_cnt << endl;
    }
}

void input(){
    cin >> N;
    cin >> S;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
