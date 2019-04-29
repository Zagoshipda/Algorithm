#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    //using ll = long long; range : -9*10^18~9*10^18


int n, m;

int aodd, aeven;
int bodd, beven;

int main(){
	IOS;

    cin >> n >> m;
    int a[n];
    int b[m];

    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i]%2 == 0){
            aeven++;
        }else{
            aodd++;
        }
    }
    for(int i=0; i<m; i++){
        cin >> b[i];
        if(b[i]%2 == 0){
            beven++;
        }else{
            bodd++;
        }
    }

    int out = 0;
    int tmp1 = aeven < bodd ? aeven : bodd;
    int tmp2 = beven < aodd ? beven : aodd;
    out = tmp1 + tmp2;
    
    cout << out;
    

    return 0;
}

