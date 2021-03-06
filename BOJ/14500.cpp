/*
    DFS로 깊이 4까지 모두 탐색하고, ㅏ ㅓ ㅗ ㅜ 모양은 따로 처리해야 함
    처음에 DFS 탐색을 하는 것까지는 단 번에 알아챘으나,
    Testcase를 보고 ㅏ ㅓ ㅗ ㅜ 를 따로 처리해야 함을 인지함

    따라서 depth == 2 일 때, 바로 옆을 붙여줄 수 있으면 붙이고 dfs(depth + 2)로 해결
*/

#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'
#define TEST cout << "TEST" << endl;

int n, m;
int map[501][501] = { 0, };
bool check[501][501] = { false, };
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int answer = -987654321;
void dfs(int y, int x, int curValue, int depth){
    if(depth == 4){
        answer = max(answer, curValue);
        return;
    }
    
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny >= 0 && ny < n && nx >= 0 && nx < m){
            if(check[ny][nx]) continue;

            if(depth == 2){
                int ny2 = y + dy[(i + 1) % 4];
                int nx2 = x + dx[(i + 1) % 4];

                if(ny2 >= 0 && ny2 < n && nx2 >= 0 && nx2 < m && !check[ny2][nx2])
                    dfs(0, 0, curValue + map[ny][nx] + map[ny2][nx2], depth + 2);
            }

            check[ny][nx] = true;
            dfs(ny, nx, curValue + map[ny][nx], depth + 1);
            check[ny][nx] = false;
        }
    }
}

int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            check[i][j] = true;
            dfs(i, j, map[i][j], 1);
            check[i][j] = false;
        }
    }

    cout << answer;
    return 0;
}