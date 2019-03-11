// A+B (7) 출력할 때 특정한 출력어구 설정하기 

// 그냥 골치아프게 하지 말고 scanf 쓰는것이 마음 편한듯... ㅅㅂ;;;
// 아무래도 출력은 printf 입력은 scanf 가 짱인듯,,,, 물론 간단한 경우는 cout이랑 cin이 편하긴 하다...

#include <cstdio>
using namespace std;

int main(){
    int T, a, b;
    scanf("%d", &T);
    int i = 1;
    while(i <= T){
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d \n", i,  a+b);
        i++;
    }
}