/*
    https://www.acmicpc.net/problem/1344
    (soccer)

    solution
        probability
            https://www.acmicpc.net/source/49540223
            (nukec, 108 ms) : implemented in solve_1()
            https://www.acmicpc.net/source/17371668
            (usj0119, 4 ms)
            https://www.acmicpc.net/source/2803068
            (ntopia, 0 ms)

        DP
            implemented in solve_dp_bottom_up()
                https://www.acmicpc.net/source/70697149
                (leekh100000, 0 ms)
                https://www.acmicpc.net/source/65408272
                (lighter, 40 ms) : one 3-dim array[][][]

            top-down DP = recursion + memoization, implemented in solve_dp_top_down()
                https://www.acmicpc.net/source/52187414
                (iyh0413, 148 ms)
                https://www.acmicpc.net/source/79118061
                (lcm2822, 20 ms)
                https://www.acmicpc.net/source/6939714
                (khj94811, 8 ms)

        https://www.acmicpc.net/source/16075377
        (kdh9949, 4 ms) : recursive

        brute force all choices 2^18 = 262144 ~ O(10^6)
            https://www.acmicpc.net/source/8501791
            (sebinkim, 40 ms) : bitmasking, implemented in solve_brute_force()
            https://www.acmicpc.net/source/44936283
            (iptt, 20 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        - at most 1 goal per each interval

    Algorithm
        5 5 ... 5 5 : 90/5 = 18 = N intervals
        primes <= 18 : 7
            2 3 5 7 11 13 17
        composites : 12
            0 1 4 6 8 9 10 12 14 15 16 18

        at least one team scores prime
        = 1 - all two teams score (not prime / composite)

        if N = 2, p
            p 1-p
            1-p p

        if N = 18
            (a,b)
            (0,0) (0,1) ... (0,18)
            (1,0) (1,1) ... (1,18)
            ...
            (18,0)(18,1)... (18,18)

        formula
            (x+y)^n = sum(comb(n, k) * x^k * y^n-k) for k=0...n
            (p + (1-p))^n = sum(comb(n, k) * p^k * (1-p)^n-k) for k=0...n

        only for combinations, without probability
            sum(nCk) = 2^n, 2^18 = 262144
            S = 18C0 + 18C1 + .... + 18C18
            = 2^18 - (18C2 + ... + 18C17)
            = 180373 ~ O(10^5)
            S^2 = 32'534'419'129 ~ O(3 * 10^10)

*/

const int MAX_PRECISION = 9;
const int NUM_PRIME = 7;
const int NUM_INTERVAL = 18;

double A, B;
int primes[] = {2, 3, 5, 7, 11, 13, 17};

void solve_1(){
    double prob_A = 0;
    double prob_B = 0;
    for(int idx=0; idx<NUM_PRIME; ++idx){
        int max_choice = primes[idx];
        double comb_1 = 1;
        double comb_2 = 1;

        // probability of p
        int ith = 1;
        for( ; ith<=max_choice; ++ith){
            comb_1 *= A;
            comb_2 *= B;
        }
        // probability of NOT p = 1-p
        for( ; ith<=NUM_INTERVAL; ++ith){
            comb_1 *= (1-A);
            comb_2 *= (1-B);
        }

        // # of choices
        if(max_choice * 2 > NUM_INTERVAL){
            max_choice = NUM_INTERVAL - max_choice;
        }
        for(int choice=1; choice<=max_choice; ++choice){
            comb_1 *= (NUM_INTERVAL - choice + 1);
            comb_1 /= choice;

            comb_2 *= (NUM_INTERVAL - choice + 1);
            comb_2 /= choice;
        }

        // accumulate
        prob_A += comb_1;
        prob_B += comb_2;
    }

    cout << setprecision(MAX_PRECISION) << 1 - (1-prob_A) * (1-prob_B) << endl;
}

