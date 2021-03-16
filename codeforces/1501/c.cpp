#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int n;
vector<pair<int, int>> ans[5000000];

int main(){
    IOS;

    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }

    int sum;
    for(int i=0; i<n; ++i){
        for(int j=0; j<i; ++j){ // Time limit exceeded : int j=i+1; j<n; ++j
            sum = a[i] + a[j];
            for(auto vec : ans[sum - 1]){
                if(vec.first != i && vec.first != j && vec.second != i && vec.second != j){
                    cout << "YES" << endl;
                    cout << i + 1 << ' ' << j + 1 << ' ' << vec.first + 1 << ' ' << vec.second + 1 << endl;
                    return 0;
                }
            }
            ans[sum - 1].push_back(make_pair(i, j));
        }
    }
    cout << "NO" << endl;

    return 0;
}
