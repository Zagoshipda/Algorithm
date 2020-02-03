#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t, n;

int main(){
    IOS;

    cin >> t;
    for(int i=0; i<t; ++i){
        cin >> n;
        vector<int> a;
        int input;
        for(int j=0; j<n; ++j){
            cin >> input;
            a.push_back(input);
        }
        int pre = -1, post = n;
        for(int j=0; j<n; ++j){
            if(a[j] >= j){
                ++pre;
            }
            else{
                break;
            }
        }
        for(int j=n-1; j>=0; --j){
            if(a[j] >= n-1 - j){
                --post;
            }
            else{
                break;
            }
        }
        if(post <= pre){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }

    }


    return 0;
}
