/*
    https://www.acmicpc.net/problem/1181
    (word sorting)

    reference
    https://en.cppreference.com/w/cpp/container/set/key_comp

    solutions
        https://www.acmicpc.net/source/16771242
        (applied7076, 16 ms) using vector<string>

        https://www.acmicpc.net/source/6931643
        (cgiosy, 12 ms) implemented in solve_2()

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

struct cmp_word{
    bool operator()(const string& str_1, const string& str_2) const {
        if(str_1.size() == str_2.size()){
            return (str_1 < str_2);
        }
        else{
            return str_1.size() < str_2.size();
        }
    }
};

const int MAX_NUM = 20'000;
const int MAX_WORD_LEN = 50;
int N;
string word;
set<string, cmp_word> words;
set<pair<int, string> > words_2;

void solve_1(){
    for(string str : words){
        cout << str << endl;
    }
}

void solve_2(){
    for(pair<int, string> str : words_2){
        cout << str.second << endl;
    }
}

void solve(){
    // solve_1();

    solve_2();
}

void input(){
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> word;
        // words.insert(word);
        words_2.insert({word.size(), word});
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
