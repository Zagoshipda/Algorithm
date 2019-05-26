// Number Guessing
// interactive problem -> flush after stdout / use scanf, printf rather than cin, cout

// binary search 로 풀기...?

#include<bits/stdc++.h>
using namespace std;

// #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long   

int T, A, B, N;
char input[30];

int main(){
	// IOS;

    scanf("%d", &T);

    for(int i=0; i<T; i++){
            // cin >> A >> B;          // A < P <= B, [A+1...B]
            // cin >> N;               // tries N times to guess finding P
        scanf("%d %d", &A, &B);
        scanf("%d", &N);

        for(int j=0; j<N; j++){
            int ans = (B+(A+1))/2;
            printf("%d \n", ans);       
            fflush(stdout);

            scanf("%s", input);
            if(!strcmp(input, "CORRECT")){
                break;
            }else if(!strcmp(input, "TOO_SMALL")){
                A = ans;
            }else if(!strcmp(input, "TOO_BIG")){
                B = ans;
            }else if(!strcmp(input, "WRONG_ANSWER")){
                exit(0);
            }
        }
    
    }

    return 0;
}

