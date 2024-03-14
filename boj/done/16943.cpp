/*
    https://www.acmicpc.net/problem/16943
    (number rearrangement)

    solutions
        next_permutation()
            https://www.acmicpc.net/source/35144696
            (limd123, 20 ms)
            https://www.acmicpc.net/source/42002794
            (dyj07132, 32 ms)
            https://www.acmicpc.net/source/54778848
            (maplestory1419, 16 ms)

        prev_permutation()
            https://www.acmicpc.net/source/24019817
            (0rch1d, 12 ms)
            https://www.acmicpc.net/source/21036092
            (kingink, 0 ms)

        recursive backtracking
            https://www.acmicpc.net/source/35164933
            (limd123, 48 ms)
            https://www.acmicpc.net/source/14931133
            (rlaeogh89, 12 ms) : counting sort method
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    time complexity
        9! ~ 10^9
        10! (= 3628800) ~ 10^5 * 120 ~ 10^7
        => brute force

1234 4100

// 3421

424 333

// 244

*/

const int MAX_NUM = 1'000'000'000;
const int MAX_DIGIT = 9;

string A_str, B_str;

multiset<char> A_digits;
void solve_wrong(){
    int len_A = A_str.size();
    int len_B = B_str.size();
    if(len_A > len_B){
        cout << -1 << endl;
    }
    else if(len_A < len_B){
        sort(A_str.begin(), A_str.end(), greater<int>());
        for(char A : A_str){
            cout << A;
        }
        cout << endl;
    }
    else{   // len_A == len_B
        for(int idx=0; idx<len_A; ++idx){
            A_digits.insert(A_str[idx]);
            // A_digits.insert(A_str[idx] - '0');
        }

        // vector<char> C_num;
        string C_str;
        for(int idx=0; idx<len_B; ++idx){
            // WRONG : may not work
            auto it = lower_bound(A_digits.begin(), A_digits.end(), B_str[idx]);
            // auto it = upper_bound(A_digits.begin(), A_digits.end(), B_str[idx]);
            int pos = distance(A_digits.begin(), it);
            if(pos){
                --it;   // WRONG : not sure to use the previous number
                // C_num.push_back(*it);
                C_str.push_back(*it);
                A_digits.erase(it);
            }
            else{
                cout << -1 << endl;
                return;
            }
        }

        if(C_str == B_str){
            prev_permutation(C_str.begin(), C_str.end());
        }
        if(C_str[0] == '0'){
            cout << -1 << endl;
        }
        else{
            cout << C_str << endl;
        }
        // for(char C : C_num){
        //     cout << C;
        // }
        // cout << endl;
    }
}

void solve_brute_force_1(){
    string C_str = "";
    sort(A_str.begin(), A_str.end(), less<int>());
    do{
        if(stoi(A_str) < stoi(B_str)){
            C_str = A_str;
        }
        else{
            break;
        }
    }
    while(next_permutation(A_str.begin(), A_str.end()));

    if(C_str.size() && C_str[0] > '0'){ // C cannot start with 0
        cout << C_str << endl;
    }
    else{
        cout << -1 << endl;
    }
}

void solve_brute_force_2(){
    sort(A_str.begin(), A_str.end(), greater<char>());

    do{
        if(stoi(A_str) < stoi(B_str)){
            if(A_str[0] != '0'){
                cout << A_str << endl;
                return;
            }
            else{
                break;
            }
        }
    }
    while(prev_permutation(A_str.begin(), A_str.end()));

    cout << -1 << endl;
}

bool used[MAX_DIGIT + 1];
string ans_str;
void backtracking_string(int nth, string C_str){
    if(nth >= A_str.size()){
        if(ans_str < C_str && stoi(C_str) < stoi(B_str) && C_str[0] != '0'){
            ans_str = C_str;
        }
        return;
    }

    for(int idx=0; idx<A_str.size(); ++idx){
        if(!used[idx]){
            used[idx] = true;
            backtracking_string(nth+1, C_str + A_str[idx]);
            used[idx] = false;
        }
    }
}

vector<int> A_digit;
int ans_num;
void backtracking_number(int nth, int num){
    if(nth >= A_str.size()){
        if(ans_num < num && num < stoi(B_str) && num / (int)pow(10, A_digit.size()-1)){
            ans_num = num;
        }
        return;
    }

    for(int idx=0; idx<A_digit.size(); ++idx){
        if(!used[idx]){
            used[idx] = true;
            backtracking_number(nth+1, 10*num + A_digit[idx]);
            used[idx] = false;
        }
    }
}

void solve_backtracking(){
    // backtracking_string(0, "");
    // if(ans_str.size()){
    //     cout << ans_str << endl;
    // }
    // else{
    //     cout << -1 << endl;
    // }

    for(int idx=0; idx<A_str.size(); ++idx){
        A_digit.push_back(A_str[idx] - '0');
    }
    backtracking_number(0, 0);
    if(ans_num){
        cout << ans_num << endl;
    }
    else{
        cout << -1 << endl;
    }
}

void solve(){
    // solve_wrong();

    solve_brute_force_1();
    // solve_brute_force_2();

    // solve_backtracking();
}

void input(){
    cin >> A_str >> B_str;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
