#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int M, N;

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

    cin >> M >> N;

    int sum = 0;
    int min_val = INT_MAX;
    for(int i=M; i<=N; ++i){
        if(is_prime(i)){
            sum += i;
            // min_val = min(min_val, i);
            if(min_val == INT_MAX){
                min_val = i;
            }
        }
    }

    if(sum == 0){
        cout << -1 << endl;
    }
    else{
        cout << sum << endl;
        cout << min_val << endl;
    }

    return 0;
}
