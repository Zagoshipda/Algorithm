#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int T;
int N;
string number;
string information;
int max_bomb_number;

void calculate_max_bomb_number_1(){
    max_bomb_number = 0;

    if(number[0] -'0' > 0){
        max_bomb_number += (1 + (number[0] - '0'));
    }
    for(int i=1; i<N-1; ++i){
        if(number[i] - '0' > 0){
            max_bomb_number += (number[i] - '0');
        }
    }
    if(number[N-1] - '0' > 0){
        max_bomb_number += (1 + (number[N-1] - '0'));
    }

    max_bomb_number /= 3;
}

void calculate_max_bomb_number_2(){
    max_bomb_number = 0;

    for(int i=0; i<N; ++i){
        max_bomb_number += (number[i] - '0');
    }

    max_bomb_number += 2;
    max_bomb_number /= 3;
}

void calculate_max_bomb_number_3(){
    max_bomb_number = 0;

    if(number[0] - '0' > 0 && number[1] - '0' > 0){
        ++max_bomb_number;
        --number[0];
        --number[1];
        // number[0] = ((number[0] - '0') - 1) + '0';
        // number[1] = ((number[1] - '0') - 1) + '0';
    }
    for(int i=1; i<N-1; ++i){
        if(number[i-1] - '0' > 0 && number[i] - '0' > 0 && number[i+1] - '0' > 0){
            ++max_bomb_number;
            --number[i-1];
            --number[i];
            --number[i+1];
            // number[i-1] = ((number[i-1] - '0') - 1) + '0';
            // number[i] = ((number[i] - '0') - 1) + '0';
            // number[i+1] = ((number[i+1] - '0') - 1) + '0';
        }
    }
    if(number[N-2] - '0' > 0 && number[N-1] - '0' > 0){
        ++max_bomb_number;
        --number[N-2];
        --number[N-1];
        // number[N-2] = ((number[N-2] - '0') - 1) + '0';
        // number[N-1] = ((number[N-1] - '0') - 1) + '0';
    }
}

int main(){
    IOS;

    cin >> T;
    while(T--){
        cin >> N;
        cin >> number;
        cin >> information;

        // calculate_max_bomb_number_1();
        // calculate_max_bomb_number_2();
        calculate_max_bomb_number_3();

        cout << max_bomb_number << endl;
    }

    return 0;
}
