/*
    ==== 단순 실수 ====
    1. queue.pop() 부재
    2. 대문자 O을 숫자0으로 착각
    3. checkAnother 함수 작성 시 이상한 값을 비교 (check.y == check.x)
    4. 순서 지정이 제대로 안됐음 red -> cRed (큐 밖에 있는 초기 변수를 사용<계속 같은 순서로 동작>)

    ==== 로직 오류 ====
    1. 두 구슬이 같은 곳에 위치하게 됨 (먼저 출발한 구슬에도 동일한 위치인지 처리 했어야 했음)

    @@@@ 중대한 실수 @@@@
    '만약, 10번 이하로 움직여서 빨간 구슬을 구멍을 통해 빼낼 수 없으면 -1을 출력한다.'
    를 대충 읽고 한 시간동안 해맸음


    ==> 앞으로는 문제 정확히 읽고, 설계를 제대로 하자
*/

#include <iostream>
#include <queue>

using namespace std;
#define endl '\n'
#define TEST cout << "TEST" << endl;
#define RED 0
#define BLUE 1

char map[10][10] = { 0, };
bool check[10][10][10][10] = { 0, };
int n, m;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

struct Coor{
    int y;
    int x;
    Coor(int y, int x) : y(y), x(x) {}
    Coor(){}
};
Coor hole;

bool checkRange(Coor check){
    return (check.y >= 0 && check.y < n && check.x >= 0 && check.x < m);
}

bool checkMap(Coor check){
    return (map[check.y][check.x] != '#');
}

bool checkAnother(Coor current, Coor another){
    return ((current.y == another.y) && (current.x == another.x));
}

bool checkHole(Coor check){
    return ((check.y == hole.y) && (check.x == hole.x));
}

bool checkVisited(Coor red, Coor blue){
    return (check[red.y][red.x][blue.y][blue.x]);
}

int main(void){
    cin >> n >> m;
    Coor red;
    Coor blue;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j ++){
            cin >> map[i][j];
            if(map[i][j] == 'R'){
                red.y = i; red.x = j;
                map[i][j] = '.';
            }
            else if(map[i][j] == 'B'){
                blue.y = i; blue.x = j;
                map[i][j] = '.';
            }
            else if(map[i][j] == 'O'){
                hole.y = i; hole.x = j;                
            }
        }
    }

    queue<pair<Coor, Coor> > q;
    check[red.y][red.x][blue.y][blue.x] = true;
    q.push(make_pair(red, blue));
    int answer = 0;
    while(!q.empty()){
        int qSize = q.size();
        while(qSize--){
            Coor cRed = q.front().first;
            Coor cBlue = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int order = RED;
                if(i == 0){
                    if(cRed.x == cBlue.x){
                        if(cRed.y > cBlue.y)
                            order = BLUE;
                        else
                            order = RED;
                    }
                }
                else if(i == 1){
                    if(cRed.y == cBlue.y){
                        if(cRed.x > cBlue.x)
                            order = RED;
                        else
                            order = BLUE;
                    }
                }
                else if(i == 2){
                    if(cRed.x == cBlue.x){
                        if(cRed.y > cBlue.y)
                            order = RED;
                        else
                            order = BLUE;
                    }
                }
                else if(i == 3){
                    if(cRed.y == cBlue.y){
                        if(cRed.x > cBlue.x)
                            order = BLUE;
                        else
                            order = RED;
                    }
                }

                Coor nRed = cRed;
                Coor nBlue = cBlue;
                bool redHole = false;
                bool blueHole = false;
                if(order == RED){
                    while(true){
                        nRed.y = nRed.y + dy[i];
                        nRed.x = nRed.x + dx[i];

                        if(!checkRange(nRed) || !checkMap(nRed) || checkAnother(nBlue, nRed)){
                            nRed.y = nRed.y - dy[i];
                            nRed.x = nRed.x - dx[i];
                            break;
                        }

                        if(checkHole(nRed)){
                            redHole = true;
                            nRed.y = -1; nRed.x = -1;
                            break;
                        }
                    }
                    
                    while(true){
                        nBlue.y = nBlue.y + dy[i];
                        nBlue.x = nBlue.x + dx[i];

                        if(!checkRange(nBlue) || !checkMap(nBlue) || checkAnother(nBlue, nRed)){
                            nBlue.y = nBlue.y - dy[i];
                            nBlue.x = nBlue.x - dx[i];
                            break;
                        }

                        if(checkHole(nBlue)){
                            blueHole = true;
                            nBlue.y = -1; nBlue.x = -1;
                            break;
                        }
                    }     
                }
                else if(order == BLUE){
                    while(true){
                        nBlue.y = nBlue.y + dy[i];
                        nBlue.x = nBlue.x + dx[i];

                        if(!checkRange(nBlue) || !checkMap(nBlue) || checkAnother(nBlue, nRed)){
                            nBlue.y = nBlue.y - dy[i];
                            nBlue.x = nBlue.x - dx[i];
                            break;
                        }

                        if(checkHole(nBlue)){
                            blueHole = true;
                            nBlue.y = -1; nBlue.x = -1;
                            break;
                        }
                    }

                    while(true){
                        nRed.y = nRed.y + dy[i];
                        nRed.x = nRed.x + dx[i];

                        if(!checkRange(nRed) || !checkMap(nRed) || checkAnother(nRed, nBlue)){
                            nRed.y = nRed.y - dy[i];
                            nRed.x = nRed.x - dx[i];
                            break;
                        }

                        if(checkHole(nRed)){
                            redHole = true;
                            nRed.y = -1; nRed.x = -1;
                            break;
                        }
                    }
                }

                if(redHole || blueHole){
                    if(blueHole) continue;
                    if(blueHole && redHole) continue;

                    if(redHole){
                        cout << answer + 1;
                        return 0;
                    }
                }
                
                if(!checkVisited(nRed, nBlue)){
                    check[nRed.y][nRed.x][nBlue.y][nBlue.x] = true;
                    q.push(make_pair(nRed, nBlue));
                }
            }
        }
        if(answer >= 9) break;
        answer++;
    }

    cout << -1;
    return 0;
}