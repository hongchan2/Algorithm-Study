#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
#define endl '\n'
#define TEST cout << "TEST" << endl

char map[101][101] = { 0, };
int mak[101] = { 0, };
int r, c;
int makCnt;

int check[101][101] = { 0, };
int clusterCnt = 1;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

void printMap(){
    // cout << endl;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
}

void dfs(int row, int col){
    for(int i = 0; i < 4; i++){
        int nr = row + dr[i];
        int nc = col + dc[i];

        if(nr >= 1 && nr <= r && nc >= 1 && nc <= c){
            if(map[nr][nc] == 'x' && !check[nr][nc]){
                check[nr][nc] = clusterCnt;
                dfs(nr, nc);
            }
        }
    }
}

int main(void){
    cin >> r >> c;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> map[i][j];
        }
    }
    cin >> makCnt;
    for(int i = 1; i <= makCnt; i++){
        cin >> mak[i];
    }

    for(int i = 1; i <= makCnt; i++){
        int nr = r - mak[i] + 1;
        if(i % 2 == 1){
            // 홀(왼)
            for(int j = 1; j <= c; j++){
                if(map[nr][j] == 'x'){
                    map[nr][j] = '.';
                    break;
                }
            }
        }
        else{
            // 짝(오)
            for(int j = c; j >= 1; j--){
                if(map[nr][j] == 'x'){
                    map[nr][j] = '.';
                    break;
                }
            }
        }

        for(int j = 1; j <= r; j++){
            for(int k = 1; k <= c; k++){
                if(map[j][k] == 'x' && !check[j][k]){
                    check[j][k] = clusterCnt;
                    dfs(j, k);
                    clusterCnt++;
                }
            }
        }
    
        // clusterCnt == 4 -> 1 ~ 3
        unordered_map<int, bool> m;
        int airNum = 0;
        for(int i = 1; i < clusterCnt; i++){
            m.insert(make_pair(i, false));
        }
        for(int j = 1; j <= c; j++){
            if(check[r][j] == 0) continue;
            auto iter = m.find(check[r][j]);
            iter->second = true;
        }
        unordered_map<int, bool>::iterator iter;
        for(iter = m.begin(); iter != m.end(); iter++){
            if(!iter->second){
                airNum = iter->first;
                break;
            }
        }

        if(airNum != 0){
            // row / col
            vector<pair<int, int> > v;
            for(int j = r; j >= 1; j--){
                for(int k = c; k >= 1; k--){
                    if(check[j][k] == airNum){
                        v.push_back(make_pair(j, k));
                    }
                }
            }

            int possibleNum = 987654321;
            for(auto p : v){
                int cr = p.first;
                int cc = p.second;

                int curNum = 0;
                for(int j = cr + 1; j <= r; j++){
                    if(check[j][cc] != 0 && check[j][cc] != airNum){
                        break;
                    }
                    curNum++;
                }
                possibleNum = min(possibleNum, curNum);
            }

            for(auto p : v){
                int cr = p.first;
                int cc = p.second;
                map[cr][cc] = '.';
                map[cr + possibleNum][cc] = 'x';
            }
        }

        memset(check, 0, sizeof(check));
        clusterCnt = 1;
        // printMap();
    }

    printMap();
    return 0;
}