// by, ainta 

// 나와 같은 알고리즘, 다만 char형 배열을 그대로 사용하였다. 
// Vasya makes the first move, determine if Vasya has a winning strategy 임을 생각하고 indexing 에 주의해서 관찰하기 

#include<cstdio>
#include<algorithm>
using namespace std;

int n;
char p[301000];

int main() {

	int i;
	scanf("%d", &n);
	scanf("%s", p);

	int T = (n - 11) / 2;
	int c = 0;

	for (i = 0; i < 2 * T + 1; i++) {
		if (p[i] == '8') c++;
	}
	if (c > T) {
		puts("YES");
	}
	else puts("NO");
}