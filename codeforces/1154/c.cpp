#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    //using ll = long long; range : -9*10^18~9*10^18

// int n, a[10], s=1e18; 
// string s;

//int : 2 g(10억, 21억...)

ll a[4];
int week[7] = {1,2,3,1,3,2,1};
int main(){
	IOS;

    cin >> a[1] >> a[2] >> a[3];
    ll num = a[1]+a[2]+a[3]; //<= 21*10^8

    int cntmax = 0;
    for(int i=0; i<7; i++){
        ll b[4] = {0, a[1], a[2], a[3]};
        int cnt = 0;
            // for(int k=1; k<4; k++){
            //     cout << b[k] << ' ';
            // }
        for(ll j=0; j<num; j++){
            int x = (i+j)%7;    //0~6
            int y = week[x];    //1~3
            if(b[y]<=0){
                break;
                // if(b[3]<=0){
                //     break;
                // }else{
                //     b[y]--;
                //     cnt++;
                // }    
            }else{
                b[y]--;
                cnt++;
            }
        }   
        if(cnt > cntmax){
            cntmax = cnt;
        }
    }
    
    
    cout << cntmax;


    return 0;
}

