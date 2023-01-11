#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int a, b, c;
int val[101][101][101];
const int offset = 50;

int w(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0){
        return 1;
    }

    if(val[a][b][c] > 0){
        return val[a][b][c];
    }

    if(a > 20 || b > 20 || c > 20){
        val[a][b][c] = w(20, 20, 20);
        return val[a][b][c];
    }
    if(a < b && b < c){
        val[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
        return val[a][b][c];
    }

    val[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    return val[a][b][c];
}

int main(){
    IOS;
    while(true){
        cin >> a >> b >> c;

        if(a == -1 && b == -1 && c == -1){
            break;
        }

        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
    }

    return 0;
}
