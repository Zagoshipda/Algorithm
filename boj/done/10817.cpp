// 세 수 : 세 정수 A, B, C가 주어진다. 이때, 두 번째로 큰 정수를 출력하는 프로그램을 작성하시오. 첫째 줄에 세 정수 A, B, C가 공백으로 구분되어 주어진다. (1 ≤ A, B, C ≤ 100) 두 번째로 큰 정수를 출력한다.

// 등호를 넣지 않아도 된다...!! 

#include <cstdio>

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int n = 0;
    if(a>b){
        if(b>c) n = b;
        else{
            if(a>c) n = c;
            else n = a;
        }  
    }else{
        if(b<c) n = b;
        else{
            if(a>c) n = a;
            else n = c;
        }
    }
    printf("%d", n);
}



// // by woqja125 : 비트 연산자를 통한 간단한 swap
// #include<stdio.h>
// void max(int &a, int &b){if(a<b) a^=b^=a^=b;}   //bit xor 연산자, a와 b의 순서를 바꿈 
// int main()
// {
//     int a, b, c; scanf("%d%d%d", &a, &b, &c);
//     max(a, b); max(a, c); max(b, c);
//     printf("%d", b); //중간값인 b 를 출력
//     return 0;
// }

// //by b1011dong : () ? a : b 조건문을 이용해 경우의 수 간단하게 표현하기 
// #include <stdio.h>
// int main()
// {
// 	int a, b, c;
// 	scanf("%d%d%d", &a, &b, &c);
// 	printf("%d", a > b ? (c > a ? a : (c > b ? c : b)) : (c > b ? b : (a > c ? a : c)));
// 	return 0;
// }