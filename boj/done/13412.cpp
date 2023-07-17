/*
    coprime pairs
    https://www.acmicpc.net/problem/13412
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define RANGE 100'000'000
int T;
int N;

int gcd(int a, int b){
    if(b <= 0){
        return a;
    }

    return gcd(b, a%b);
}

// coprime <==> gcd = 1 <==> lcm = a*b
bool is_coprime(int a, int b){
    if(gcd(max(a, b), min(a, b)) == 1){
        return true;
    }
    else{
        return false;
    }
}

void input(){
    cin >> T;
}

void solve(){
    while(T--){
        cin >> N;
        int a, b;
        int cnt = 0;
        for(int i=1; i*i<=N; ++i){
            if(N % i == 0){
                a = i;
                b = N / i;
                if(is_coprime(a, b)){
                    ++cnt;
                }
            }
        }
        cout << cnt << endl;
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
