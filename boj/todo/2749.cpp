// 피보나치 수 3 -> 피사노 주기 pisano period 를 이용한 해결
//첫째 줄에 n이 주어진다. n은 1,000,000,000,000,000,000보다 작거나 같은 자연수이다.
//첫째 줄에 n번째 피보나치 수를 1,000,000으로 나눈 나머지를 출력한다.

// -> 이번에는 구해야 하는 피보나치 수의 범위가 매우 커졌다. 일단 long long 배열공간을 마련해서 해보면, size of array f is too large 라는 에러 메세지가 출력된다... -> 배열의 공간을 미리 확보하는 것이 불가능.... 동적으로 배열의 공간을 확보하는 것이 필요할 듯 하다.
// 물론 그렇다고 방법 자체를 recursion으로 사용하면 애초에 계산 시간이 너무 오래 걸릴 것이 뻔하다. 
// 계속 에러가 났는데 보다 근본적인 문제는 우선 피보나치 수가 너무 커져서 이번에는 long long 의 표현범위마저도 넘어서게 된다는 결과가 나왔다는 것이다. 대략 90을 넘기면서부터 에러가 발생함-long long의 표현범위를 넘어섬- 을 확인할 수 있다.
// 그러나 이번 문제의 경우 1000,000으로 나눈 나머지를 구해야 한다는 것으로부터 피사노 주기 pisano period 와 관련하여 문제를 해결할 수 있다고 한다. 


#include <iostream>
// #include <cstdio>
#include <cmath>
using namespace std;

// input: integer n -> output: returns nth fib num % 1000000 
// 값의 범위가 너무 커지는 것을 방지하기 위해 애초에 계산에서부터 나머지들끼리만 계산하면 된다...!! -> 더하기를 해도 mod 는 유지되니깐!!
int fib(int n){ 
    int a = 0;
    int b = 1;
    int c = 0;
    if(n < 2) return n;
    for(int i = 2; i < n+1; i++){
        c = (a + b) % 1000000 ;
        a = b % 1000000 ;
        b = c % 1000000 ;
    }
    return c;
}

// 0, 1, 1, 2, 3, 5/ 8, 13, 21, 34, 55/ 89, 144, 233, 377, 610/ 987, 1597
// input <= 10^18, longlong <= 9*10^18
// n > 2라면, k(10^n) = 15×10^(n-1)
// k(10^6) = 15*10^5 = 15*pow(10,5)

int main(){
  long long input = 0;
  int n = 0;
  cin >> input;
  long long m = 15*pow(10,5);
  n = input % m;  
  int output = fib(n);
  // int output = 3* pow(10, 3);  //3*10^3
  cout << output << endl;
  // cout << output % 1000000 << endl;
}
