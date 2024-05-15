// 피보나치 수 3 
// 첫째 줄에 n <= 1,000,000,000,000,000,000 (10^18)
// n번째 피보나치 수를 1,000,000으로 나눈 나머지를 출력 (10^6)
// M = 10^k 일 때, k > 2 라면, 주기는 항상 15 × 10^(k-1)
// 지금 문제에서 주기는 15 00000

#include <iostream>
using namespace std;
const int mod = 1000000;    
const int p = 15*(mod/10);  //period
int fibo[p] = {0,1};    //array for dynamic programming

int main(){
    long long n;
    cin >> n;
    //주기가 p이므로 0 ~ p-1 번째까지 fibo 값만 알면 충분
    for(int i=2; i<p; i++){ 
        fibo[i] = fibo[i-1] + fibo[i-2];
        fibo[i] %= mod; //나머지만 구하면 되므로 값을 저장할 때 나머지만 구해서 저장하면 된다
    }
    cout << fibo[n%p] << '\n';
    return 0;

    // cout << 24/2*3 << endl;  //36
    // cout << 24/(2*3) << endl;   //4
}