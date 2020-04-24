#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int board_y, board_x;
vector<vector<int>> pic;

int cur_cnt = 0;
void dfs(int y, int x, int value, bool check[][101]){
    for(int i = 0; i < 4; i++){
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if(ny >= 0 && ny < board_y && nx >= 0 && nx < board_x){
            if(check[ny][nx]) continue;
            if(pic[ny][nx] != value) continue;

            cur_cnt++;
            check[ny][nx] = true;
            dfs(ny, nx, value, check);
        }
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    bool check[101][101] = { 0, };
    int answer_cnt = 0;
    int answer_max = 0;
    board_y = m; board_x = n;
    pic = picture;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(check[i][j]) continue;
            if(!picture[i][j]) continue;

            answer_cnt++;
            cur_cnt++;
            check[i][j] = true;
            dfs(i, j, picture[i][j], check);
            answer_max = max(answer_max, cur_cnt);
            cur_cnt = 0;
        }
    }
    
    vector<int> answer(2);
    answer[0] = answer_cnt;
    answer[1] = answer_max;
    return answer;
}