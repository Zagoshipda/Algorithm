#include <iostream>
using namespace std;
int main()
{
    int n, m;   //1<= n <= m <= 500 000 000
    cin >> n >> m;

    if(m % n != 0){
        cout << -1;
        return 0;
    }else{  //m % n == 0
        int i=0;
        if(n == 1){
            while(m > 1){
                if(m % 2 == 0){
                    m /= 2;
                    i++;
                }else if(m % 3 == 0){ 
                    m /= 3; 
                    i++;
                }else{
                    cout << -1;
                    return 0;
                }
            }
        }else{
            int r = m/n;
            while(r > 1){
                if(r % 2 == 0){
                    r /= 2;
                    i++;
                }else if(r % 3 == 0){
                    r /= 3;
                    i++;
                }else{
                    cout << -1;
                    return 0;
                }   
            }
        }
        cout << i;
    }

    return 0;
}
