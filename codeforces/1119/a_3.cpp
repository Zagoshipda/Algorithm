#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define endl '\n'

int n, cnt1, cnt2;

int main(){
	IOS;
    cin >> n;
    int a[n+1]={0, };

    for(int i=1; i<n+1; i++){
        cin >> a[i];
    }
    int max = 0;    //output: maximum possible distance 

    int s = 1;
    int e = n;
    if(a[s] != a[e]){
        max = e-s;
    }else{  //a[s] == a[e]
        int first = a[s];
        int last = a[e];
        for(int i=s+1; i<e+1; i++){
            if(a[i] != last){
                cnt1 = e-i;    
                break;
            }
        }
        for(int j=e; j>s-1; j--){
            if(a[j] != first){
                cnt2 = j-s;   
                break;
            }
        }
        max = (cnt1 > cnt2) ? cnt1 : cnt2;
    }

    cout << max;

    return 0;
}

