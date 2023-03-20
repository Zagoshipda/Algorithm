#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
=============== INPUT ===============
4
1 4 5 1

*/

#define SIZE 100001
int n;
int arr[SIZE];
int amount[SIZE];
int max_amount;

void calculate_max_amount(){
    amount[0] = arr[0];
    amount[1] = arr[0] + arr[1];
    amount[2] = max(arr[0] + arr[1], max(arr[1] + arr[2], arr[0] + arr[2]));
    for(int pos=3; pos<n; ++pos){
        // amount[pos] = max(amount[pos-4] + arr[pos-2] + arr[pos-1], max(amount[pos-3] + arr[pos-1] + arr[pos], amount[pos-2] + arr[pos]));
        amount[pos] = max(amount[pos-1], max(amount[pos-3] + arr[pos-1] + arr[pos], amount[pos-2] + arr[pos]));
    }

    // for(int i=0; i<n; ++i){
    //     cout << amount[i] << " ";
    // }
    // cout << endl;
    max_amount = amount[n-1];
}

int main(){
    IOS;

    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }

    calculate_max_amount();

    cout << max_amount << endl;

    return 0;
}
