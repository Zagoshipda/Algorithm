// Codeforces Round #558 (Div. 2)
// a. Eating Soup, rating 1000

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int n, m;
int out;

int main(){
	IOS;
    cin >> n >> m;
    
    int d = n - m;
    
    if(m == 0){
        out = 1;
        cout << out << endl;
        return 0;
    }
    if(m == n){
        out = 0;
        cout << out << endl;
        exit(0);
    }
    if(d >= m){
        out = m;
        cout << out << endl;
    }else{  //d < m
        out = d;
        cout << out << endl;
    }

    return 0;
}





