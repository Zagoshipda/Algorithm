// by kmjp

#include <iostream>
using namespace std;

int main(){
    int n, m; 
    cin >> n >> m;
    if(m % n){
        cout << -1;
        return 0;
    }
    int ret = 0;
    m /= n;
    while(m%2==0) m/=2, ret++;
    while(m%3 ==0) m/=3, ret++;
    if(m==1) cout << ret;
    else cout << -1;
    
    return 0;
}