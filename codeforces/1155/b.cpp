#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int n;

int main(){
	IOS;

    cin >> n;
    char s[n];
    cin >> s;
    int num[n+1] = {0};
    for(int i=1; i<=n; i++){
        num[i] = (int)s[i-1]-48;
    }
    
        // for(int i=1; i<=n; i++){
        //     cout << num[i] << ' ';
        // }

    int cnt = 0;
    for(int i =1; i<=n-10; i++){
        if(num[i] == 8){
            cnt++;
        }
    }

    if(cnt >= (n-10+1)/2){
        cout << "YES";
    }else{
        cout << "NO";
    }


    return 0;
}

