#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

// https://stackoverflow.com/questions/28152496/how-to-iterate-through-a-set-of-sets-c

int t;
int n;

int main(){
	IOS;

    int a[2] = {1, 2};
    int b[2] = {1, 2};
    cout << boolalpha << (a == b) << endl;  // false
    cout << boolalpha << (a[0] == b[0] && a[1] == b[1]) << endl;    // true

    set<int> s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(1);
    cout << "s1 --- " << endl;
    for(auto it = s1.begin(); it != s1.end(); ++it){
        cout << *it << endl;
    }

    set<int> s2;
    s2.insert(1);
    s2.insert(2);
    s2.insert(1);
    cout << "s2 --- " << endl;
    for(auto it = s2.begin(); it != s2.end(); ++it){
        cout << *it << endl;
    }

    cout << boolalpha << (s1 == s2) << endl;    // true

    multiset<int> ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(1);
    cout << "ms --- " << endl;
    for(auto it = ms.begin(); it != ms.end(); ++it){
        cout << *it << endl;
    }

    cout << endl;
    cout << "multiset with pair ---" << endl;
    multiset<pair<int, int>> ms1;
    ms1.insert(make_pair(1, 2));
    multiset<pair<int, int>> ms2;
    ms2.insert(make_pair(1, 2));
    cout << boolalpha << (ms1 == ms2) << endl;  // true

    multiset<pair<int, int>> ms3;
    ms3.insert(make_pair(1, 2));
    multiset<pair<int, int>> ms4;
    ms4.insert(make_pair(2, 1));
    cout << boolalpha << (ms3 == ms4) << endl;  // false

    cout << boolalpha << (make_pair(1, 1) == make_pair(1, 1)) << endl;  // true
    cout << boolalpha << (make_pair(1, 2) == make_pair(2, 1)) << endl;  // false


    cout << "nested multiset ---" << endl;
    multiset<multiset<int>> mms1;
    multiset<int> ms01;
    ms01.insert(1);
    ms01.insert(1);
    mms1.insert(ms01);
    multiset<int> ms02;
    ms02.insert(2);
    ms02.insert(2);
    mms1.insert(ms02);
    for(auto it = mms1.begin(); it != mms1.end(); ++it){
        for(auto it2 = it->begin(); it2 != it->end(); ++it2){
            cout << *it2 << " ";
        }
        cout << endl;
    }
    cout << endl;


    return 0;
}
