//피보나치 수 5
// 첫째 줄에 n이 주어진다. n은 20보다 작거나 같은 자연수 또는 0이다.
// 첫째 줄에 n번째 피보나치 수를 출력한다.

#include <iostream>
using namespace std;

int fib(int n){ 
    int f[21];
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
  int n = fib(input);
  cout << n << endl;
}