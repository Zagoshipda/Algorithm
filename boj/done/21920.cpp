/*
    average of coprimes
    https://www.acmicpc.net/problem/21920
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 500'000
#define RANGE 1'000'000
int N;
int arr[SIZE];
int X;
// bool visited[RANGE+1];
// bool coprimes[RANGE+1];

// int gcd(int a, int b){
//     return (b <= 0) ? a : gcd(b, a%b);
// }

bool is_coprime(int a, int b){
    return gcd(max(a, b), min(a, b)) == 1;
}

void input(){
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> arr[i];
    }
    cin >> X;
}

void solve(){
    double sum = 0;
    int cnt = 0;

    // for(int i=0; i<N; ++i){
    //     bool result;
    //     if(!visited[arr[i]]){
    //         visited[arr[i]] = true;
    //         result = is_coprime(X, arr[i]);
    //         coprimes[arr[i]] = result;
    //     }
    //     else{
    //         result = coprimes[arr[i]];

    //     }
    //     if(result){
    //         sum += arr[i];
    //         ++cnt;
    //     }
    // }

    for(int i=0; i<N; ++i){
        bool result = is_coprime(X, arr[i]);
        if(result){
            sum += arr[i];
            ++cnt;
        }
    }

    cout << sum / cnt << endl;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
