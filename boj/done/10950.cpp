// A+B (3) - 몇 번 더하기 연산을 수행할지 주어지는 경우 

// 첫째 줄에 테스트 케이스의 개수 T가 주어진다.
// 각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. (0 < A, B < 10)
// 각 테스트 케이스마다 A+B를 출력한다.

#include <iostream>
using namespace std;
int main(){
    int a,b, T;
    cin >> T;
    while(T != 0){
        cin >> a >> b;
        cout << a + b << "\n";
        T--;
    } 
}