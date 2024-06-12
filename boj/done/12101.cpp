// 1, 2, 3 더하기 (2) 이번에는 사전순으로 정렬하고 그 순서에 해당하는 덧셈조합을 그대로 출력해야 함

// 첫째 줄에 정수 n과 k가 주어진다. n은 양수이며 11보다 작고, k는 231-1보다 작거나 같은 자연수이다
// n을 1, 2, 3의 합으로 나타내는 방법 중에서 사전 순으로 k번째에 오는 것을 출력한다. k번째 오는 식이 없는 경우에는 -1을 출력한다.

#include <cstdio>
#include <string>
using namespace std;

int cal(int n){
    
}

int main(){
    int sum[11] = {0, 1, 2, 4}; //초기화 (나머지 부분들은 0으로 초기화됨)
    for(int i=4; i<11; i++)
        sum[i] = sum[i-1] + sum[i-2] + sum[i-3];
    int n, k;
    scanf("%d %d", &n, &k);
    if(k > sum[n]) return -1;
    string out;
    



    // //배열 초기화에 대한 재미있는 예제 
    // int arr[11] = {0, 1, 2, 4};
    // printf("%d %d %d %d\n", arr[3], arr[4], arr[5], arr[11]);   //4 0 0 (쓰레기값-계속바뀜..???)  

    // int arr2[11];
    // arr2[0] = 1;
    // printf("%d %d %d %d", arr2[0], arr2[1], arr2[2], arr2[3]);   //1 (쓰레기값-일정) (쓰레기값-계속바뀜..???) (쓰레기값-일정..??)
}