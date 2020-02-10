#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int N;
string s;

int main(){
    IOS;

    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> s;
        if((s[s.length()-1] - '0') & 1){
            cout << "odd" << endl;
        }
        else{
            cout << "even" << endl;
        }
    }

    return 0;
}
