#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int cnt[1000010];
int N;

int calculate(int n){
    if(n == 1){
        cnt[1] = 1;
        return 0;
    }
    else{
        if(cnt[n] > 0){
            return cnt[n];
        }
        if(n % 3 == 0 && n % 2 == 0){
            cnt[n] = min(min(calculate(n/3), calculate(n/2)), calculate(n-1)) + 1;
        }
        else if(n % 3 == 0){
            cnt[n] = min(calculate(n/3), calculate(n-1)) + 1;
        }
        else if(n % 2 == 0){
            cnt[n] = min(calculate(n/2), calculate(n-1)) + 1;
        }
        else{
            cnt[n] = calculate(n-1) + 1;
        }
        return cnt[n];
    }
}

int main(void){
    IOS;

    cin >> N;

    cout << calculate(N) << endl;

    return 0;
}
