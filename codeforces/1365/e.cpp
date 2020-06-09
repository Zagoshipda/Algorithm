#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int n;
ll maxVal;

int main(){
	IOS;

    cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }

    if(n < 3){
        for(int i=0; i<n; ++i){
            maxVal |= a[i];
        }
    }
    else{
        ll value = 0;
        for(int i=0; i<n-2; ++i){
            for(int j=i+1; j<n-1; ++j){
                for(int k=j+1; k<n; ++k){
                    value = a[i] | a[j] | a[k];
                    // cout << value << endl;
                    if(value > maxVal){
                        maxVal = value;
                    }
                }
            }
        }
    }

    cout << maxVal << endl;

    return 0;
}
