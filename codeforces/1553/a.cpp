#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
int n;

int main(){
    IOS;

    cin >> t;
    while(t--){
        cin >> n;
        cout << (n+1)/10 << endl;
    }

    return 0;
}
