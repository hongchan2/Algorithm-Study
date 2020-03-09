#include <iostream>
#include <algorithm>

using namespace std;

int n;
int map[101][101] = { 0, };
int curMap[101][101] = { 0, };
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void dfs(int y, int x){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny >= 0 && ny < n && nx >= 0 && nx < n){
            if(curMap[ny][nx] == 0){
                curMap[ny][nx] = 1;
                dfs(ny, nx);
            }
        }
    }
}

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    int answer = -987654321;
    for(int i = 0; i < 100; i++){

        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(map[j][k] <= i)
                    curMap[j][k] = -1;
                else
                    curMap[j][k] = 0;
            }
        }

        int cnt = 0;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(curMap[j][k] != 0) continue;

                cnt++;
                curMap[j][k] = 1;
                dfs(j, k);
            }
        }

        answer = max(answer, cnt);
        // cout << cnt << endl;
        if(cnt == 0)
            break;
    }

    cout << answer;
    return 0;
}