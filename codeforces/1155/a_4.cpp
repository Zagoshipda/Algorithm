// Educational Codeforces Round 63 (Rated for Div. 2)
// A. Reverse a Substring
// by, ko_osaga

// string 의 사용 관찰/ 연습해보기 

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300005;    
int n;
string s;

int main(){
	cin >> n;   // length <= 300000
	cin >> s;
	if(is_sorted(s.begin(), s.end())){
		cout << "NO";
		return 0;       
	}

    //string 을 사용하면 size메서드를 사용할 수 있고 배열처럼 string의 원소에 접근할 수 있음 

	for(int i=1; i<s.size(); i++){  
		if(s[i-1] > s[i]){
			printf("YES\n%d %d\n", i, i + 1);   //2줄 1줄로 짧게 표현하기 
			return 0;
		}
	}
}