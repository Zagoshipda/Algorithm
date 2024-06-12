// A+B (9) 일단 현재 나와있는 A+B 문제 중 마지막... 여러 개의 세부문제 (서브테스크) 들로 이루어져 있다.... 

// 이전보다 값의 범위가 커졌다고 생각하면 된다. 
// 첫째 줄에 A와 B (-1010000 ≤ A, B ≤ 1010000)가 주어진다.

// -> long long 으로 받으면 될듯...?

#include <cstdio>
using namespace std;

int main(){
    long long a, b;
    scanf("%d %d", &a, &b);
    printf("%d \n", a+b);
}


// // 파이썬...ㄷ??? https://hsdevelopment.tistory.com/147 
// a, b = input().split()
// a=int(a)
// b=int(b)
// print(a+b)