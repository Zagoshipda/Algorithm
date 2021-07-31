#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
int n;

int main(){
    IOS;

    cin >> t;
    while(t--){
        cin >> n;
        if(n <= 1){
            cout << "a" << endl;
            continue;
        }
        string ans;
        int front = n/2;
        int back = front-1;
        for(int i=0; i<front; ++i){
            ans += 'a';
        }
        if(n & 1){
            ans += "bc";
        }
        else{
            ans += "b";
        }
        for(int i=0; i<back; ++i){
            ans += 'a';
        }
        cout << ans << endl;
    }


    return 0;
}
