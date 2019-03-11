// 피보나치 수 2  --> output 값의 범위를 생각해야 하기 때문에 long long (int) 형 자료형을 사용해서 결과값을 출력해야 함을 명심 

#include <iostream>
using namespace std;

long long fib(int n){ 
    long long f[100]; 
    f[0]=0;
    f[1]=1;
    for(int i=2; i<n+1; i++){
        f[i]=f[i-1]+f[i-2];
    }
    return f[n];
}

int main(){
  int input = 0;
  cin >> input;
  long long output = fib(input);
  cout << output << endl;
}

// Solution ----------------------------
// #include <cstdio>
// long long d[91], n, i;
// int main() {
// 	d[1] = 1; scanf("%d", &n);
// 	for(i = 2; i <= n; ++i)d[i] = d[i - 1] + d[i - 2];
// 	printf("%lld\n", d[n]);
// }