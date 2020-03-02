#include <iostream>

#define endl "\n"

using namespace std;

int dp[1001][1001] = { 0, };
int map[1001][1001] = { 0, };

int max(int a, int b, int c){
    if(a  > b){
        if(a > c)
            return a;
        else
            return c;
    }
    else{
        if(b > c)
            return b;
        else
            return c;
    }
}

int main(void){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> map[i][j];
        }
    }
    
    dp[1][1] = map[1][1];
    for(int i = 2; i <= n; i++)
        dp[i][1] = dp[i - 1][1] + map[i][1];
    for(int j = 2; j <= m; j++)
        dp[1][j] = dp[1][j - 1] + map[1][j];

    for(int i = 2; i <= n; i++)
        for(int j = 2; j <= m; j++)
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j]) + map[i][j];
    
    cout << dp[n][m] << endl;
    return 0;
}