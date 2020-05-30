#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int T;
double h, c, t;
int targetInt;
double targetDouble;
double result1, result2;
double diff1, diff2;

// 438837 375205 410506
// 973303 519683 866255  -> 973303(x=0) / 822096(x=1) / 687918(x=2)

int main(){
    IOS;

    cin >> T;
    while(T--){
        cin >> h >> c >> t;
        if(t == h){
            cout << 1 << endl;
            continue;
        }
        if(t <= (h+c)/2){
            cout << 2 << endl;
            continue;
        }
        targetInt = (int)(t-h)/(h+c-2*t);
        targetDouble = (t-h)/(h+c-2*t);
        // diff1 = targetDouble - targetInt;
        // diff2 = (targetInt + 1) - targetDouble;
        // cout << "values : " << targetInt << ' ' << targetDouble << ' ' << diff1 << ' ' << diff2 << endl;

        result1 = ((targetInt + 1)*h + targetInt*c)/(2*targetInt + 1);
        result2 = ((targetInt + 1 + 1)*h + (targetInt+1)*c)/(2*(targetInt+1) + 1);
        diff1 = abs(result1 - t);
        diff2 = abs(result2 - t);

        if(diff1 <= diff2){
            cout << 2*targetInt + 1 << endl;
        }
        else if(diff1 > diff2){
            cout << 2*(targetInt + 1) + 1<< endl;
        }
    }
    

    return 0;
}
