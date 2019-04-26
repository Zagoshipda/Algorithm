#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

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
    // 더 간단하게 구하기 
    x = max - b[0];
    y = max - b[1];
    z = max - b[2]; 
    cout << x << ' ' << y << ' ' << z;
    

    return 0;
}


