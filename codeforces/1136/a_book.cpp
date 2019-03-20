#include <cstdio>

int main(){
    int chap;
    scanf("%d", &chap);
    int l[chap+1], r[chap+1];
    int n=1;
    while(n < chap+1){
        scanf("%d %d", &l[n], &r[n]);
        n++;
    }
    int k;
    scanf("%d", &k);
    int m=1;
    int output = chap;
    while(m < chap+1){
        if(k<=r[m]){
            break;
        } 
        else  
            output--;
            m++;
    }
    printf("%d", output);
}