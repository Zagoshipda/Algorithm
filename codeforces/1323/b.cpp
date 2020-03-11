#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18)

int n, m, k;
ll ans;

vector<int> counter(vector<int> vec){
    int size = vec.size();
    vector<int> res(size + 1);

    for(int i=0; i<size; ++i){
        if(vec[i] == 0){
            continue;
        }

        // method 1. using for loop
        int j;
        for(int k = i; k < size+1; ++k){
            if(k == size || vec[k] == 0){
                j = k;
                break;
            }
        }
        // cout << j << endl;


        // method 2. using while loop
        // int j = i;
        // while(j < size && vec[j] == 1){
        //     ++j;
        // }

        int len = j - i;
        for(int k = 1; k<=len; ++k){
            res[k] += j - i - k + 1;
        }
        i = j;
    }

    return res;
}

int main(){
    IOS;

    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    for(int i=0; i<m; ++i){
        cin >> b[i];
    }

    auto a2 = counter(a);
    auto b2 = counter(b);

    for(int i=1; i<=n; ++i){
        if(k % i == 0 && k / i <= m){
            ans += a2[i] * b2[k/i];
        }
    }

    cout << ans << endl;
    

    return 0;
}
