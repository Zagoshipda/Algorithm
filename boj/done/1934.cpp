/*
    LCM
    https://www.acmicpc.net/problem/1934
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define RANGE 45'000
int T;
int A, B;

int gcd(int a, int b){
    if(b <= 0){
        return a;
    }

    return gcd(b, a%b);
}

int lcm(int a, int b){
    return (a * b) / gcd(max(a,b), min(a,b));
}


void input(){
    cin >> T;
}

void solve(){
    while(T--){
        cin >> A >> B;
        cout << lcm(A, B) << endl;
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
