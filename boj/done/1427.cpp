#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long

string N;

int main(void){

    cin >> N;
    
    int len = N.length();
    int ans[len];
    fill_n(ans, len, 0);

    for(int i=0; i<len; ++i){
        ans[i] = N[i] - '0';
    }
    sort(ans, ans+len);

    for(int i=0; i<len; ++i){
        cout << ans[len-1-i];
    }
    cout << endl;

    return 0;
}
