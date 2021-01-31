#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
int n;

int main(){
    IOS;

    int total_num;
    cin >> t;
    total_num = t;
    int cnt=0;
    while(t--){
        cin >> n;
        int _size = 2*n;
        vector<ll> d(_size);
        for(int i=0; i<_size; ++i){
            cin >> d[i];
        }

        // if(total_num > 20000 && ++cnt == 140){
        //     for(int cnt_i=0; cnt_i<_size; ++cnt_i){
        //         cout << d[cnt_i] << ' ';
        //     }
        //     cout << endl;
        //     continue;
        // }
        sort(d.begin(), d.end());
        bool flag = true;
        ll prev = -1;
        bool is_found = false;
        vector<ll> diff_sum(n-1);
        int _divisor = 2;
        for(int i=0; i<_size; ++i){
            if(prev >= 0){
                if(prev == d[i]){
                    if(is_found){
                        cout << "NO" << endl;
                        flag = false;
                        break;
                    }
                    else{
                        is_found = true;
                    }
                }
                else{
                    if(is_found){
                        if((d[i] - d[i-1]) % _divisor){
                            cout << "NO" << endl;
                            flag = false;
                            break;
                        }
                        else{
                            diff_sum[(i-1)/2] = (d[i] - d[i-1]) / _divisor;
                            _divisor += 2;
                            is_found = false;
                        }
                    }
                    else{
                        cout << "NO" << endl;
                        flag = false;
                        break;
                    }
                }
            }
            prev = d[i];
        }
        if(flag){
            // cout << "diff_sum : " << endl;
            // for(int i=0; i<n-1; ++i){
            //     cout << diff_sum[i] << ' ';
            // }
            // cout << endl;
            ll _diff_sum = 0;
            for(int i=0; i<n-1; ++i){
                // cout << (n-1-i) << ' ' << diff_sum[i] << endl; 
                _diff_sum += (n-1-i) * diff_sum[i]; 
            }
            _diff_sum *= 2;
            // cout << "d[0] / _diff_sum : " << d[0] << ' ' << _diff_sum << ' ' << d[0] - _diff_sum << endl;
            if(d[0] - _diff_sum > 0 && ((d[0] - _diff_sum) % (2*n)) == 0){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
