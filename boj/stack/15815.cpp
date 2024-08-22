/*
    https://www.acmicpc.net/problem/15815
    (evaluate the expression)

    solutions
        using array index
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
    a+b*c = abc*+
    a*b+c = ((a*b)+c) = (a*b)c+ = ab*c+

    12*3+

    ((a+b)+(c*d)) = ((ab+)+(cd)*) = ab+cd*+
    (a+(b+(c*d))) = (a+(b+cd*)) = a+bcd*+ = abcd*++

    ((a+b)+c) = (ab+)+c = ab+c+
    a+(b+c) = a+bc+ = abc++
*/

string expression;
void solve(){
    int len = expression.size();
    stack<char> stk_operation;
    stack<int> stk_number;
    for(int idx=0; idx<len; ++idx){
        if('0' <= expression[idx] && expression[idx] <= '9'){
            stk_number.push(expression[idx] - '0');
        }
        else{   // expression[idx] < '0'
            int num_1 = stk_number.top();
            stk_number.pop();
            int num_2 = stk_number.top();
            stk_number.pop();

            // NOTE : numbers in reverse order
            if(expression[idx] == '+'){
                stk_number.push(num_2 + num_1);
            }
            else if(expression[idx] == '-'){
                stk_number.push(num_2 - num_1);
            }
            else if(expression[idx] == '*'){
                stk_number.push(num_2 * num_1);
            }
            else if(expression[idx] == '/'){
                stk_number.push(num_2 / num_1);
            }
        }
    }

    cout << stk_number.top() << endl;
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
