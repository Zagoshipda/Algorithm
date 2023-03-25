#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 50'001
int n;
int squares[SIZE];

void calculate_minimum_number_of_squares(){
    for(int i=1; i<=n; ++i){
        squares[i] = i;
    }

    for(int i=2; i<=n; ++i){
        for(int j=1; j*j<=i; ++j){
            squares[i] = min(squares[i], squares[i-j*j] + 1);
        }
    }

    cout << squares[n] << endl;
}

int main(){
    IOS;

    cin >> n;

    calculate_minimum_number_of_squares();

    return 0;
}
