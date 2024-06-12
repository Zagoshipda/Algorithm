//dynamic programming 연습해보자... 그냥 머가리로는 안될듯;;;

//결국 N까지의 해당하는 연산의 횟수의 최소값들을 저장하는 배열 arr[n]을 만들고 이를 이용하기로 하자. 

#include <iostream>
using namespace std;

int main(){
    
    // int n = 1000000;   //10^6 를 하면 bit 연산자가 된다
    int arr[1000000];   //max ~10^6
    int N;  //input
    int check(int N);
    cin >> N;
    cout << n;

}

int check(int n){
    if(n==1) return 0;
    if(n % 2 ==0){

    }
    if(n % 3 ==0){
        int temp = check(n/3) +1;
    
    }
}