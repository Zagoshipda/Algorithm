#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    //using ll = long long; range : -9*10^18~9*10^18

// int n, a[10], s=1e18; 
// string s;

int main(){
	IOS;

    int a[4];
    int b[3];
    int cnt = 0;
    int x, y, z;
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    int max = a[0];
    for(int i=1; i<4; i++){
        if(a[i]>max){
            max = a[i];
            cnt = i;
        }
    }
    int j=0;
    for(int i=0; i<4; i++){
        if(i!=cnt){
            b[j] = a[i];
            j++;
        }
    }
    x = b[0] + b[1] - max;
    y = b[0] + b[2] - max;
    z = b[1] + b[2] - max; 
    cout << x << ' ' << y << ' ' << z;
    

    return 0;
}


