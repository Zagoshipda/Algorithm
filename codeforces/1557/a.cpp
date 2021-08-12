#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
double n;

int main(){
    IOS;

    cin >> t;
    while(t--){
        cin >> n;
        vector<double> a(n);
        double max = INT_MIN;
        double sum = 0;
        for(int i=0; i<n; ++i){
            cin >> a[i];
            sum += a[i];
            if(max < a[i]){
                max = a[i];
            }
        }
        cout.precision(10);
        cout << max + (sum-max)/(n-1) << endl;
    }


    return 0;
}
