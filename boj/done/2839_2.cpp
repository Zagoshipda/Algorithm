#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int N;
int cnt;

int main(){
    IOS;

    cin >> N;

    while(true){
        if(N < 0){
            cout << -1 << endl;
            break;
        }
        if(N % 5 == 0){
            cout << (N / 5) + cnt << endl;
            break;
        }
        N -= 3;
        cnt += 1;
    }

    return 0;
}
