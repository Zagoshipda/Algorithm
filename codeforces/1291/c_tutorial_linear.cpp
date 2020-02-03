#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    k = min(k, m - 1);
    vector<int> a(n);
    for(auto &x : a)
        cin >> x;
    vector<int> b;
    for(int i = 0; i < m; i++)
        b.push_back(max(a[i], a[i + n - m]));
    // int sz = m - k;
    int ans = 0;
    deque<int> q;
    for(int i = 0, j = 0; i <= k; i++) {
        while(q.size() && q.front() < i)
            q.pop_front();
        while(j <= i + m-1 -k) {
            while(q.size() && b[q.back()] >= b[j]){
                q.pop_back();
            }
            q.push_back(j++);
            cout << q.size() << ' ' << q.front() << endl;
        }
        cout << "print : " << ' ';
        for(int l=0; l<q.size(); ++l){
            cout << q[l] << ' ';
        }
        cout << endl;
        ans = max(ans, b[q.front()]);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);    // 주석처리하면 input 마다 output 출력됨

    int t;
    cin >> t;
    while(t--){
        solve();
    }
        
}
