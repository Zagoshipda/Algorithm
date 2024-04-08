/*
    https://www.acmicpc.net/problem/18891
    (pick the shits)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Simulation
        (50 % proportional)
        total votes = 24'430'476
        total proportional = 22'732'332

        N = 300 = 253 + 47 = (242 + 11) + 47(= 30 + 17)
        R = 11
        N - R = 289
        (N - R) * p - r
                      289       - 242   = [47]
        1 : 289 * p = 104.0689  - 105   = 0         /2 = 0
        2 : 289 * p = 79.3594   - 110   = 0         /2 = 0
        3 : 289 * p = 83.0875   - 25    = 58.0875   /2 = 29.04375
                                                        ~ 29 / 39 * 30 = 22.307 ~ 22
        4 : 289 * p = 22.4842   - 2     = 20.4842   /2 = 10.2421
                                                        ~ 10 / 39 * 30 = 7.692 ~ 7 + 1 = 8

        difference / 2 < 30 ?
        diff / 2 < 30 - 4 < 30 ?
        diff / 2 = 24
        14 => 28 = x - 25 => x = 53
        10 => ...

        ex.
        (300-x) - (253-x) = 47 => 30
        100 - 100   = 0
        100 - 80    = 20 /2 = 10    ~ 10
        100 - 73    = 27 /2 = 13.5  ~ 14
        30 - 24 = 6

        2 10
        hello 5 5
        world 5 5
        => 253 = 243 + 10 = (47 + 10 =) 57 * 1/2 - 5 = 28.5 - 5 = 23.5 / 2 = 11.75 ~ 12
        proportional_seats 24 / 30
        hello 29 = 5 + (12 + 3) + 9 (~8.5) = 29
        world 28 = 5 + (12 + 3) + 8 (~8.5) = 28


        4 310
        a 100 100   : 100/306 ~ 0.326 (O) 1/3 * 278 ~ 92.66 - 100 = 0
                                            (X) 0.326 * 3 = 0.980 ~ 0 + 1
                                        (O) 1/3 * 3 = 1
                                            (X) 0.326 * 17 = 5.555 ~ 5 + 1
                                        (O) 1/3 * 17 = 5.666 ~ 5 + 1 = 6
                                        => 7
        b 80 100    : 100/306 ~ 0.326 (O) 1/3 * 278 ~ 92.66 - 80 = 12.66 /2 ~ 6.33 ~ 6
                                        1/3 * 3 = 1
                                        1/3 * 17 = 5.666 ~ 5 + 1 = 6
                                        => 13
        c 50 100    : 100/306 ~ 0.326 (O) 1/3 * 278 ~ 92.66 - 50 = 42.66 /2 ~ 21.33 ~ 21
                                        1/3 * 3 = 1
                                        1/3 * 17 = 5.666 ~ 5
                                        => 27
        d 1 6       : 6/306   ~ 0.019 (X) * 278 ~ 5.450 - 1 = 4.45 /2 ~ 2.225 ~ 2

        total (231, 306)

        27 < 30, 3 left

        a 100   + 7     = 107
        b 80    + 13    = 93
        c 50    + 27    = 77
        d 1     + 0     = 1



4 310
a 100 100
b 80 100
c 50 100
d 1 6

// a 107         105 (X)
// b 93(O) 92(X)
// c 77(O) 76(X) 79 (X)
// d 1(O)  3(X)

306 valid, 4 invalid
253 = 231 + 22(= R)
300 - 22 = 278

        4 310
        a 90 100    : 100/306 ~ 0.326 (O) 1/3 * 268 ~ 89.333 - 90 = 0
                                            1/3 * 5 = 1.666 ~ 1 + 1
                                            1/3 * 17 ~ 5.66 ~ 5 + 1
                                            => 8
        b 80 100    : 100/306 ~ 0.326 (O) 1/3 * 268 ~ 89.333 - 80 = 9.33 /2 ~ 4.665 = 5
                                            1/3 * 5 = 1.666 ~ 1 + 1
                                            1/3 * 17 ~ 5.66 ~ 5 + 1
                                            => 13
        c 50 100    : 100/306 ~ 0.326 (O) 1/3 * 268 ~ 89.333 - 50 = 39.33 /2 ~ 19.665 = 20
                                            1/3 * 5 = 1.666 ~ 1
                                            1/3 * 17 ~ 5.66 ~ 5
                                            => 26
        d 1 6       : 6/306 ~ 0.019 (X)

        25 < 30, 5 left

4 310
a 90 100
b 80 100
c 50 100
d 1 6

306 valid, 4 invalid
253 = 221 + 32(= R)
300 - 32 = 268
a 90 + 8
b 80 + 13 (O) / 12 (X)
c 50 + 26 (O) / 27 (X)
d 1

            4 310
            a 110 100   : 100/306 ~ 0.326 (O) 1/3 * 298 ~ 99.333 - 110 = 0
                                                1/3 * 17 ~ 5.66 = 5 + 1
                                                => 6
            b 80 100    : 100/306 ~ 0.326 (O) 1/3 * 298 ~ 99.333 - 80 = 19.33 /2 = 9.665 ~ 10
                                                1/3 * 17 ~ 5.66 = 5 + 1
                                                => 16
            c 60 100    : 100/306 ~ 0.326 (O) 1/3 * 298 ~ 99.333 - 60 = 39.33 /2 = 19.665 ~ 20
                                                1/3 * 17 ~ 5.66 = 5
                                                => 25
            d 1 6       : 6/306 ~ 0.019 (X)

            30 = 30, 0 left
4 310
a 110 100
b 80 100
c 60 100
d 1 6

// a 116
// b 96 / (X) 86 (+6)
// c 85 / (X) 65 (+5)
// d 1

306 valid, 4 invalid
253 = 251 + 2(= R)
300 - 2 = 298


        4 310
        a 100 100   : 100/306 ~ 0.326 (O) 1/3 * 298 ~ 99.333 -100 = 0
                                            1/3 * 5 ~ 1.6 = 1 + 1
                                            1/3 * 17 ~ 5.6 = 5 + 1
                                            => 8
        b 100 100   : 100/306 ~ 0.326 (O) 1/3 * 298 ~ 99.333 -100 = 0
                                            1/3 * 5 ~ 1.6 = 1 + 1
                                            1/3 * 17 ~ 5.6 = 5 + 1
                                            => 8
        c 50 100    : 100/306 ~ 0.326 (O) 1/3 * 298 ~ 99.333 -50 = 49.3/2 ~ 24.65 ~ 25
                                            1/3 * 5 ~ 1.6 = 1
                                            1/3 * 17 ~ 5.6 = 5
                                            => 31
        d 1 6       : 6/306 ~ 0.019 (X)
        306 valid, 4 invalid
        253 = 251 + 2(= R)

4 310
a 100 100
b 100 100
c 50 100
d 1 6
// 25/30
// a 108
// b 108 / 107 (X)
// c 81  / 82 (X)
// d 1


4 310
a 100 100
_ 100 100
___ 50 100
d 1 6

// _ 108 (+8)   / 107
// a 108 (+8)   / 108
// ___ 81 (+31) / 82
// d 1


4 310
a 20 1000000
b 10 1000000
c 5 1000000
d 1 600000
// 24/30


4 310
a 100 1000000
b 10 1000000
c 5 1000000
d 1 600000
// 51/30

4 310
a 40 1000000
b 10 1000000
c 5 1000000
d 1 600000
// 29/30

4 310
a 43 1000000
b 10 1000000
c 5 1000000
d 1 600000
// 30/30

5 310
a 43 1000000
b 10 1000000
c 5 1000000
d 1 600000
e 1 10
// 30/30

5 310
a 0 10
b 0 10
c 0 10
d 0 6
e 0 10

// 23/30
// a 11 = 10.21/2 ~ 5 + 1.52 ~ 5+1+1 = 7 + 3.69 ~ 7+3+1 ~ 11
// b 11 = 10.21/2 ~ 5 + 1.52 ~ 5+1+1 = 7 + 3.69 ~ 7+3+1 ~ 11
// c 10 = 10.21/2 ~ 5 + 1.52 ~ 5+1   = 6 + 3.69 ~ 6+3+1 ~ 10
// e 9  = 6.130/2 ~ 3 + 0.91 ~ 3+0+1 = 4 + 2.21 ~ 4+2   ~ 6
// d 6  = 10.21/2 ~ 5 + 1.52 ~ 5+1   = 6 + 3.69 ~ 6+3   ~ 9


2 1000000000
a 0 1000000000
b 253 0
// 150/30
// b 253
// a 47

2 1000000000
a 0 500000000
b 253 500000000
// 75/30
// b 261
// a 39

2 1000000000
a 100 500000000
b 150 500000000
// 24/30
// b 161
// a 136

3 1000000000
a 100 300000000
b 100 300000000
c 50 300000000
// 25/30
// a 108
// b 108
// c 81

3 1000000000
a 1 3
b 1 3
c 5 3
// 25/30
// a 18
// b 18
// c 18

4 1000000000
a 1 3
b 1 3
c 5 10000000
d 200 10000000
// 61/30
// d 208
// c 44
// a 1
// b 1


3 1000000000
a 100 300000000
b 100 300000000
c 50 300000000

*/

