// A+B (6) 두 수가 , 로 구분되어 있는 경우 

// 첫째 줄에 테스트 케이스의 개수 T가 주어진다.
// 각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. A와 B는 콤마(,)로 구분되어 있다. (0 < A, B < 10)
// 각 테스트 케이스마다 A+B를 출력한다.

// 그냥 골치아프게 하지 말고 scanf 쓰는것이 마음 편한듯... ㅅㅂ;;;

#include <cstdio>
using namespace std;

int main(){
    int T, a, b;
    scanf("%d", &T);
    while(T > 0){
        scanf("%d,%d", &a, &b);
        printf("%d \n", a+b);
        T--;
    }
    
    // string input;
    // char* a;
    // getline(cin, input);
    // strtok(input, ",", a);

    // cout << input << " " << a << endl;

    // char test[20] = "abcd efgh";
    // cout << strtok(test, "d") << endl;  //abc
    // cout << test << endl;   //abc
    // test[3] = 'a';
    // cout << test << endl;   //abca efgh

    // strtok 예제
    // char* result;
    // char str[5] = "1, 2";
    // result = strtok(str, ",");
    // while(result != NULL){
    //     cout << result << "\n";
    //     result = strtok(NULL, " ");
    // }


    // while(true){   
    //     cin >> a >> b;
    //     if(a == 0 && b == 0) break;
    //     cout << a + b << "\n";
    // }
}