#include <iostream>
#include <algorithm>

using namespace std;
#define endl '\n'
#define TEST cout << "TEST" << endl

int n;
int map[501][501] = { 0, };
int dp[501][501] = { 0, };
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int dfs(int y, int x){
    int& ret = dp[y][x];
    if(ret)
        return ret;    

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny >= 0 && ny < n && nx >= 0 && nx < n)
            if(map[y][x] < map[ny][nx])
                ret = max(ret, dfs(ny, nx));
    }
    ret++;
    return ret;
}

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> map[i][j];
    
    int answer = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            answer = max(answer, dfs(i, j));
        }
    }
    cout << answer;
    return 0;
}