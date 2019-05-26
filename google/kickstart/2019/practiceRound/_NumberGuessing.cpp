// by, analysis 

#include <iostream>
#include <string>

int main() {
    int num_test_cases;
    std::cin >> num_test_cases;

    for (int i = 0; i < num_test_cases; ++i) {
        int lo, hi;
        std::cin >> lo >> hi;

        int num_tries;
        std::cin >> num_tries;

        int head = lo + 1, tail = hi;
        while (true) {
            int m = (head + tail) / 2;
            std::cout << m << std::endl;
            std::string s;      //***string 으로 받기 
            std::cin >> s;

             //string 은 이렇게 간단하게 문자열 비교가 가능하다 
            if (s == "CORRECT")    
                break; 
            if (s == "TOO_SMALL")
                head = m + 1;
            else
                tail = m - 1;
        }
        
    }
    return 0;
}
