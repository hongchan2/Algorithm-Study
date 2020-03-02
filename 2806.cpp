#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'

// dp[0][i] = 1 ~ i 를 a로 채우는데 걸리는 최소 값
// dp[1][i] = 1 ~ i 를 b로 채우는데 걸리는 최소 값
int dp[2][1000000] = { 0, };

int main(void){
    int n;
    string s;
    cin >> n >> s;

    if(s[0] == 'A'){
        dp[1][0] = 1;
    }
    else if(s[0] == 'B'){
        dp[0][0] = 1;
    }

    for(int i = 1; i < n; i++){
        if(s[i] == 'A'){
            dp[0][i] = dp[0][i - 1];
            dp[1][i] = min(dp[0][i - 1], dp[1][i - 1]) + 1;
        }
        else if(s[i] == 'B'){
            dp[1][i] = dp[1][i - 1];
            dp[0][i] = min(dp[0][i - 1], dp[1][i - 1]) + 1;
        }
    }

    cout << dp[0][n - 1] << endl;
    return 0;
}