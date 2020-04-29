#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
int a, b, q;
ll l, r;

int main(){
    IOS;

    cin >> t;
    while(t--){
        cin >> a >> b >> q;
        // int big = (a > b) ? a : b;
        // int small = (a > b) ? b : a;
        // vector<int> val1(a*b + 1);
        // vector<int> val2(a*b + 1);
        // for(int i=1; i<=a*b; ++i){
        //     // val1[i] = (i % small) % big;
        //     // val2[i] = (i % big) % small;
        //     val1[i] = (i % a) % b;
        //     val2[i] = (i % b) % a;
        //     // if(i % big == 0){
        //     //     val2[i] = 0;
        //     // }
        //     // else if(i % big < small){
        //     //     val2[i] = i % big;
        //     // }
        //     // else if(i % big == small){
        //     //     val2[i] = 0;
        //     // }
        //     // else if(i % big < big){
        //     //     val2[i] = (i % big - small) % small;
        //     // }
        // }
        // cout << "val1 : ";
        // for(int i=1; i<=a*b; ++i){
        //     cout << val1[i] << ' '; 
        // }
        // cout << endl;
        // cout << "val2 : ";
        // for(int i=1; i<=a*b; ++i){
        //     cout << val2[i] << ' ';
        // }
        // cout << endl;

        vector<ll> cnt(a*b + 1);
        for(int i=1; i<=a*b; ++i){
            cnt[i] = cnt[i - 1];
            if((i % a) % b != (i % b) % a){
                ++cnt[i];
            }
        }
        // for(int i=0; i<=a*b; ++i){
        //     cout << cnt[i] << ' ';
        // }
        // cout << endl;

        vector<ll> ans(q + 1);
        for(int i=1; i<=q; ++i){
            cin >> l >> r;
            ans[i] = ((r / (a*b)) * cnt[cnt.size()-1] + cnt[r%(a*b)]) - (((l-1) / (a*b)) * cnt[cnt.size()-1] + cnt[(l-1)%(a*b)]);

            // ll q1 = (l-1) / (a*b);
            // ll q2 = r / (a*b);
            // if(q1 == q2){ 
            //     ans[i] = cnt[r%(a*b)] - cnt[(l-1)%(a*b)];
            // }
            // else{
            //     ans[i] = (cnt[cnt.size()-1] - cnt[(l-1)%(a*b)]) + (q2 - q1 - 1) * cnt[cnt.size()-1] + cnt[r%(a*b)];
            // }
        }
        for(int i=1; i<=q; ++i){
            cout << ans[i] << ' ';
        }
        cout << endl;
    }


    return 0;
}
