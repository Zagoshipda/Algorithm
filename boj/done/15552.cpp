// 빠른 A+B

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int T, A, B;

int main(){
	IOS;

    cin >> T;
    while(T--){
        cin >> A >> B;
        cout << A+B << '\n';
    }

    return 0;
}

