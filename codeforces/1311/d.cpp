#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // -9*10^18 ~ 9*10^18

int t;
int a, b, c;

int main(void){
    IOS;

    cin >> t;
    while(t--){
        cin >> a >> b >> c;

        int A = 0, B = 0, C = 0;
        int min = INT_MAX;
        for(int tempA=1; tempA<=2*a; ++tempA){
            for(int tempB=tempA; tempB<=2*b; tempB+=tempA){
                // if(tempB%tempA){
                //     continue;
                // }
                for(int k=0; k<2; ++k){
                    int tempC = (c/tempB)*tempB + k*tempB;
                    int diff = abs(tempA - a) + abs(tempB - b) + abs(tempC - c);
                    if(diff < min){
                        A = tempA;
                        B = tempB;
                        C = tempC;
                        min = diff;
                    }
                }
            }
        }
        
        cout << min << endl;
        cout << A << ' ' << B << ' ' << C << endl;


    }    


    return 0;
}
