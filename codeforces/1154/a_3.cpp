// A. Restoring Three Numbers
// by, tataky

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;   //더하면 overflow될 수 있으므로 longlong

vector<ll> v;

int main() {
	v.resize(4);
	for(int i=0; i<4; i++){
        scanf("%lld", &v[i]);
    }
	sort(v.begin(), v.end());   //벡터 정렬하기

	//가장 마지막것이 a+b+c, 나머지는 2개씩 더한것들
	printf("%lld %lld %lld\n", v[3]-v[0], v[3]-v[1], v[3]-v[2]);

	return 0;
}