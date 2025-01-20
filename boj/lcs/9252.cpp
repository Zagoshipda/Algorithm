/*
    LCS 2 : length and string
    https://www.acmicpc.net/problem/9252

    QnA
    https://www.acmicpc.net/board/view/99431

    References
    https://www.crocus.co.kr/787
    https://velog.io/@treeboy2762/92512%EB%B2%88-LCS
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define INITIAL_VALUE -1
#define SIZE 1000
string str_1, str_2;
int dp[SIZE + 1][SIZE + 1];
pair<int, int> parent[SIZE + 1][SIZE + 1];
string lcs;

// NOTE : just initializing [array of string] takes a lot of time (8ms -> 28ms)
// string dp_2[SIZE + 1][SIZE + 1];

void input(){
    cin >> str_1 >> str_2;
}

void initialize(){
    for(int i=0; i<=SIZE; ++i){
        for(int j=0; j<=SIZE; ++j){
            dp[i][j] = INITIAL_VALUE;
        }
    }
}

void print_lcs_and_its_length(){

    // for(int row=0; row<=str_1.length(); ++row){
    //     for(int col=0; col<=str_2.length(); ++col){
    //         cout << dp[row][col] << " ";
    //         // cout << parent[row][col].first << " " << parent[row][col].second << " / ";
    //     }
    //     cout << endl;
    // }

    // for(int row=str_1.length(), col=str_2.length(); row>0, col>0; ){
    //     // cout << "row / col : " << row << " " << col << endl;
    //     int next_row = parent[row][col].first;
    //     int next_col = parent[row][col].second;
    //     if(next_row == row - 1 && next_col == col - 1){
    //         lcs = str_1[row-1] + lcs;
    //     }
    //     row = next_row;
    //     col = next_col;
    // }

    // cout << dp[str_1.length()][str_2.length()] << endl;
    // cout << lcs << endl;



    // stack<char> stk;
    stack<int> stk;
    // vector<int> lcs;
    // int lcs[SIZE];
    // const int len = dp[str_1.length()][str_2.length()];
    // char lcs[len+1];
    // lcs[len] = '\0';

    // int pos = 0;
    // int pos = len-1;
    // NOTE : wrong answer at 95% for row>0 || col>0 condition -> dp[][] indexing may cause an error
    // NOTE : comma operator
    for(int row=str_1.length(), col=str_2.length(); col>0 && row>0 /*row>0, col>0*/ /*row>0 || col>0*/ ; ){
    // for(int row=str_1.length(), col=str_2.length(); dp[row][col]>0; ){
        // only 3 cases possible
        // if(dp[row][col] == 1 + dp[row-1][col-1]){
        //     // stk.push(str_1[row]);
        //     stk.push(row-1);
        //     --row;
        //     --col;
        // }
        // else if(dp[row][col] == dp[row-1][col]){
        //     --row;
        // }
        // else if(dp[row][col] == dp[row][col-1]){
        //     --col;
        // }

        // NOTE : order of condition matters.
        if(dp[row][col] == dp[row-1][col]){
            --row;
        }
        else if(dp[row][col] == dp[row][col-1]){
            --col;
        }
        // NOTE : time exceeded at 95% for col>0 || row>0
        else if(dp[row][col] == 1 + dp[row-1][col-1]){
            stk.push(row-1);
            // stk.push(str_1[row-1]);
            // lcs.push_back(row-1);
            // lcs[pos] = str_1[row-1];
            // --pos;
            --row;
            --col;
        }
    }
    // TODO : check condition
    // assert(stk.size() == len);

    cout << stk.size() << endl;
    while(!stk.empty()){
        // cout << stk.top();
        cout << str_1[stk.top()];
        // lcs[pos++] = str_1[stk.top()];
        stk.pop();
    }
    // cout << lcs << endl;


    // cout << lcs.size() << endl;
    // for(int i=lcs.size()-1; i>=0; --i){
    //     cout << str_1[lcs[i]];
    // }
    // cout << pos << endl;
    // for(int i=pos-1; i>=0; --i){
    //     cout << str_1[lcs[i]];
    // }


    // cout << len << endl;
    // cout << lcs << endl;
}


void lcs_bottom_up_1(){

    // initialize();

    for(int len_1=1; len_1<=str_1.length(); ++len_1){
        for(int len_2=1; len_2<=str_2.length(); ++len_2){
            // if(len_1 <= 0 || len_2 <= 0){
            //     dp[len_1][len_2] = 0;
            // }
            // else{
                if(str_1[len_1-1] == str_2[len_2-1]){
                    dp[len_1][len_2] = 1 + dp[len_1-1][len_2-1];
                    parent[len_1][len_2] = {len_1-1, len_2-1};
                }
                else{
                    int val_1 = dp[len_1-1][len_2];
                    int val_2 = dp[len_1][len_2-1];
                    if(val_1 > val_2){
                        dp[len_1][len_2] = val_1;
                        parent[len_1][len_2] = {len_1-1, len_2};
                    }
                    else{
                        dp[len_1][len_2] = val_2;
                        parent[len_1][len_2] = {len_1, len_2-1};
                    }
                }
            // }
        }
    }

    print_lcs_and_its_length();
}

// time exceeded
void lcs_bottom_up_2(){

    for(int len_1=0; len_1<=str_1.length(); ++len_1){
        for(int len_2=0; len_2<=str_2.length(); ++len_2){
            // if(len_1<=0 || len_2<=0){
            //     dp_2[len_1][len_2] = "";
            // }
            // else{
            //     if(str_1[len_1-1] == str_2[len_2-1]){
            //         // dp_2[len_1][len_2] = dp_2[len_1-1][len_2-1] + str_1[len_1-1];
            //         dp_2[len_1][len_2] = dp_2[len_1-1][len_2-1].append(str_1, len_1-1, 1);
            //     }
            //     else{
            //         if(dp_2[len_1-1][len_2].length() > dp_2[len_1][len_2-1].length()){
            //             dp_2[len_1][len_2] = dp_2[len_1-1][len_2];
            //         }
            //         else{
            //             dp_2[len_1][len_2] = dp_2[len_1][len_2-1];
            //         }
            //     }
            // }
        }
    }

    // lcs = dp_2[str_1.length()][str_2.length()];
    cout << lcs.length() << endl;
    cout << lcs << endl;
}

void lcs_bottom_up_3(){

    for(int len_1=1; len_1<=str_1.length(); ++len_1){
        for(int len_2=1; len_2<=str_2.length(); ++len_2){
            if(str_1[len_1-1] == str_2[len_2-1]){
                dp[len_1][len_2] = 1 + dp[len_1-1][len_2-1];
            }
            else{
                dp[len_1][len_2] = max(dp[len_1-1][len_2], dp[len_1][len_2-1]);
            }
        }
    }

    // stack<char> stk;
    stack<int> stk;
    for(int row=str_1.length(), col=str_2.length(); row>0 && col>0; ){
        // only 3 cases possible
        if(dp[row][col] == dp[row-1][col]){
            --row;
        }
        else if(dp[row][col] == dp[row][col-1]){
            --col;
        }
        else if(dp[row][col] == 1 + dp[row-1][col-1]){
            // stk.push(str_1[row]);
            stk.push(row-1);
            --row;
            --col;
        }
    }

    cout << stk.size() << endl;
    while(!stk.empty()){
        // cout << stk.top();
        cout << str_1[stk.top()];
        stk.pop();
    }
}

void lcs_top_down(){

}

void solve(){

    // lcs_bottom_up_1();

    // lcs_bottom_up_2();

    lcs_bottom_up_3();
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
