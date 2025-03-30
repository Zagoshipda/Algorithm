/*
    https://www.acmicpc.net/problem/14565
    (modular inverses)

    reference
        https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Proof
*/

#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        N = 2...10^12
        a c = a a^-1 = 1 (mod N)
        a (k=1...N-1) = 1 (mod N) except k = 0


    Algorithm
        a^phi(N) = 1 (mod N) if a and N are coprime
            where phi(N) = number of coprimes with N in 1...N

        [Observation] : if gcd(N, A) > 1 then A c != 1 (mod N)
        therefore we now assume gcd(N, A) = 1

        given A, N find c s.t. A c = 1 (mod N)
        <=> A c = N k + 1 for some integer c, k
        <=> find some integer c, k s.t. A c - N k = 1
        <=> WLOG find integer c, k s.t. A c + N k = 1 = gcd(N, A)
        => find c, k using extended Euclidean algorithm

        num_a = quotient * num_b + remainder
        num_a - quotient * num_b = remainder

        formulation
            a = q1 b + r1           r1 = a - q1 b
            b = q2 r1 + r2          r2 = b - q2 r1
            r1 = q3 r2 + r3         r3 = r1 - q3 r2
            r2 = q4 r3 + r4         r4 = r2 - q4 r3
            r3 = q5 r4 + r5         r5 = r3 - q5 r4
            r4 = q6 r5 + r6         r6 = r4 - q6 r5
            ...
                                    rk = rk-2 - qk rk-1


        N = 26, A = 11
        15 3
ex.
12378 3054

// 132 -535 => 6 (= gcd)


26 11

*/

const int ARR_SIZE = 3;

ll N, A;

ll arr_r[ARR_SIZE + 1];
ll arr_s[ARR_SIZE + 1];
ll arr_t[ARR_SIZE + 1];


ll gcd_recursive(ll num_a, ll num_b){
    return num_b ? gcd_recursive(num_b, num_a % num_b) : num_a;
}

ll extended_euclidean_1(ll num_a, ll num_b){
    if(num_b == 1){
        return 1;
    }

    ll num_gcd = gcd_recursive(num_a, num_b);
    if(1 < num_gcd){
        return -1;
    }

    // 1. base case
    arr_r[0] = num_a, arr_r[1] = num_b;
    arr_s[0] = 1, arr_s[1] = 0;
    arr_t[0] = 0, arr_t[1] = 1;

    // 2. recurrence relation (r_k - q_k+1 * r_k+1 = r_k+2)
    while(true){
        ll quotient = arr_r[0] / arr_r[1];
        arr_r[2] = arr_r[0] - quotient * arr_r[1];
        arr_s[2] = arr_s[0] - quotient * arr_s[1];
        arr_t[2] = arr_t[0] - quotient * arr_t[1];
        // std::cout << arr_r[2] << " " << arr_s[2] << " " << arr_t[2] << endl;

        if(arr_r[2] == num_gcd){
            if(arr_t[2] < 0){
                arr_t[2] += num_a;
            }
            return arr_t[2];
        }
        if(arr_r[2] == 0){
            break;
        }

        arr_r[0] = arr_r[1];
        arr_r[1] = arr_r[2];

        arr_s[0] = arr_s[1];
        arr_s[1] = arr_s[2];

        arr_t[0] = arr_t[1];
        arr_t[1] = arr_t[2];
    }

    return -1;
}

ll extended_euclidean_2(ll num_a, ll num_b){

    ll num_gcd = gcd_recursive(num_a, num_b);
    if(1 < num_gcd){
        return -1;
    }

    // 1. base case
    arr_r[0] = num_a, arr_r[1] = num_b;
    arr_s[0] = 1, arr_s[1] = 0;
    arr_t[0] = 0, arr_t[1] = 1;

    // 2. recurrence relation (r_k - q_k+1 * r_k+1 = r_k+2)
    while(true){
        ll quotient = arr_r[0] / arr_r[1];
        arr_r[2] = arr_r[0] - quotient * arr_r[1];
        arr_s[2] = arr_s[0] - quotient * arr_s[1];
        arr_t[2] = arr_t[0] - quotient * arr_t[1];
        // std::cout << arr_r[2] << " " << arr_s[2] << " " << arr_t[2] << endl;

        if(arr_r[2] == 0){
            if(arr_t[1] < 0){
                arr_t[1] += num_a;
            }
            return arr_t[1];
        }

        // update loop invariant
        arr_r[0] = arr_r[1];
        arr_r[1] = arr_r[2];

        arr_s[0] = arr_s[1];
        arr_s[1] = arr_s[2];

        arr_t[0] = arr_t[1];
        arr_t[1] = arr_t[2];
    }

    return -1;
}

void solve_1(){
    ll inverse_plus = N - A;
    ll inverse_multiple = extended_euclidean_2(N, A);

    std::cout << inverse_plus << " " << inverse_multiple << endl;
}

void solve(){
    solve_1();
}

void input(){
    std::cin >> N >> A;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
