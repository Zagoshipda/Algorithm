#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define int long long
#define endl '\n'

// int n, ans, a[10], s=1e18; 
// string s;

int n;

int findMax(int b[], int s, int e){
    int out = 0;
    if(e == s+1){
        if(s!= e){
            return 1;
        }else{
            return 0;
        }
    }
    int temp = (b[s] == b[e]) ? 0 : e-s;
    out = max(findMax(b, s, e-1), findMax(b, s+1, e));
    out = max(temp, out);
    return out;
}

int main(){
	IOS;
    cin >> n;
    int a[n+1]={0, };

    for(int i=1; i<n+1; i++){
        cin >> a[i];
    }
    int max = 0;    //output: maximum possible distance 
    max = findMax(a, 1, n);
        

    cout << max;



    return 0;
}

