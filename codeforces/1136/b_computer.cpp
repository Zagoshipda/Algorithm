#include <cstdio>

int main(){
    int n,k;
    scanf("%d %d", &n, &k);
    int m = (n+1)/2;
    int output;
    if(k<=m){
        output = 3*n+k-1;
    }else{
        output = 3*n+(n-k);
    }

    printf("%d", output);
}
