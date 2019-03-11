// A+B (8) 이 역시나 7과 똑같이 출력할 때 적절히 멘트 설정하기...

#include <cstdio>
using namespace std;

int main(){
    int T, a, b;
    scanf("%d", &T);
    int i = 1;
    while(i <= T){
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d + %d = %d \n", i, a, b, a+b);
        i++;
    }
}