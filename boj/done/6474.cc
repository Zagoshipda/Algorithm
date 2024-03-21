/*
    https://www.acmicpc.net/problem/6474
    (palindromes)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    - palindrome is a string that is the same forward as backward
    - mirrored string is a string for which when each of the elements of the string is changed to its reverse, and when the string is read backwards, the result is the same as the original string
    - mirrored palindrome is a string that meets the criteria of a regular palindrome and the criteria of a mirrored string

*/

const int MIN_LENGTH = 1;
const int MAX_LENGTH = 20;
string ANS_NOT_PALINDROME = " -- is not a palindrome.";
string ANS_IS_PALINDROME = " -- is a palindrome.";
string ANS_IS_MIRRORED = " -- is a mirrored string.";
string ANS_IS_MIRRORED_PALINDROME = " -- is a mirrored palindrome.";

string S;
bool is_palindrome(string str){
    int len = str.size();
    for(int left=0, right=len-1; left<=right; ++left, --right){
        if(str[left] != str[right]){
            return false;
        }
    }
    return true;
}

map<char, char> mirror_map;
void initialize(){
    mirror_map['A'] = 'A';
    mirror_map['E'] = '3';
    mirror_map['H'] = 'H';
    mirror_map['I'] = 'I';
    mirror_map['J'] = 'L';
    mirror_map['L'] = 'J';
    mirror_map['M'] = 'M';
    mirror_map['O'] = 'O';
    mirror_map['S'] = '2';
    mirror_map['T'] = 'T';
    mirror_map['U'] = 'U';
    mirror_map['V'] = 'V';
    mirror_map['W'] = 'W';
    mirror_map['X'] = 'X';
    mirror_map['Y'] = 'Y';
    mirror_map['Z'] = '5';
    mirror_map['1'] = '1';
    mirror_map['2'] = 'S';
    mirror_map['3'] = 'E';
    mirror_map['5'] = 'Z';
    mirror_map['8'] = '8';
}

bool is_mirrored(string str){
    int len = str.size();
    for(int left=0, right=len-1; left<=right; ++left, --right){
        if(mirror_map[str[left]] != str[right]){
            return false;
        }
    }
    return true;
}

void solve(){
    if(is_palindrome(S) && is_mirrored(S)){
        cout << S << ANS_IS_MIRRORED_PALINDROME << endl << endl;
    }
    else if(is_palindrome(S)){
        cout << S << ANS_IS_PALINDROME << endl << endl;
    }
    else if(is_mirrored(S)){
        cout << S << ANS_IS_MIRRORED << endl << endl;
    }
    else{
        cout << S << ANS_NOT_PALINDROME << endl << endl;
    }
}

void input(){
    initialize();

    while(cin >> S){
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