/*
    DP
    S ubproblem
        prefix
        dp[i][k] : probability of score k=0...18<=i for interval[:i=1...18]
    R ecurrence relation
        2 choices : score at interval[i] or not
        dp[i][k] = dp[i-1][k-1] * p + dp[i-1][k] * (1-p)
    T opological order
        for i=1...18
            for k=0...i
    B ase case
        dp[0][0] = 1 : always score 0 from the beginning
        dp[0][1] = 0 : NO way to score at the beginning
    O riginal problem
        1 - (1-dp_A[18][composites]) * (1-dp_B[18][composites])
    T ime complexity
        # of subproblem : O(10^3)
        operations per subproblem : O(1)
        operations for the original problem : O(1)
        total : O(10^3)
*/

double dp_A[NUM_INTERVAL + 1][NUM_INTERVAL + 1];
double dp_B[NUM_INTERVAL + 1][NUM_INTERVAL + 1];
void solve_dp_bottom_up(){
    dp_A[0][0] = 1;
    dp_B[0][0] = 1;
    for(int idx=1; idx<=NUM_INTERVAL; ++idx){
        for(int goals=0; goals<=idx; ++goals){
            dp_A[idx][goals] = dp_A[idx-1][goals-1] * A + dp_A[idx-1][goals] * (1-A);
            dp_B[idx][goals] = dp_B[idx-1][goals-1] * B + dp_B[idx-1][goals] * (1-B);
        }
    }

    double prob_A = 0;
    double prob_B = 0;
    for(int idx=0; idx<NUM_PRIME; ++idx){
        prob_A += dp_A[NUM_INTERVAL][primes[idx]];
        prob_B += dp_B[NUM_INTERVAL][primes[idx]];
    }
    cout << setprecision(MAX_PRECISION) << 1 - (1-prob_A) * (1-prob_B) << endl;
}

double dp[2][NUM_INTERVAL + 1][NUM_INTERVAL + 1];
double recursion(int nth, int score, int prob){
    if(nth < score){
        return 0;
    }

    if(nth <= 0){
        // if(score){
        //     return 0;
        // }
        // else{
        //     return 1;
        // }
        return score == 0;
    }

    if(dp[prob][nth][score]){
        return dp[prob][nth][score];
    }

    return dp[prob][nth][score] = (
        recursion(nth-1, score-1, prob) * (A*(1-prob) + B*prob) +
        recursion(nth-1, score, prob) * (1 - A*(1-prob) - B*prob)
    );
}

void solve_dp_top_down(){
    double prob_A = 0;
    double prob_B = 0;
    for(int idx=0; idx<NUM_PRIME; ++idx){
        prob_A += recursion(NUM_INTERVAL, primes[idx], 0);
        prob_B += recursion(NUM_INTERVAL, primes[idx], 1);
    }
    cout << setprecision(MAX_PRECISION) << 1 - (1-prob_A) * (1-prob_B) << endl;
}

bool is_prime(int num){
    for(int idx=0; idx<NUM_PRIME; ++idx){
        if(num == primes[idx]){
            return true;
        }
    }
    return false;
}

void solve_brute_force(){
    int max_state = 1 << NUM_INTERVAL;
    double prob_A = 0;
    double prob_B = 0;
    for(int state=0; state<max_state; ++state){
        double val_A = 1;
        double val_B = 1;
        int cnt = 0;
        for(int bit=0; bit<NUM_INTERVAL; ++bit){
            if((state >> bit) & 1){
                val_A *= A;
                val_B *= B;
                ++cnt;
            }
            else{
                val_A *= (1-A);
                val_B *= (1-B);
            }
        }
        // if(is_prime(cnt)){
        //     prob_A += val_A;
        //     prob_B += val_B;
        // }
        if(!is_prime(cnt)){
            prob_A += val_A;
            prob_B += val_B;
        }
    }
    // cout << setprecision(MAX_PRECISION) << 1 - (1-prob_A) * (1-prob_B) << endl;
    cout << setprecision(MAX_PRECISION) << 1 - prob_A * prob_B << endl;
}

void solve(){
    // solve_1();  // 0 ms

    // solve_dp_bottom_up();   // 0 ms
    // solve_dp_top_down();    // 16 ms

    solve_brute_force();    // 20 ms
}

void input(){
    cin >> A >> B;

    // take as a probability
    A /= 100;
    B /= 100;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
