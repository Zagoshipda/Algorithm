//그대로 출력하기2 : 입력 받은 대로 출력하기 단, 공백인 줄이 있을 수 있음 

//idea -> 그냥 한 줄 씩 출력하는 것으로 하고 단지 11718 에서 공백임을 확인하는 조건 input[cnt].compare("") == 0 만 제거하는 형태로 가는 것이 가장 깔끔할 듯. 왜냐하면 공백인 줄이 몇 줄이 되는지를 미리 알 수 없으니 실시간으로 한줄씩 내용을 받아서 출력하게 하는 것이 좋을 것 같다.             

#include <iostream>
#include <string>
using namespace std;    

int main(){
    // string a;
    // string b;  
    // getline(cin, a);
    // getline(cin, b);

    // cout << a << endl << b << endl;
    //getline 은 일단 공백상관 없이 한 라인을 무조건 읽어들임을 알 수 있음 

    int cnt = 0;    //반복문 반복횟수 max 100회를 count 하기 위한 int 변수 선언 
    string input[100]; //입력값을 받을 string 형 배열 선언 
   
    //알고리즘 개요 
    //input line을 한줄씩 받고
    //한줄씩 출력하기 
    //내용이 더 이상 없으면 종료 
    while(cnt != 100){
        getline(cin, input[cnt]);    //cin >> input;
        cout << input[cnt] << endl;
        cnt++;
    }    

}