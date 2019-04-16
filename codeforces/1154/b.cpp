#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    //using ll = long long; range : -9*10^18~9*10^18

// int n, a[10], s=1e18; 
// string s;

int n;

int main(){
	IOS;

    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    // sort(b, b + 10);
    sort(a, a+n);
    int diff = 0;
    int cnt = 0;
    for(int i=1; i<n; i++){
        if(a[i-1] == a[i]){
            continue;
        }
        if(diff == 0){  //처음 다를때
            diff = a[i] - a[i-1];
            cnt++;
        }else{  //두번쨰이상 다를때
            int tmp = a[i] - a[i-1];
            cnt++;
            if(diff == tmp){
                continue;
            }else{
                diff = -1;
                cnt = 0;
                break;
            }
        }
    }
    
    if(cnt == 1 && diff%2 == 0){
        diff = diff/2;
    }
    cout << diff;

    return 0;
}

