#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
int n, m;
string s;
int l, r;

int main(){
    IOS;

    cin >> t;
    while(t--){
        cin >> n >> m;
        cin >> s;
        // vector<int> cnt(n);
        vector<int> lsum(n, 0);
        vector<int> lmaxi(n, 0);
        vector<int> lmini(n, 0);
        vector<int> rsum(n, 0);
        vector<int> rmaxi(n, 0);
        vector<int> rmini(n, 0);
        for(int i=0; i<n; ++i){
            // left
            if(s[i] == '-'){
                if(i == 0){
                    lsum[i] = -1;
                }
                else{
                    lsum[i] = lsum[i-1] - 1;
                }
            }
            else if(s[i] == '+'){
                if(i == 0){
                    lsum[i] = 1;
                }
                else{
                    lsum[i] = lsum[i-1] + 1;
                }
            }
            if(i == 0){
                lmaxi[i] = lmini[i] = lsum[i];
            }
            else{
                lmaxi[i] = lmaxi[i-1];
                lmini[i] = lmini[i-1];
                if(lmaxi[i-1] < lsum[i]){
                    lmaxi[i] = lsum[i];
                }
                else if(lsum[i] < lmini[i-1]){
                    lmini[i] = lsum[i];
                }
            }
            
            // right
            if(s[n-1-i] == '-'){
                if(i == 0){
                    rmaxi[n-1-i] = rmini[n-1-i] = -1;
                }
                else{
                    rmaxi[n-1-i] = max(-1, rmaxi[n-i] - 1);
                    rmini[n-1-i] = min(-1, rmini[n-i] - 1);
                }
            }
            else if(s[n-1-i] == '+'){
                if(i == 0){
                    rmaxi[n-1-i] = rmini[n-1-i] = 1;
                }
                else{
                    rmaxi[n-1-i] = max(1, rmaxi[n-i] + 1);
                    rmini[n-1-i] = min(1, rmini[n-i] + 1);
                }
            }
        }

        for(int i=0; i<m; ++i){
            cin >> l >> r;
            int left_max_value = 0, left_min_value = 0, left_sum_value = 0;
            int right_max_value = 0, right_min_value = 0;
            if(l > 1){
                left_max_value = lmaxi[l-2];
                left_min_value = lmini[l-2];
                left_sum_value = lsum[l-2];
            }
            if(r < n){
                right_max_value = rmaxi[r];
                right_min_value = rmini[r];
            }
            // cout << left_max_value << left_min_value << right_max_value << right_min_value << endl;

            int total_max_value = left_sum_value + right_max_value > left_max_value ? left_sum_value + right_max_value : left_max_value;
            int total_min_value = left_sum_value + right_min_value < left_min_value ? left_sum_value + right_min_value : left_min_value;

            // cout << total_max_value << ' ' << total_min_value << endl;
            // cout << total_max_value - total_min_value + 1 << endl;
            if(total_max_value * total_min_value > 0){
                cout << max(abs(total_max_value), abs(total_min_value)) + 1 << endl;
            }
            else{
                cout << total_max_value - total_min_value + 1 << endl;
            }
        }

    }

    return 0;
}
