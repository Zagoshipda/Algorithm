#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int N;
long long pinary_number[91][2];
long long num;

void calculate_number_of_pinary_number(){
    pinary_number[1][0] = 0;
    pinary_number[1][1] = 1;

    for(int pos=2; pos<=N; ++pos){
        pinary_number[pos][0] = pinary_number[pos-1][0] + pinary_number[pos-1][1];
        pinary_number[pos][1] = pinary_number[pos-1][0];
    }

    num = pinary_number[N][0] + pinary_number[N][1];
}

int main(){
    IOS;

    cin >> N;

    calculate_number_of_pinary_number();

    cout << num << endl;

    return 0;
}
