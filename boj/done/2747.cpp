//피보나치 수 1. 간단하게 dynamic programming 활용해서 해결가능 
// 0번째 피보나치 수는 f 배열을 선언할 때 f[0]=0으로 초기화되므로 이미 지정되는 것이라 생각할 수 있음. 45번째까지의 피보나치 수를 구하는 것이므로 int 자료형만으로도 결과값을 저장할 수 있어 int를 사용하는 것이 가장 효율적인 메모리 공간사용방법. 

#include <iostream>
using namespace std;

int fib(int n){ 
    int f[100]; 
    f[1]=1;
    f[2]=1;
    for(int i=3; i<n+1; i++){
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