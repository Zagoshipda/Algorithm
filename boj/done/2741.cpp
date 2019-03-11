// N 찍기

//줄바꿈에 endl 대신 \n을 사용하는 것이 훨씬 더 속도가 빠름 -> endl 사용시 시간초과로 실패. 또한 cout 보다는 printf 함수가 훨씬 더 빠르다고... 
// 참고하기: https://www.acmicpc.net/problem/15552
// https://codecollector.tistory.com/381

#include <iostream>
using namespace std;
int main(){
    int n; 
    cin >> n;
    int i = 1;
    while(i <= n){
        cout << i << "\n";  
        i++;
    }
}