#include<iostream>
#include<string>
using namespace std;
 
int main(){
 
    string str;
    while (true)
    {
        getline(cin, str);
        if (str=="")
            break;
        cout << str << endl;
    }
 
    return 0;
}


// 출처: https://kih0902.tistory.com/22 