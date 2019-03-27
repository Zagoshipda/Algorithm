// by, dotorya

#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")  
using namespace std;

#define mp make_pair  
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size())  
#define rep(i, n) for(int i=0;i<n;i++)  
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

pll in[300050]; //pair <ll, ll> 을 각 원소로 하는 배열 
int main() {
	int N, K, i, j;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) scanf("%lld %lld", &in[i].second, &in[i].first);   //length, beauty

    // *****이 부분이 사실상 알고리즘의 핵심으로, beauty를 기준으로 가장 작은것부터 큰 순서대로(오름차순) 정렬하여 이후의 계산을 반복문for를 통해 처리하게 할 수 있게됨을 관찰하자 
	sort(in + 1, in + N + 1);   // 나 혼자 함수를 따로 만드려 하지 말고 *** sort 함수를 제발 쓰자...

        cout << "after sorting ------ \n";
        for(int i =1; i<=N; i++){
            cout << i << "th first: " << in[i].first << " second: " << in[i].second << '\n';
        }
	ll ans = 0;

        cout << "iteration starts ----- \n";
    //class std::priority_queue<_Ty, _Container, _Pr>
	priority_queue <ll, vector<ll>, greater<ll>> Hx;    
	ll sum = 0;
	for (i = N; i >= 1; i--) {
		Hx.push(in[i].second);
            cout << i << "th length: " << in[i].second << ' ';
		sum += in[i].second;    //length 는 가장 큰 것을 하나씩 빼서 더한다. 

        // 가능한 최대 횟수(size up to k)에 다다르면 다음 loop에서 push하기 위한 자리를 마련해주기 위해 미리 pop으로 queue에서 하나(가장 length가 짧은 것)를 제거한다
		if (Hx.size() > K) {    
			sum -= Hx.top();
                cout << "top: " << Hx.top() << '\n';
			Hx.pop();
		}
            cout << "beauty: " << in[i].first << ' ';
            cout << "sum: " << sum << '\n';
		ans = max(ans, in[i].first * sum);  // *** max함수도 사용하자.... 
	}
	return !printf("%lld\n", ans);  // *좋은 technique : return 0을 하기 위해 프린트한 값(!=0)을 부정하여 전달해서 출력과 main함수 종료를 동시에 처리.
}