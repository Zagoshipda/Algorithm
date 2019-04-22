// Educational Codeforces Round 63 (Rated for Div. 2)
// B. Game with Telephone Numbers
// by, Um_nik 

// 가장 오른쪽 10개의 숫자를 제외한 나머지 숫자들 중 (8이 나타나는 횟수 > 8 이외의 다른 숫자가 나타나는 횟수) 의 조건만 만족하면 됨을 이용한다. 

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int n;
const int N = 100100;
char s[N];

int main(){
	IOS;

    scanf("%d %s", &n, s);
	int cnt = 0;
	for (int i = 0; i < n - 10; i++) {
		if (s[i] == '8')
			cnt++;
		else
			cnt--;
	}
	if (cnt > 0)
		printf("YES\n");
	else
		printf("NO\n");


    return 0;
}

