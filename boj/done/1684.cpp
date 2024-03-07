/*
    https://www.acmicpc.net/problem/1684
    (same remainder)

    similar problem
        https://www.acmicpc.net/problem/2981
        (granica)
        https://www.acmicpc.net/problem/17433
        (mysterious number)

    solutions
        https://www.acmicpc.net/source/17484684
        (pichulia, 0 ms) : custom function gcd()

        https://www.acmicpc.net/source/132070
        (WeissBlume, 0 ms) : implemented in solve_4()

        http://disq.us/t/3rw707y

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        find the largest divider D s.t. remainder R is the same for all numbers

    Algorithm
        solve_2() brute force : try all possible divisors, take the maximum
        (sort all numbers in ascending order)
            (WRONG) take the number with the smallest absolute value
                    predict the remainder = smallest number, ... 2, 1
        (AC) take the number with the largest absolute value
            divisor can be within the range [1, max_abs]
            (X) predict the remainder = largest number, ... 2, 1
            (O) predict the divisor = largest number, ... 2, 1
        start from the possible largest number since finding the largest D
        divide all numbers by the divisor and check whether the remainder is the same
        return the current divisor as D

        Time complexity : iterate through n numbers, check remainders with divisor
            maximum absolute val = O(10^6)
            number of integers n = O(10^3)
            total time complexity = O(10^9)

        solve_3() calculate GCD among differences between numbers
        sort all numbers and calculate GCD among n-1 differences
        2-1. take GCD(num[i+1] - num[i]) for i=1...n-1
        2-2. take GCD(num[i] - num[1]) for i=2...n


input / output

3
8 -4 -6

// 2

2
-1000000 -1000

// 999000

3
-2 2 1000000

// 2

4
22 36 48 72

// 2

2
1 3

// 2

4
3 1 25 21

// 2

4
9 1 13 -7

// 4

*/

const int NUM = 1'000;
int T;  // for debugging
int n;
int numbers[NUM + 1];
int min_number = INT_MAX;   // WRONG
int max_number = 0;         // AC
int max_div;


void solve_wrong(){
    sort(numbers+1, numbers+1+n, less<int>());
    int pos = lower_bound(numbers+1, numbers+1+n, 0) - numbers+1;

    for(int sub=abs(numbers[pos]); sub>=1; --sub){
        int num = numbers[pos] - sub;
        // cout << "   num" << num << endl;
        bool divisible = true;
        for(int idx=1; idx<=n; ++idx){

            // cout << numbers[idx] - sub << endl;
            if(((numbers[idx] - sub) % num + num) % num){
                divisible = false;
                break;
            }
        }

        if(divisible){
            max_div = max(max_div, num);
        }
    }

    cout << max_div << endl;
}


void solve_2(){
    // sort(numbers+1, numbers+1+n, less<int>());

    // for(int div=abs(min_number); div>=1; --div){
    for(int div=abs(max_number); div>=1; --div){
        // int remainder = (min_number % div + div) % div;
        int remainder = (max_number % div + div) % div;
        bool is_equal = true;
        for(int idx=1; idx<=n; ++idx){
            if((numbers[idx] % div + div) % div != remainder){
                is_equal = false;
                break;
            }
        }
        if(is_equal){
            cout << div << endl;
            break;
        }
    }
}

int gcd_recursive(int num_1, int num_2){
    if(num_1 < 0){
        num_1 = -num_1;
    }
    if(num_2 < 0){
        num_2 = -num_2;
    }

    if(num_2 <= 0){
        return num_1;
    }

    return gcd_recursive(num_2, num_1 % num_2);
}

int gcd_iterative(int num_1, int num_2){
    if(num_1 < 0){
        num_1 = -num_1;
    }
    if(num_2 < 0){
        num_2 = -num_2;
    }

    if(num_1 < num_2){
        swap(num_1, num_2);
    }

    int remainder;
    while(num_2 > 0){
        remainder = num_1 % num_2;
        num_1 = num_2;
        num_2 = remainder;
    }

    return num_1;
}

void solve_3(){
    // sort(numbers+1, numbers+1+n, less<int>());
    // int diff = numbers[2] - numbers[1];
    int diff = 0;
    // for(int idx=2; idx<n; ++idx){
    for(int idx=1; idx<n; ++idx){
        diff = gcd(diff, numbers[idx+1] - numbers[idx]);
        // diff = gcd_recursive(diff, numbers[idx+1] - numbers[idx]);
        // diff = gcd_iterative(diff, numbers[idx+1] - numbers[idx]);
    }
    cout << diff << endl;
}

void solve_4(){
    int diff = 0;
    for(int idx=1; idx<=n; ++idx){
        diff = gcd_iterative(diff, numbers[idx] - min_number);
    }
    cout << diff << endl;
}


ofstream fout;
void solve_file(){
    // sort(numbers+1, numbers+1+n, less<int>());
    for(int div=abs(min_number); div>=1; --div){
        int remainder = (min_number % div + div) % div;
        bool is_equal = true;
        for(int idx=1; idx<=n; ++idx){
            if((numbers[idx] % div + div) % div != remainder){
                is_equal = false;
                break;
            }
        }
        if(is_equal){
            // cout << div << endl;
            fout << div << " ";
            break;
        }
    }
}


void solve(){
    // cout << gcd(3, -3) << endl;             // 3
    // cout << gcd(-3, 3) << endl;             // 3
    // cout << gcd(-3, -3) << endl;            // 3
    // cout << gcd_recursive(3, -3) << endl;   // 3
    // cout << gcd_recursive(-3, 3) << endl;   // 3
    // cout << gcd_recursive(-3, -3) << endl;  // -3

    // solve_2();
    // solve_3();
    solve_4();

    // solve_file();
}

ifstream fin;
void file_input(){
    fin.open("./1684.in");
    fout.open("./1684.out");
    fin >> T;
    while(T--){
        fin >> n;
        min_number = INT_MAX;
        for(int i=1; i<=n; ++i){
            fin >> numbers[i];
            if(numbers[i] == 0){
                continue;
            }
            if(abs(numbers[i]) < min_number){
                min_number = numbers[i];
            }
        }
        solve();
    }
    fout << endl;
    fin.close();
    fout.close();
}

void input(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> numbers[i];
        // if(numbers[i] == 0){
        //     continue;
        // }
        // if(abs(numbers[i]) < min_number){   // WRONG
        //     min_number = numbers[i];
        // }
        if(max_number < abs(numbers[i])){
            max_number = numbers[i];
        }
        if(numbers[i] < min_number){
            min_number = numbers[i];
        }
    }
}

int main(){
    IOS;

    input();
    solve();

    // file_input();

    return 0;
}
