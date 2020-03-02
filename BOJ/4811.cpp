#include <iostream>

using namespace std;

#define endl '\n'

long long memo[31][31] = { 0, };

long long dfs(int full, int half, int day){
    long long returnValue = 0;

    if(day == 0){
        return 1;
    }

    if(memo[full][half]){
        return memo[full][half];
    }

    if(full > 0){
        returnValue += dfs(full - 1, half + 1, day - 1);
    }
    if(half > 0){
        returnValue += dfs(full, half - 1, day - 1);
    }
    memo[full][half] = returnValue;

    return returnValue;
}

int main(void){
    int n;
    while(cin >> n && n){
        cout << dfs(n, 0, 2 * n) << endl;
    }
    return 0;
}