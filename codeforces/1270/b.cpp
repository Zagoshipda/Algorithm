#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int t, n;

int main(){
	IOS;

    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        int a[n];
        fill_n(a, n, 0);
        
        for(int j=0; j<n; j++){
            cin >> a[j];
        }

        bool flag = true;
        for(int j=0; j<n-1; j++){
            if(abs(a[j]-a[j+1]) >= 2){
                cout << "YES" << endl;
                cout << j+1 << ' ' << j+2 << endl;
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "NO" << endl;
        }
    }

    return 0;
}
