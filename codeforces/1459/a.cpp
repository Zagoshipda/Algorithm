#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int T;
int n;
int red;
int blue;

int main(){
    IOS;

    cin >> T;
    while(T--){
        cin >> n;
        string a, b;
        cin >> a >> b;

        red = blue = 0;
        for(int i=0; i<n; ++i){
            if(a[i] > b[i]){
                ++red;
            }
            else if(a[i] < b[i]){
                ++blue;
            }
        }
        if(red > blue){
            cout << "RED" << endl;
        }
        else if(red < blue){
            cout << "BLUE" << endl;
        }
        else{
            cout << "EQUAL" << endl;
        }
    }

    return 0;
}
