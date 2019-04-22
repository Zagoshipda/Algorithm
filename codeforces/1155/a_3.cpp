// Educational Codeforces Round 63 (Rated for Div. 2)
// A. Reverse a Substring
// by, Um_nik 

// 어차피 순서가 역전된 길이 2짜리 연속된 2개의 알파벳만 찾으면 된다.
// 핵심이 되는 원리를 파악하고 가장 작은 문제를 찾아 전체 문제 해결하기 

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

const int N = 300300;
int n;
char s[N];

int main(){
	IOS;

    scanf("%d %s", &n, s);

	for (int i = 0; i < n-1; i++) {
		if (s[i] > s[i+1]) {
			printf("YES \n");
			printf("%d %d \n", i+1, i+2);
			return 0;   //return 을 통한 main 함수 종료 
		}
	}
	printf("NO \n");

	return 0;
}

