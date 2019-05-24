// by, mnbvmar

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>    //....?? 무엇?

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())


const int MaxN = 5e5+100;   //이렇게 배열 size를 const int로 선언한 뒤 나중에 할당하는 것이 좋은 방법. 5e5+5 이런 식으로 값을 빠르게 할당하는 것이 명시적으로 0의 개수를 확인하기 좋은 듯 

int fu_parent[MaxN];
int fu_count[MaxN];

int Find(int x) {
  if (x == fu_parent[x]) { return x; }
  return fu_parent[x] = Find(fu_parent[x]);
}

void Union(int u, int v) {
  u = Find(u); v = Find(v);
  if (u != v) {             //서로 다를 때로 조건을 넣는 것이 더 깔끔한 듯
    fu_parent[u] = v;
    fu_count[v] += fu_count[u];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int n, m;
  cin >> n >> m;
  iota(fu_parent, fu_parent + n + 1, 0);    //fu_parent[0...n] 을 각 i번째 element를 i로 초기화
  fill_n(fu_count, n + 1, 1);               //fu_count[0...n] 을 모두 1로 초기화

  for (int j = 0; j < m; ++j) {
    int cnt, fst;
    cin >> cnt;
    if (!cnt) { continue; }
    cin >> fst;

    for (int k = 0; k < cnt-1; ++k) {
      int nxt;
      cin >> nxt;
      Union(fst, nxt);
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << fu_count[Find(i)] << " ";
  }
  cout << "\n";
}
