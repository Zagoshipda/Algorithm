#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    //using ll = long long; range : -9*10^18~9*10^18

int x;
int cnt;


bool checker(int n){
	int m = n & (n-1);
	if( m == 0 ){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	IOS;
    int out[40] = {-1};
    cin >> x;
    if(checker(x+1)){
        cout << 0 << endl;
        return 0;
    }
    int k;
    int k2 = 0;
    for(k=0; k<40; k++){
        if(k%2==0){
                // cout << x << endl;
            int tmp = 1;
            int tmpcnt = 0;
            int maxcnt = 0;
            while(tmp<=x){
                tmp = tmp << 1;
                maxcnt++;
            }
            maxcnt--;
                // int twos[maxcnt+1] = {0};
            int tmpx = x;
            for(int i = maxcnt; i>=0; i--){
                tmp = 1;
                tmp = tmp << i;
                if(tmp <= tmpx){
                    tmpx -= tmp;
                    continue;
                }else{  // tmp > tmpx
                    tmpcnt = i;
                    break;
                }
            }
            tmpcnt++;
            out[k2] = tmpcnt;
            k2++;
            int opA = 0;
            for(int i=0; i<tmpcnt; i++){
                opA += pow(2, i);
            }
                // cout << opA << endl;
            x ^= opA;
                // cout << x << endl;
            if(checker(x+1)){
                break;
            }
        }else{
            x = x+1;
                // cout << x << endl;
            if(checker(x+1)){
                break;
            }
        }
    }

    
    cout << k+1 << endl;
    for(int h=0; h<k2; h++){
        cout << out[h] << ' ';
    }
    



    return 0;
}

