#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
char a[9][9];

int main(){
    IOS;

    cin >> t;
    while(t--){
        for(int i=0; i<9; ++i){
            string input;
            cin >> input;
            for(int j=0; j<9; ++j){
                a[i][j] = input[j];
                if(a[i][j] == '1'){
                    a[i][j] = '2';
                }
            }
        }
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                cout << a[i][j];
            }
            cout << endl;
        }
    }
    

    return 0;
}
