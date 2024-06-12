// 피사노 주기

// 피보나치 수열을 m으로 나눈 나머지를 이용해서 만든 수열은 주기를 이룬다. 이를 피사노 주기라고 한다. 이제 k(m)을 그 반복하는 부분 수열의 길이, 즉 주기라고 하자. 
// input : 첫째 줄에 테스트 케이스의 개수 P (1 ≤ P ≤ 1000)가 주어진다. 각 테스트 케이스는 N과 M으로 이루어져 있다. N은 테스트 케이스의 번호이고, M은 문제에서 설명한 m이다. (2 ≤ M ≤ 1,000,000)
// output : 각 테스트 케이스마다 테스트 케이스 번호를 출력하고 k(M)을 출력한다.

// 피사노 주기는 다음 공식을 따른다 -> 공식의 수학적 원리 알아보기
// If n = F (2k) (k ≥ 2), then π(n) = 4k; if n = F (2k + 1) (k ≥ 2), then π(n) = 8k + 4

// 주기가 있다 -> 반복되는 수열이 있다 -> 그 반복되는 수열이 어떠한 것인지... 생각해보면...? 문제 해결이 조금 쉬워진다. 

// k(m) ≤ m^2 - 1 = 10^12-1
// int fibo[m^2-1] ...? -> 너무 space를 많이 잡아먹을 듯 

#include <cstdio>
// using namespace std;

// int fib(int n){
//     int a=0,b=1,c=0;
//     if(n<2) return n;
//     for(int i=2; i<n+1; i++){
//         c=a+b;
//         a=b;
//         b=c;
//     }
//     return c;
// }


// int pisano(int n){
//     int a=0,b=1,c=0;
//     if(n<2) return n;
//     for(int i=2; i<n+1; i++){
//         c=a+b;
//         a=b;
//         b=c;
//     }
//     return c;
// }

int main(){
    int P, N, M;
    scanf("%d", &P);    // # of test cases
    printf("P is : %d \n", P);
    while(P){
        scanf("%d %d", &N, &M);
        
        int k = 1;
        // printf("k is : %d \n", k);
        int a=1, b=1, c;
        // printf("a is : %d \n", a);
        for(int i=1; i<M*M; i++){   //여기서 에러가 나는데 i를 long long 으로 바꿔주면 될듯 
            c = (a+b) % M;
            if(b == 1 && c == 1) break;
            a=b;
            b=c;
            k++;
        }
        printf("%d %d \n", N, k);
        P--;
    }
}