/*  
 *   1. char 형으로 map을 사용할 때는 '정수' 형태로 넣거나 값을 비교해야 함 
 *      (map[i][j] = '0'  /  map[i][j] != '0')
 *   2. struct 를 사용할 때는 생성자를 함께 정의하기
 *      (q.push(Tong(1, 2, 3)))
 *   3. 범위 잘 설정하기 (통나무 회전 시)
 */
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;
#define endl '\n'
#define TEST cout << "TEST" << endl;
#define HOR 0   // horizontal
#define VER 1   // vertical

struct Tong{
    int centerY;
    int centerX;
    int direction;

    Tong(int y, int x, int d) : centerY(y), centerX(x), direction(d) {}
};
char map[51][51] = { 0, };
int check[51][51][2] = { 0, };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main(void){
    int n;
    cin >> n;
    
    int bCnt = 0, eCnt = 0;
    int by, bx, bDirection = -1;
    int ey, ex, eDirection = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c;
            cin >> c;
            if(c == 'B'){
                map[i][j] = '0';

                if(bCnt == 0){
                    bCnt++;
                    by = i; bx = j;
                }
                else if(bCnt == 1){
                    if(bx + 1 == j){
                        bDirection = HOR;
                    }
                    else{
                        bDirection = VER;
                    }
                    bCnt++;
                    by = i; bx = j;
                }
            }
            else if(c == 'E'){
                map[i][j] = '0';

                if(eCnt == 0){
                    eCnt++;
                    ey = i; ex = j;
                }
                else if(eCnt == 1){
                    if(ex + 1 == j){
                        eDirection = HOR;
                    }
                    else{
                        eDirection = VER;
                    }
                    eCnt++;
                    ey = i; ex = j;
                }
            }
            else{
                map[i][j] = c;
            }
        }
    }

    queue<Tong> q;
    check[by][bx][bDirection] = true;
    q.push(Tong(by, bx, bDirection));
    int answer = 0;
    while(!q.empty()){
        int qSize = q.size();
        while(qSize--){
            int cy = q.front().centerY;
            int cx = q.front().centerX;
            int cd = q.front().direction;
            q.pop();
            if(cy == ey && cx == ex && cd == eDirection){
                cout << answer;
                return 0;
            }
            
            // move
            for(int i = 0; i < 4; i++){
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                int nd = cd;

                if(nd == HOR){
                    if(ny >= 0 && ny < n && nx >= 1 && nx < n - 1){
                        if(map[ny][nx - 1] == '0' && map[ny][nx] == '0' && map[ny][nx + 1] == '0'){
                            if(!check[ny][nx][nd]){
                                check[ny][nx][nd] = true;
                                q.push(Tong(ny, nx, nd));
                            }
                        }
                    }
                }
                else if(nd == VER){
                    if(ny >= 1 && ny < n - 1 && nx >= 0 && nx < n){
                        if(map[ny - 1][nx] == '0' && map[ny][nx] == '0' && map[ny + 1][nx] == '0'){
                            if(!check[ny][nx][nd]){
                                check[ny][nx][nd] = true;
                                q.push(Tong(ny, nx, nd));
                            }
                        }
                    }
                }
            }

            // turn
            if(cd == HOR){
                if(cy >= 1 && cy < n - 1 && cx >= 1 && cx < n - 1){
                    bool isZero = true;
                    for(int i = -1; i < 2; i++){
                        if(map[cy - 1][cx + i] != '0'){
                            isZero = false;
                            break;
                        }
                        if(map[cy + 1][cx + i] != '0'){
                            isZero = false;
                            break;
                        }
                    }

                    if(isZero){
                        if(!check[cy][cx][VER]){
                            check[cy][cx][VER] = true;
                            q.push(Tong(cy, cx, VER));
                        }
                    }
                }
            }
            else if(cd == VER){
                if(cy >= 1 && cy < n - 1 && cx >= 1 && cx < n - 1){
                    bool isZero = true;
                    for(int i = -1; i < 2; i++){
                        if(map[cy + i][cx - 1] != '0'){
                            isZero = false;
                            break;
                        }
                        if(map[cy + i][cx + 1] != '0'){
                            isZero = false;
                            break;
                        }
                    }

                    if(isZero){
                        if(!check[cy][cx][HOR]){
                            check[cy][cx][HOR] = true;
                            q.push(Tong(cy, cx, HOR));
                        }
                    }
                }
            }
        }
        answer++;
    }

    cout << 0;
    return 0;
}