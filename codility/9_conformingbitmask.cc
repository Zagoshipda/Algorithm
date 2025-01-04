/*
    https://app.codility.com/programmers/trainings/9/count_conforming_bitmasks/
    (CountConformingBitmasks)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        In this problem we consider unsigned 30-bit integers, i.e. all integers B such that 0 ≤ B < 230.

        We say that integer A conforms to integer B if, in all positions where B has bits set to 1, A has corresponding bits set to 1.

        For example:
            00 0000 1111 0111 1101 1110 0000 1111(BIN) = 16,244,239 conforms to
            00 0000 1100 0110 1101 1110 0000 0001(BIN) = 13,032,961, but
            11 0000 1101 0111 0000 1010 0000 0101(BIN) = 819,399,173 does not conform to
            00 0000 1001 0110 0011 0011 0000 1111(BIN) = 9,843,471.

        Write a function:
            class Solution { public int solution(int A, int B, int C); }

        that, given three unsigned 30-bit integers A, B and C, returns the number of unsigned 30-bit integers conforming to at least one of the given integers.

        For example, for integers:
            A = 11 1111 1111 1111 1111 1111 1001 1111(BIN) = 1,073,741,727,
            B = 11 1111 1111 1111 1111 1111 0011 1111(BIN) = 1,073,741,631, and
            C = 11 1111 1111 1111 1111 1111 0110 1111(BIN) = 1,073,741,679,

        the function should return 8, since there are 8 unsigned 30-bit integers conforming to A, B or C, namely:
            11 1111 1111 1111 1111 1111 0011 1111(BIN) = 1,073,741,631,
            11 1111 1111 1111 1111 1111 0110 1111(BIN) = 1,073,741,679,
            11 1111 1111 1111 1111 1111 0111 1111(BIN) = 1,073,741,695,
            11 1111 1111 1111 1111 1111 1001 1111(BIN) = 1,073,741,727,
            11 1111 1111 1111 1111 1111 1011 1111(BIN) = 1,073,741,759,
            11 1111 1111 1111 1111 1111 1101 1111(BIN) = 1,073,741,791,
            11 1111 1111 1111 1111 1111 1110 1111(BIN) = 1,073,741,807,
            11 1111 1111 1111 1111 1111 1111 1111(BIN) = 1,073,741,823.

        Write an efficient algorithm for the following assumptions:
            - A, B and C are integers within the range [0..1,073,741,823].

    Algorithm
        2^30 ~ 10^9 = 1'073'741'823
        A conform to B : A >= B

        inclusion - exclusion ?
            => only need to consider bit positions

        just use set to handle duplicates ?
            => might be hard to calculate the exact value
*/

const int MAX_BIT = 30;
const int MAX_NUM = (1 << 30) - 1;  // 1'073'741'823 ~ 10^9

long long cnt_A;
long long cnt_B;
long long cnt_C;
long long cnt_AB;
long long cnt_AC;
long long cnt_BC;
long long cnt_ABC;

long long count_bits(int num){
    int bits = 0;
    while(num){
        if(num & 1){
            ++bits;
        }
        num >>= 1;
    }

    return 1 << (30 - bits);
}

int solution(int A, int B, int C) {
    // Implement your solution here

    cnt_A = count_bits(A);
    cnt_B = count_bits(B);
    cnt_C = count_bits(C);
    cnt_AB = count_bits(A | B);
    cnt_AC = count_bits(A | C);
    cnt_BC = count_bits(B | C);
    cnt_ABC = count_bits(A | B | C);

    // inclusion - exclusion
    return (cnt_A + cnt_B + cnt_C) - (cnt_AB + cnt_AC + cnt_BC) + cnt_ABC;
}

void solve(){
    cout << (1 << 30) - 1 << endl;
}

void input(){

}

void debug(){

}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    // debug();

    input();

    solve();

    return 0;
}
