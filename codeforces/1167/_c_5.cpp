// by, Radewoosh

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

using namespace std;

const int nax=1000*1007;
int n, m;

int oj[nax];
int roz[nax];

int fin(int v)
{
	if (v!=oj[v])
		oj[v]=fin(oj[v]);
	return oj[v];
}

void uni(int a, int b)
{
	a=fin(a);
	b=fin(b);
	oj[a]=b;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		oj[i]=i;
	for (int i=1; i<=m; i++)
	{
		int x, y;
		int p=-1;
		scanf("%d", &x);
        // 명시적인 x번 반복은 while문을 사용하는 것이 때로는 더 간단한 방법인 듯
		while(x--)
		{
			scanf("%d", &y);
			if (p==-1)          //p = first input of group
				p=y;
			uni(p, y);
		}
	}
	for (int i=1; i<=n; i++)
		roz[fin(i)]++;
	for (int i=1; i<=n; i++)
		printf("%d ", roz[fin(i)]);
	printf("\n");
	return 0;
}
