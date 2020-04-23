/*
    Big Integer를 처음 구현해 봐서 답을 보고 풀어본 문제.

    100C50 이 long long 범위를 넘어가기 때문에 따로 Big Integer를 구현해야 했다.
    String으로 이를 구현!
    (Struct high/low 로 나누어서 구현하는 방법도 있었음)
*/

#include <iostream>
#include <algorithm>

using namespace std;

string s1, s2;

string sum(string s1, string s2){
    long long sum = 0;
    string returnValue = "";

    while(!s1.empty() || !s2.empty() || sum){

        if(!s1.empty()){
            sum += s1.back() - '0';
            s1.pop_back();
        }

        if(!s2.empty()){
            sum += s2.back() - '0';
            s2.pop_back();
        }

        returnValue.push_back((sum % 10) + '0');
        sum /= 10;
    }

    reverse(returnValue.begin(), returnValue.end());
    
    return returnValue;
}

int main(void){
    cin >> s1 >> s2;
    cout << sum(s1, s2);
    return 0;
}