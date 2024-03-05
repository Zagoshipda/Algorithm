/*
    https://www.acmicpc.net/problem/2981
    (granica)

    similar problem
        https://www.acmicpc.net/problem/1684
        (same remainder)

    solutions
        https://www.acmicpc.net/source/21611522
        (minjun623, 0 ms) : using absolute value & stack, implemented in solve_2()
        https://www.acmicpc.net/source/8934198
        (harinboy, 0 ms)

        2-pass iteration for finding divisors, implemented in solve_3()
        https://www.acmicpc.net/source/390700
        (koosaga, 0 ms)
        https://www.acmicpc.net/source/1615161
        (cozyyg, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

    find all divisor M that makes all remainders of N numbers to be the same
    M > 1

2
10 1000000000

// 2 3 5 6 9 10 11 15 18 22 30 33 45 55 66 73 90 99 101 110 137 146 165 198 202 219 274 303 330 365 411 438 495 505 606 657 685 730 803 822 909 990 1010 1095 1111 1233 1314 1370 1507 1515 1606 1818 2055 2190 2222 2409 2466 3014 3030 3285 3333 4015 4110 4521 4545 4818 5555 6165 6570 6666 7227 7373 7535 8030 9042 9090 9999 10001 11110 12045 12330 13563 13837 14454 14746 15070 16665 19998 20002 22119 22605 24090 27126 27674 30003 33330 36135 36865 41511 44238 45210 49995 50005 60006 66357 67815 69185 72270 73730 81103 83022 90009 99990 100010 110011 110595 124533 132714 135630 138370 150015 152207 162206 180018 207555 220022 221190 243309 249066 300030 304414 330033 331785 405515 415110 450045 456621 486618 550055 622665 660066 663570 729927 761035 811030 900090 913242 990099 1010101 1100110 1216545 1245330 1369863 1459854 1522070 1650165 1980198 2020202 2283105 2433090 2739726 3030303 3300330 3649635 4566210 4950495 5050505 6060606 6849315 7299270 9090909 9900990 10101010 11111111 13698630 15151515 18181818 22222222 30303030 33333333 45454545 55555555 66666666 90909090 99999999 111111110 166666665 199999998 333333330 499999995 999999990

*/

const int NUM = 100;
const int MAX_NUM = 1'000'000'000;
int N;
int numbers[NUM + 1];

int gcd_recursive(int num_1, int num_2){
    if(num_2 <= 0){
        return num_1;
    }

    return gcd_recursive(num_2, num_1 % num_2);
}

void solve_1(){
    sort(numbers+1, numbers+1+N, less<int>());

    int diff = numbers[2] - numbers[1];
    for(int idx=2; idx<=N; ++idx){
        diff = gcd_recursive(diff, numbers[idx+1] - numbers[idx]);
    }

    // time exceeded
    // for(int div=2; div<=diff; ++div){
    //     if(diff % div <= 0){
    //         cout << div << " ";
    //     }
    // }

    // NOTE : answer - divisors must be sorted in ascending order
    vector<int> ans;
    for(int div=2; div*div<=diff; ++div){
    // for(ll div=2; div*div<=diff; ++div){
        if(diff % div <= 0){
            if(div != diff / div){
                ans.push_back(div);
                ans.push_back(diff/div);
            }
            else{
                ans.push_back(div);
            }
        }
    }
    ans.push_back(diff);

    sort(ans.begin(), ans.end(), less<int>());
    for(int num : ans){
        cout << num << " ";
    }
    cout << endl;
}

void solve_2(){
    int diff = abs(numbers[1] - numbers[2]);

    for(int idx=2; idx<N; ++idx){
        diff = gcd_recursive(diff, abs(numbers[idx] - numbers[idx+1]));
    }

    stack<int> stk_M;
    stk_M.push(diff);
    int num;
    for(num=2; num*num<diff; ++num){
        if(diff % num <= 0){
            cout << num << " ";
            stk_M.push(diff / num);
        }
    }
    if(num * num == diff){
        cout << num << " ";
    }
    while(!stk_M.empty()){
        cout << stk_M.top() << " ";
        stk_M.pop();
    }
    cout << endl;
}

void solve_3(){
    int diff = abs(numbers[1] - numbers[2]);
    for(int idx=2; idx<N; ++idx){
        diff = gcd(diff, numbers[idx] - numbers[idx+1]);
    }

    int num;
    for(num=2; num*num<diff; ++num){
        if(diff % num <= 0){
            cout << num << " ";
        }
    }
    if(num * num == diff){
        cout << num << " ";
    }
    while(--num){
        if(diff % num <= 0){
            cout << diff / num << " ";
        }
    }
    cout << endl;
}

void solve(){
    // solve_1();

    // solve_2();

    solve_3();
}

void input(){
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> numbers[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
