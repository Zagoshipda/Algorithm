#include <iostream>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int i=0;
    int output;
    if(n == 1){
        while(m > 1){
            if(m%2 == 0){
                m = m/2;
            }else if(m%3 == 0){
                m = m/3;
            }else{
                output = -1;
                goto EXIT;
            }
            i++;
        }   
        output = i;
    }else{ //n != 1
        if( m % n != 0){
            output = -1;
        } else {    // m % n == 0
            int r = m / n;
            while(r > 1){
                if(r%2 == 0){
                    r = r/2;
                }else{  //r%3 == 0 
                    r = r/3;
                }
                i++;
            }   
            output = i;
        }
    }
    EXIT:
    cout << output <<'\n';

}