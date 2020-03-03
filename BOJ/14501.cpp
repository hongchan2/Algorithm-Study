#include <iostream>
#include <algorithm>

using namespace std;

int n;
int t[16] = { 0, };
int p[16] = { 0, };
int answer = -987654321;

void dfs(int depth, int sum){
    if(depth == n + 1){
        answer = max(answer, sum);
        return;
    }

    if(depth + t[depth] - 1 <= n){
        dfs(depth + t[depth], sum + p[depth]);
    }
    dfs(depth + 1, sum);
}

int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> t[i] >> p[i];
    }

    dfs(1, 0);
    cout << answer;
    return 0;
}