#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long

int t;
int n;
const int SIZE = 200000;
int a[SIZE];

int k;
int l1[2], l2[2];

bool used[SIZE+1];
bool judge(int arr[], int n){
    for(int i=1; i<=n; ++i){
        used[i] = false;
    }
    for(int i=0; i<n; ++i){
        used[arr[i]] = true;
    }
    for(int i=1; i<=n; ++i){
        if(!used[i]){
            return false;
        }
    }
    return true;
}

int main(void){
    IOS;

    cin >> t;
    while(t--){
        k = 0;

        cin >> n;
        int max = 0;
        for(int i=0; i<n; ++i){
            cin >> a[i];
            if(max < a[i]){
                max = a[i];
            }
        }

        if(judge(a, max) && judge(a+max, n-max)){
            l1[k] = max;
            l2[k] = n-max;
            ++k;
        }

        if(max != n-max && judge(a, n-max) && judge(a+n-max, max)){
            l1[k] = n-max;
            l2[k] = max;
            ++k;
        }

        cout << k << endl;
        for(int i=0; i<k; ++i){
            cout << l1[i] << ' ' << l2[i] << endl;
        }

    }


    return 0;
}
