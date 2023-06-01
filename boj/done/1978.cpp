/*
    Find prime number
    https://www.acmicpc.net/problem/1978

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int N;
int num;
int cnt;

bool is_prime(int n){
    if(n < 2){
        return false;
    }

    for(int i=2; i*i<=n; ++i){
        if(n % i == 0){
            return false;
        }
    }

    return true;
}

int main(){
    IOS;

    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> num;
        if(is_prime(num)){
            ++cnt;
        }
    }

    cout << cnt << endl;

    return 0;
}
