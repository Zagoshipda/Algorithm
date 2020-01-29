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
    for(int i=0; i<t; i++){
        int a[3];
        cin >> a[0] >> a[1] >> a[2] >> n;
        sort(a, a+3);
        int maxNum = a[2];
        int diff1 = maxNum - a[0];
        int diff2 = maxNum - a[1];
        int diff3 = maxNum - a[2];
        int sum = diff1 + diff2 + diff3;
        if(sum > n){
            cout << "NO" << endl;
            continue;
        }
        else{
            int left = n - sum;
            if(left % 3 == 0){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
    

    return 0;
}
