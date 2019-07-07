//D. Vus the Cossack and Numbers
//Accepted...! -> by using brute force... constructive algorithm/ greedy algorithm
//생각보다 쉬운 문제였음... 간단할 것 같은 알고리즘이 지나치게 복잡하게 느껴진다면 brute force도 좋은 해결방법이 될 수 있을 것. 이 문제의 경우 각 step마다 문제의 조건을 맞추어가도록 greedy하게 단계적으로 쌓아나가는 방식으로의 해결이 가능했음... 

    //Q. 위와 같이 하면 항상 정답을 찾을 수 있는가...? 
    //A. 가능한 반례로는 어떠한 것이 있을까...? 예를 들어, sum < 0 이지만 abs(a[i] - (b[i]+1)) >= 1 이 되는 경우로 인해 최종적으로는 sum < 0 (!= 0) 이 되어버리는 경우가 존재한다면, 아래의 algorithm은 정답을 구해주지 못한다. 
    //위 반례가 가능하려면, 

    //우선 sum < 0 이 되는 경우는 어떤 경우인가...? 반올림 round()를 한 후의 bi들의 합이 < 0 이 되려면 다음 case #1과 같이 어떤 양수를 0.5보다 큰 소수점의 두 음수의 합으로 쪼개야 한다
        //case #1 (1) sum < 0
        // 1 -> 1
        // -0.5 -> -1
        // -0.5 -> -1

        //case #1 (2) sum > 0
        // -1 -> -1
        // 0.5 -> 1
        // 0.5 -> 1
    //bi의 sum == 0 이 되려면 양수를 0.5보다 작은 소수점, 큰 소수점의 2개의 불균형한 소수점 음수의 합으로 쪼개면 된다    
        //case #2 sum == 0
        // 1 -> 1
        // -0.4 -> 0
        // -0.6 -> -1
    //(A) 이제 sum < 0 이라 가정해보자 그러면 결국 어떤 bi + 1을 해주어야 할 것이다. 그런데 이 경우 원래 bi자체가 내림을 한 셈이 되었으므로 +1을 해도 원본인 ai와 bi + 1의 차이가 1을 넘지 않게 된다 
    //(B) 마찬가지로 sum > 0인 경우 어떤 bi의 경우 올림을 한 상태일 것이므로 bi - 1 을 해도 ai와의 차이가 1을 넘지 않게 된다.
    //따라서 (A), (B)로부터 아래의 알고리즘의 correctness가 증명되었다 

    //부가적으로, 반올림round()에 대한 개념을 재정립할 필요가 있다. 반올림을 단순히 수직선 위에서의 구간별로 한 숫자에 대응하는 것이라고 이해하면 음수의 경우의 반올림이 양수의 경우와 대칭적인(혹은 시각에 따라 반대의) 형태로 나타나는 것이 아닌가라고 생각할 수 있다. 따라서 일관된 이해를 위해서는, 원점(0)을 기준으로 특정 숫자들이 떨어져있는 상대적인 거리에 따라 가장 가까운 특정 정수로 대표값을 취하는 것이라 생각하는 것이 더 올바른 이해라고 할 수 있겠다 


    //참고로, python에서도 반올림을 처리하는 round() function이 있는데, Python2에서는 사사오입법을, Python3에서는 오사오입법을 쓴다고 하므로 나중에 다시 확인해볼 것 



#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
// #define ll long long    // range : -9*10^18 ~ 9*10^18

int n;
int sum;

int main(){
	IOS;

    cin >> n;
    double a[n+1] = {0};
    int b[n+1] = {0};
    
    for(int i=1; i<=n; i++){
        double input;
        cin >> input;
        a[i] = input;
        b[i] = round(input);
        sum += b[i];
    }

    for(int i=1; i<=n; i++){
        if(sum > 0){
            if(abs(a[i] - (b[i]-1)) < 1){
                cout << b[i]-1 << endl;
                sum -= 1;
            }else{
                cout << b[i] << endl;
            }
            
        }else if(sum < 0){
            if(abs(a[i] - (b[i]+1)) < 1){
                cout << b[i]+1 << endl;
                sum += 1;
            }else{
                cout << b[i] << endl;
            }

        }else{
            cout << b[i] << endl;
        }
    }
    
    return 0;
}

