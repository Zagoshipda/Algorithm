// 기찍 N (N 찍기 반대 ㅋㅋ)
// 자연수 N이 주어졌을 때, N부터 1까지 한 줄에 하나씩 출력하는 프로그램을 작성하시오 - 첫째 줄부터 N번째 줄 까지 차례대로 출력

#include <iostream>
using namespace std;
int main(){
    int n; 
    cin >> n;
    int i = n;
    while(i > 0){   //0을 제외함에 주의
        cout << i << "\n";  // 마찬가지로 개행에 endl 대신 \n을 사용하는 것이 속도가 훨씬 더 빠르다. 
        i--;
    }
}