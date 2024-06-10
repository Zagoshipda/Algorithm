/*
    https://www.acmicpc.net/problem/25671
    (bracket and bar sequences)

    similar problem
        https://www.acmicpc.net/problem/1722
        (permutation order)
        https://www.acmicpc.net/problem/2248
        (finding binary) : recursive approach

    solution
        https://www.acmicpc.net/source/49708179
        (sait2000, 1084 ms)

    reference
        Ivan Kazmenko Contest 3
        https://ucup.ac/files/ucup/tutorials/tutorials-2-16.pdf
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        - encodes bracket-and-bar sequences as integers
        - # of triples n <= 25
        - 3n <= 75 character bracket-and-bar sequence
        - encode <= 2 * 10^18
        operations
        - (op1) concatenation : AB
        - (op2) inclusion : ( A | B )

    Algorithm
        count # of triples for n ~ 25 and just print its number ?
        both by op1 & op2, length increases by 3

        triple=1, len=3
            (|)
        triple=2, len=6
            123456 123456 123456
            (|)(|) ((|)|) (|(|))
        pos  2  5    3 5   2 4
        => encode / decode based on the position of bars ?

        DP
        S ubproblem
            (observation) sequence must start with the opening bracket '('
                ( A | B ) C : total n triples
                (op1) concatenation C
                (op2) inclusion A, B
                1 triple corresponding the first opening bracket, n-1 triples left
                => recurse
                A : u triples
                B : v triples
                C : n-1 -u -v triples (fully determined by A, B)
            dp[k] : # of triples of k triples (length 3k)
        R ecurrence relation
            dp[k] : dp[A] * dp[B] * dp[C] for '|' and ')' position corresponding the first '('
        T opological order
        B ase case
        O riginal problem
        T ime complexity


I / O

encode
4
25
(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)((|(|))((|)|)(|(|))(|)(|)(|)|)
1
(|)
4
((((|)|)|)|)
5
(|(|))((|(|))|)

// 1231234
// 0
// 54
// 65



decode
4
25
1231234
1
0
4
54
5
65

// (|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)(|)((|(|))((|)|)(|(|))(|)(|)(|)|)
// (|)
// ((((|)|)|)|)
// (|(|))((|(|))|)

*/

const int TRIPLE_SIZE = 3;
const int MAX_TRIPLES = 25;

string ENCODE = "encode";
string DECODE = "decode";
enum TYPES{
    opening_bracket = 1,
    bar = 2,
    closing_bracket = 3,
};
char characters[TRIPLE_SIZE + 1] = { ' ', '(', '|', ')' };

string type;
int t;
int n;
string sequence;
ll integer;

ll dp[MAX_TRIPLES + 1];
/*
1
1 3 12 55 273
1428 7752 43263 246675 1430715
8414640 50067108 300830572 1822766520 11124755664
68328754959 422030545335 2619631042665 16332922290300 102240109897695
642312451217745 4048514844039120 25594403741131680 162250238001816900 1031147983159782228

24 : 162'250'238'001'816'900 ~ O(10^17)
25 : 1'031'147'983'159'782'228 ~ O(10^18) ~ long long
*/
void validate(){
    for(int idx=0; idx<=MAX_TRIPLES; ++idx){
        cout << dp[idx] << " ";
    }
    cout << endl;
}

void initialize(){
    dp[0] = 1;
    for(int triple=1; triple<=MAX_TRIPLES; ++triple){
        for(int idx=0; idx<triple; ++idx){
            for(int jdx=0; jdx<triple-idx; ++jdx){
                dp[triple] += dp[idx] * dp[jdx] * dp[triple-1-idx-jdx];
            }
        }
    }
}

// encode(k, l, r) : encode sequence[l...r] with k triples
ll encode(int triples, int left, int right){
    // if(left > right){
    if(triples <= 0){
        return 0;
    }

    int pos_1 = left;
    int pos_2 = -1;
    int pos_3 = -1;
    bool is_bar = false;
    for(int pos=left, cnt=0; pos<=right; ++pos){
        if(sequence[pos] == characters[opening_bracket]){
            ++cnt;
        }
        else if(!is_bar && cnt == 1 && sequence[pos] == characters[bar]){
            pos_2 = pos;
            is_bar = true;
        }
        else if(sequence[pos] == characters[closing_bracket]){
            --cnt;
            if(cnt == 0){
                pos_3 = pos;
                break;
            }
        }
    }

    int target_1 = (pos_2 - pos_1) / TRIPLE_SIZE;
    int target_2 = (pos_3 - pos_2) / TRIPLE_SIZE;
    ll num = 0;
    for(int idx=0; idx<triples; ++idx){
        for(int jdx=0; jdx<triples-idx; ++jdx){
            int kdx = triples-1 - idx - jdx;
            if(idx == target_1 && jdx == target_2){
                // ll val = encode(idx, pos_1+1, pos_2-1);
                // val *= dp[jdx];
                // val += encode(jdx, pos_2+1, pos_3-1);
                // val *= dp[kdx];
                // val += encode(kdx, pos_3+1, right);
                // return num + val;
                return num + (
                    encode(idx, pos_1+1, pos_2-1) * dp[jdx] * dp[kdx] +
                    encode(jdx, pos_2+1, pos_3-1) * dp[kdx] +
                    encode(kdx, pos_3+1, right)
                );
            }
            else{
                num += dp[idx] * dp[jdx] * dp[kdx];
            }
        }
    }

    return num;
}

// decode(k, n) : decode integer n with k triples
string decode(int triples, ll nth){
    // NOTE : the same order as encode()
    for(int idx=0; idx<triples; ++idx){
        for(int jdx=0; jdx<triples-idx; ++jdx){
            int kdx = triples-1 - idx - jdx;

            ll cnt = dp[idx] * dp[jdx] * dp[kdx];
            if(cnt <= nth){
                nth -= cnt;
            }
            else{
                // ENCODE : nth = val_1 * dp[jdx] * dp[kdx] + val_2 * dp[kdx] + val_3
                ll val_3 = nth % dp[kdx];
                nth /= dp[kdx];
                ll val_2 = nth % dp[jdx];
                nth /= dp[jdx];
                ll val_1 = nth;
                return (
                    '(' + decode(idx, val_1) +
                    '|' + decode(jdx, val_2) +
                    ')' + decode(kdx, val_3)
                );
            }
        }
    }

    // base case : empty string
    return "";
}

void solve(){
    if(type == ENCODE){
        cout << encode(n, 0, 3*n-1) << endl;
    }
    else if(type == DECODE){
        cout << decode(n, integer) << endl;
    }
}

void input(){
    // validate();
    initialize();

    cin >> type;
    cin >> t;
    while(t--){
        cin >> n;
        if(type == ENCODE){
            cin >> sequence;
        }
        else if(type == DECODE){
            cin >> integer;
        }

        solve();
    }
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    // solve();

    return 0;
}
