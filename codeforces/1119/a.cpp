// codeforces global round 2
// https://codeforces.com/contest/1119
// A. Ilya and a Colorful Walk


#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl '\n'

int n;


int main(){
	IOS;
    cin >> n;
    int a[n+1]={0, };

    for(int i=1; i<n+1; i++){
        cin >> a[i];
    }
    int max = 0;
    for(int i=1; i<n; i++){
        for(int j=n; j>i; j--){
            if(max > (n-i+1)){
                goto HERE;
            }
            if((a[i] != a[j]) && (max < (j-i))){
                max = j-i;
            }
        }
    }
    HERE:
    cout << max;



    return 0;
}