const int NUM_PARTY = 50;
const int MAX_VOTERS = 1'000'000'000;   // 10^9
const int NUM_SHITS = 300;
const int NUM_LOCAL_SHITS = 253;
const int NUM_PROPORTIONAL_SHITS = 47;
const int NUM_PROPORTIONAL_1 = 30;
const int NUM_PROPORTIONAL_2 = 17;

const int QUALIFYING_LOCAL = 5;
const int QUALIFYING_PROPORTIONAL = 3;

int P, V;
string name;
int local, proportional;
string parties_name[NUM_PARTY + 1];
pair<int, int> parties[NUM_PARTY + 2];  // (local, proportional)
int R;
int sum_local;
int sum_proportional;
bool is_qualified[NUM_PARTY + 1];
int sum_qualified_proportional;
int linked_votes[NUM_PARTY + 1];

struct cmp_party_1{
    bool operator()(const pair<double, int>& party_1, const pair<double, int>& party_2){
        if(party_1.first == party_2.first){
            return party_1.second > party_2.second;
        }
        else{
            return party_1.first < party_2.first;
        }
    }
};

struct cmp_party_2{
    bool operator()(const pair<int, string>& party_1, const pair<int, string>& party_2){
        if(party_1.first == party_2.first){
            return party_1.second > party_2.second;
        }
        else{
            return party_1.first < party_2.first;
        }
    }
};

