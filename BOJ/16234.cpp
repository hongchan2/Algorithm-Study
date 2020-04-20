/*
    map은 해당 영역별 인구이동 후 존재하는 사람 수를 담고 있음.
    그러나 인구이동이 끝나고나서 m.clear()를 깜빡하여, 한 번에 못 품
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;
#define endl '\n';
#define TEST cout << "TEST" << endl;

int n, l, r;
int map[51][51] = { 0, };
int check[51][51] = { 0, };

int peopleSum;
int areaSum;
unordered_map<int, int> m;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void dfs(int cy, int cx,int areaCnt){
    for(int i = 0; i < 4; i++){
        int ny = cy + dy[i];
        int nx = cx + dx[i];

        if(ny >= 0 && ny < n && nx >= 0 && nx < n){
            if(check[ny][nx]) continue;

            int result = abs(map[cy][cx] - map[ny][nx]);
            if(result >= l && result <= r){
                peopleSum += map[ny][nx];
                areaSum++;

                check[ny][nx] = areaCnt;
                dfs(ny, nx, areaCnt);
            }
        }
    }
}

int main(void){
    cin >> n >> l >> r;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    int answer = 0;
    while(1){
        memset(check, 0, sizeof(check));
        m.clear();

        int areaCnt = 1;
        bool endCheck = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(check[i][j]) continue;

                peopleSum = map[i][j];
                areaSum = 1;

                check[i][j] = areaCnt;
                dfs(i, j, areaCnt);

                if(endCheck && (areaSum > 1)) endCheck = false;

                m.insert(make_pair(areaCnt, peopleSum / areaSum));
                areaCnt++;
            }
        }
        
        if(endCheck) break;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                unordered_map<int, int>::iterator iter = m.find(check[i][j]);
                map[i][j] = iter->second;
            }
        }

        answer++;
    }

    cout << answer;
    return 0;
}