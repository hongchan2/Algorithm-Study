#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
#define endl '\n'

int dp[1001][1001] = { 0, };

int main(void){
    int n, m; 
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%1d", &dp[i][j]);

    int answer = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){            
            if(dp[i][j]){
                dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j - 1], dp[i - 1][j])) + 1;
                answer = max(answer, dp[i][j]);
            }
        }
    }

    cout << answer * answer << endl;
    return 0;
}