void solve(){
    // step 0 determine the precondition
    double ratio;
    for(int idx=1; idx<=P; ++idx){
        ratio = (parties[idx].second / (double) sum_proportional) * 100;
        if(parties[idx].first >= QUALIFYING_LOCAL || ratio >= 3){
            is_qualified[idx] = true;
            sum_local += parties[idx].first;
            sum_qualified_proportional += parties[idx].second;
        }
    }
    R = NUM_LOCAL_SHITS - sum_local;
    // parties[P+1] = {R, 0};   // for independent shits

    // step 1
    int proportional_seats = 0;
    for(int idx=1; idx<=P; ++idx){
        if(is_qualified[idx]){
            ratio = (parties[idx].second / (double) sum_qualified_proportional);
            double val = ((NUM_SHITS - R) * ratio - parties[idx].first) / 2;
            if(val < 1){
                linked_votes[idx] = 0;
            }
            else{
                val = round(val);
                linked_votes[idx] = val;
                proportional_seats += val;
            }
        }
    }
    // cout << proportional_seats << endl;
    // step 2-1
    // priority_queue<pair<double, int>, vector<pair<double, int> >, less<pair<double, int>> > pq_max_2;    // (decimal, index)
    priority_queue<pair<double, int>, vector<pair<double, int> >, cmp_party_1> pq_max_2;    // (decimal, index)

    double integral, decimal;
    int residual, distributed;
    if(proportional_seats < NUM_PROPORTIONAL_1){
        residual = NUM_PROPORTIONAL_1 - proportional_seats;
        distributed = 0;

        for(int idx=1; idx<=P; ++idx){
            if(is_qualified[idx]){
                // ratio = (parties[idx].second / (double) sum_proportional);
                ratio = (parties[idx].second / (double) sum_qualified_proportional);
                // decimal = modf(ratio, &integral);
                // decimal = modf(ratio * residual, &integral);
                decimal = modf(linked_votes[idx] + ratio * residual, &integral);

                // pq_max_2.push({decimal, -idx});
                pq_max_2.push({decimal, idx});

                // linked_votes[idx] += integral;
                linked_votes[idx] = integral;
                distributed += integral;
            }
        }
        // assert(distributed <= residual);
        assert(distributed <= NUM_PROPORTIONAL_1);

        // while(distributed < residual){
        while(distributed < NUM_PROPORTIONAL_1){
            auto [val, index] = pq_max_2.top();
            pq_max_2.pop();

            // linked_votes[-index] += 1;
            linked_votes[index] += 1;
            ++distributed;
        }
    }

    // step 2-2
    else if(proportional_seats > NUM_PROPORTIONAL_1){
        residual = NUM_PROPORTIONAL_1;
        distributed = 0;

        for(int idx=1; idx<=P; ++idx){
            if(is_qualified[idx] && linked_votes[idx] > 0){
                // ratio = (linked_votes[idx] / (double) proportional_seats);
                // decimal = modf(ratio * residual, &integral);
                decimal = modf(residual * linked_votes[idx] / (double) proportional_seats, &integral);
                // pq_max_2.push({decimal, -idx});
                pq_max_2.push({decimal, idx});

                linked_votes[idx] = integral;
                distributed += integral;
            }
        }
        assert(distributed <= residual);

        while(distributed < residual){
            auto [val, index] = pq_max_2.top();
            pq_max_2.pop();

            // linked_votes[-index] += 1;
            linked_votes[index] += 1;
            ++distributed;
        }
    }

    // step 3
    // priority_queue<pair<double, int>, vector<pair<double, int> >, less<pair<double, int>> > pq_max_3;
    priority_queue<pair<double, int>, vector<pair<double, int> >, cmp_party_1 > pq_max_3;
    residual = NUM_PROPORTIONAL_2;
    distributed = 0;
    for(int idx=1; idx<=P; ++idx){
        if(is_qualified[idx]){  // NOTE : the last error fixed (...)
            // ratio = (parties[idx].second / (double) sum_proportional);  // WRONG, but passed
            ratio = (parties[idx].second / (double) sum_qualified_proportional);
            decimal = modf(ratio * residual, &integral);
            // pq_max_3.push({decimal, -idx});
            pq_max_3.push({decimal, idx});

            linked_votes[idx] += integral;
            distributed += integral;
        }
    }
    assert(distributed <= residual);

    while(distributed < residual){
        auto [val, index] = pq_max_3.top();
        pq_max_3.pop();

        // linked_votes[-index] += 1;
        linked_votes[index] += 1;
        ++distributed;
    }
    assert(distributed == NUM_PROPORTIONAL_2);

    // step 4 total votes & output
    priority_queue<pair<int, string>, vector<pair<int, string> >, cmp_party_2> pq_max_4;    // (votes, index)
    for(int idx=1; idx<=P; ++idx){
        pq_max_4.push({linked_votes[idx] + parties[idx].first, parties_name[idx]});
    }

    while(!pq_max_4.empty()){
        auto [seats, name] = pq_max_4.top();
        cout << name << " " << seats << endl;
        pq_max_4.pop();
    }
}

void input(){
    cin >> P >> V;
    for(int i=1; i<=P; ++i){
        cin >> name >> local >> proportional;
        parties_name[i] = name;
        parties[i] = {local, proportional};
        // sum_local += local;
        sum_proportional += proportional;
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
