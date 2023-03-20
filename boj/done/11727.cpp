#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define MOD 10007
#define SIZE 1001
int n;
int num[SIZE];

void calculate_num(){
    num[1] = 1;
    num[2] = 3;
    for(int i=3; i<=n; ++i){
        num[i] = (num[i-2] * 2 + num[i-1]) % MOD;
    }

    cout << num[n] << endl;
}

int main(){
    IOS;

    cin >> n;

    calculate_num();

    return 0;
}
