
#include<bits/stdc++.h>
using namespace std;

#define ll long long

// ll n, a[10], b[10]= {5,3,1,6,2, 9,8,7,4,0}, ans, s=1e18; 

//int < 2*10^9

int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0);
    
    cin >> n;
    ll a[n];
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int here =n;
    for(int i=n-1; i>=0; i--){
        if(a[i-1]>=a[i]){
            here = i;
            break;
        }
    }
    ll sum =0;
    if(a[here] == 1){
        for(int i=n-1; i>=here; i--){
            sum += a[i];
        }
        cout << sum;
        exit(0);
    }

    for(int i=n-1; i>=here; i--){
        sum += a[i];
    }
        // cout << here << endl;
    ll x = a[here]-1;
        // cout << x << '\n';
    for(int j=here-1; j>=0 && x>0; j--){
        if(a[j] < x){
            sum += a[j];
            x = a[j];
        }else{
            sum += x;
        }
        x--;
    }
    cout << sum;


    return 0;
}