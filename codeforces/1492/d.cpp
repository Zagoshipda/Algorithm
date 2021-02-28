#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int a, b, k;

int main(){
    IOS;

    cin >> a >> b >> k;
    string x, y;
    if(a == 0 || b == 1){
        if(k == 0){
            if(a == 0){
                for(int i=0; i<b; ++i){
                    x += '1';
                    y += '1';
                }
            }
            else if(b == 1){
                x += '1';
                y += '1';
                for(int i=0; i<a; ++i){
                    x += '0';
                    y += '0';
                }
            }
            cout << "Yes" << endl;
            cout << x << endl;
            cout << y << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    else{
        if(k > a + b - 2){
            cout << "No" << endl;
        }
        else{
            if(k <= a){
                for(int i=0; i<b-1; ++i){
                    x += '1';
                    y += '1';
                }
                if(k > 0){
                    x += '1';
                    y += '0';
                }
                for(int i=0; i<k-1; ++i){
                    x += '0';
                    y += '0';
                }
                if(k > 0){
                    x += '0';
                    y += '1';
                }
                else{
                    x += '1';
                    y += '1';
                }
                for(int i=0; i<a-k; ++i){
                    x += '0';
                    y += '0';
                }
            }
            else{
                int front = k - a;
                int back = a;
                for(int i=0; i<b-front-1; ++i){
                    x += '1';
                    y += '1';
                }
                x += '1';
                y += '0';
                for(int i=0; i<front; ++i){
                    x += '1';
                    y += '1';
                }
                for(int i=0; i<back-1; ++i){
                    x += '0';
                    y += '0';
                }
                x += '0';
                y += '1';

            }
            cout << "Yes" << endl;
            cout << x << endl;
            cout << y << endl;
        }
    }
    

    return 0;
}
