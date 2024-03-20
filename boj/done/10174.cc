/*
    https://www.acmicpc.net/problem/10174
    (palindromes)

    solutions
        https://www.acmicpc.net/source/14741053
        (putdata, 0 ms) : transform(), tolower(), implemented in solve_2()

        https://www.acmicpc.net/source/5013934
        (Nada, 0 ms) : ASCII transformation, implemented in solve_3()

    references
        https://developer0hye.tistory.com/450

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    palindrome : same in either the forward or reverse direction
        not worry about capitalization
        all characters including blanks are considered
*/

int n;
string word;

void solve_1(){
    string lower_word;
    for(char ch : word){
        lower_word += static_cast<char>(tolower(ch));
    }

    int len = lower_word.size();
    for(int start=0, end=len-1; start<=end; ++start, --end){
        if(lower_word[start] != lower_word[end]){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

void solve_2(){
    // transform(word.begin(), word.end(), word.begin(), ::tolower);
    // transform(word.begin(), word.end(), word.begin(), [](unsigned char c){ return tolower(c); });

    // If f returns a result, the result is ignored
    // for_each(word.begin(), word.end(), [](char c){ c = tolower(c); });  // WRONG
    for_each(word.begin(), word.end(), [](char& c){ c = tolower(c); }); // AC : use reference

    int len = word.size();
    for(int start=0, end=len-1; start<=end; ++start, --end){
        if(word[start] != word[end]){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

void solve_3(){
    for(char& ch : word){
        if('A' <= ch && ch <= 'Z'){
            ch = ch - 'A' + 'a';
        }
    }

    int len = word.size();
    for(int start=0, end=len-1; start<=end; ++start, --end){
        if(word[start] != word[end]){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

void solve(){
    // solve_1();

    // solve_2();

    solve_3();
}

void input(){
    cin >> n;
    // Extracts and discards characters from the input stream until and including delim
    // Ignoring all leftover characters on the line of input with
    // cin.ignore();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while(n--){
        // Extracts characters from stream until end of line or the specified delimiter delim
        getline(cin, word);
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
