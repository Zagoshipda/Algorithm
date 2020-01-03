#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int t;
int n, k1, k2;

int main(){
	IOS;

    cin >> t;

    for(int i=0; i<t; i++){
        cin >> n >> k1 >> k2;
        int a[k1];
        int b[k2];
        fill_n(a, k1, 0);
        fill_n(b, k2, 0);
        for(int j=0; j<k1; j++){
            cin >> a[j];
        }
        for(int j=0; j<k2; j++){
            cin >> b[j];
        }
        sort(a, a+k1);
        sort(b, b+k2);

        int maxa = a[k1-1];
        int maxb = b[k2-1];

        if(maxa > maxb){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}
