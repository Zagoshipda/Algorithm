/*
    https://www.acmicpc.net/problem/15815
    (calculate postfix notation)

    similar problem
        https://www.acmicpc.net/problem/1918
        (postfix notation 1)
        https://www.acmicpc.net/problem/15659
        (operator insertion 3)

    solutions
        using array index : idx-2, idx-1, idx
            https://www.acmicpc.net/source/8814794
            (YunGoon, 0 ms)
            https://www.acmicpc.net/source/18262000
            (goooora, 0 ms)

        using stack
        https://www.acmicpc.net/source/8795593
        (fromis_9, 0 ms)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        prefix, infix, postfix notation

        a+b*c = abc*+
        a*b+c = ((a*b)+c) = (a*b)c+ = ab*c+

        12*3+

        ((a+b)+(c*d)) = ((ab+)+(cd)*) = ab+cd*+
        (a+(b+(c*d))) = (a+(b+cd*)) = a+bcd*+ = abcd*++

        ((a+b)+c) = (ab+)+c = ab+c+
        a+(b+c) = a+bc+ = abc++
*/

const int MAX_LENGTH = 100;     // 10^2

string expression;

void solve_stack(){
    stack<int> stk_number;
    int len = expression.size();

    for(int idx=0; idx<len; ++idx){
        char curr = expression[idx];
        if('0' <= curr && curr <= '9'){
            stk_number.push(curr - '0');
        }
        else{   // curr < '0'
            // NOTE : numbers from stack in reverse order
            int num_2 = stk_number.top();
            stk_number.pop();
            int num_1 = stk_number.top();
            stk_number.pop();

            if(curr == '+'){
                stk_number.push(num_1 + num_2);
            }
            else if(curr == '-'){
                stk_number.push(num_1 - num_2);
            }
            else if(curr == '*'){
                stk_number.push(num_1 * num_2);
            }
            else if(curr == '/'){
                stk_number.push(num_1 / num_2);
            }
        }
    }

    cout << stk_number.top() << endl;
}

void solve(){
    solve_stack();
}

void input(){
    cin >> expression;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
