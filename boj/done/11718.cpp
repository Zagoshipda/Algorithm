//그대로 출력하기 : 입력 받은 대로 출력하기 단, 줄 사이 공백은 없음

#include <iostream>
#include <string>
using namespace std;    //namespace를 정의하지 않으면 std::string 으로 사용

int main(){
    // char input[100];
    // input[0] = "first";  
    // input[1] = "second";

    int cnt = 0;    //반복문 반복횟수 max 100회를 count 하기 위한 int 변수 선언 
    string input[100]; //입력값을 받을 string 형 배열 선언 
   
    //알고리즘 개요 
    //input line을 한줄씩 받고
    //한줄씩 출력하기 
    //내용이 더 이상 없으면 종료 

    //-> 내용을 통째로 받고 통째로 출력하는 것으로 짜보았다. 
    //한줄씩 받고 출력하면 더욱 간단하게  while문 하나로도 가능
    while(cnt != 100){
        getline(cin, input[cnt]);    //cin >> input;
        if(input[cnt].compare("") == 0)
            break;
        cnt++;
    }
    int cnt2 = 0;
    while(cnt2 != cnt){
        cout << input[cnt2] << endl;
        cnt2++;
    }
    

}