#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t, n;
int a[3];

int main(){
    IOS;

    cin >> t;
    for(int i=0; i<t; ++i){
        cin >> a[0] >> a[1] >> a[2] >> n;
        sort(a, a+3);
        int left = n - (2*a[2] - a[1] - a[0]);
        if(left >= 0 && left % 3 == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    

    return 0;
}
