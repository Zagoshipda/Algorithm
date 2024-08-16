/*
    https://www.acmicpc.net/problem/10951
        A+B (4) 입력이 있는 한 계속해서 출력하기
        while 조건에 입력을 넣어버리는 것으로 해결
*/

#include <iostream>
using namespace std;

int a, b;
int solve_wrong(){
    // output exceeded
    while(true){
        cin >> a >> b;
        cout << a + b << "\n";
    }
}

int solve(){
    while(cin >> a >> b){
        cout << a + b << "\n";
    }
}

int main(){
    solve();
}