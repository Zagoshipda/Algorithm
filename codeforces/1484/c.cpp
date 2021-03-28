#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
int n, m;

int main(){
    IOS;

    cin >> t;
    while(t--){
        int max_cnt = 0;
        int max_cnt_num = 0;
        
        cin >> n >> m;
        vector<int> cnt(n+1);
        vector<int> ans_c(m);
        vector<int> f[m];
        int size;
        for(int i=0; i<m; ++i){
            cin >> size;
            vector<int> ff(size);
            for(int j=0; j<size; ++j){
                cin >> ff[j];
            }
            f[i] = ff;

            ans_c[i] = ff[0];
            ++cnt[ff[0]];
            if(cnt[ff[0]] > max_cnt){
                max_cnt = cnt[ff[0]];
                max_cnt_num = ff[0];
            }
        }

        if(max_cnt > (m+1)/2){
            for(int i=0; i<m; ++i){
                if(f[i][0] == max_cnt_num){
                    for(int j=0; j<f[i].size(); ++j){
                        if(f[i][j] != max_cnt_num){
                            ans_c[i] = f[i][j];
                            --max_cnt;
                            break;
                        }
                    }
                }

                if(max_cnt <= (m+1)/2){
                    break;
                }
            }
        }

        if(max_cnt <= (m+1)/2){
            cout << "YES" << endl;
            for(int i=0; i<m; ++i){
                cout << ans_c[i] << ' ';
            }
            cout << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}
