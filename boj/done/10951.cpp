//A+B (4) 입력이 있는 한 계속해서 출력하기 
// -> while 조건에 입력을 넣어버리는 것으로 해결할 수 있다 ....!! 

#include <iostream>
using namespace std;

int main(){
    int a, b;
    while(cin >> a >> b){   
        cout << a + b << "\n";
    }
}