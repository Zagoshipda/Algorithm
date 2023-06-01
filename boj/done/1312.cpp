#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int A, B, N;

int main(){
    IOS;

    cin >> A >> B >> N;

    for(int i=0; i<N; ++i){
        A %= B;
        A *= 10;
    }

    cout << A / B << endl;

    return 0;
}
