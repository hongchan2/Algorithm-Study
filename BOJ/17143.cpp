/*
    디버깅 없이 한 번에 풀 수 있었으나,
    break를 깜빡해서 조금 헤맸음
    -> 꼼꼼히 집중해서 문제를 풀자!
*/

#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

struct Shark{
    int speed;
    int direction;
    int size;

    Shark(int s, int d, int z) : speed(s), direction(d), size(z) {};
    Shark() {
        speed = 0;
        direction = 0;
        size = 0;
    };
};

int r, c, m;
Shark board[101][101];

void debug(){
    cout << endl;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cout << board[i][j].size << " ";
        }
        cout << endl;
    }
}

int catchShark(int col){
    for(int i = 1; i <= r; i++){
        if(!board[i][col].size) continue;

        int returnValue = board[i][col].size;
        board[i][col] = Shark();
        return returnValue;
    }

    return 0;
}

void moveShark(){
    vector<Shark> copyBoard[101][101];

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(!board[i][j].size) continue;

            int nr, nc, nDirection;
            int cSize = board[i][j].size;
            int cDirection = board[i][j].direction;
            int cSpeed = board[i][j].speed;
            // 이동 위치 계산 (i, j)      
            nr = i;
            nc = j;
            nDirection = cDirection;
            int remainSpeed = cSpeed;
            switch(board[i][j].direction){
                case 1:
                    while(true){
                        // up
                        if(nr - remainSpeed >= 1){
                            nr -= remainSpeed;
                            break;
                        }
                        
                        remainSpeed -= (nr - 1);
                        nDirection = 2;
                        nr = 1;

                        // down
                        if(nr + remainSpeed <= r){
                            nr += remainSpeed;
                            break;
                        }

                        remainSpeed -= (r - nr);
                        nDirection = 1;
                        nr = r;
                    }
                    break;

                case 2:
                    while(true){
                        // down
                        if(nr + remainSpeed <= r){
                            nr += remainSpeed;
                            break;
                        }

                        remainSpeed -= (r - nr);
                        nDirection = 1;
                        nr = r;

                        // up
                        if(nr - remainSpeed >= 1){
                            nr -= remainSpeed;
                            break;
                        }
                        
                        remainSpeed -= (nr - 1);
                        nDirection = 2;
                        nr = 1;
                    }
                    break;

                case 3:
                    while(true){
                        // right
                        if(nc + remainSpeed <= c){
                            nc += remainSpeed;
                            break;
                        }

                        remainSpeed -= (c - nc);
                        nDirection = 4;
                        nc = c;

                        // left
                        if(nc - remainSpeed >= 1){
                            nc -= remainSpeed;
                            break;
                        }
                        
                        remainSpeed -= (nc - 1);
                        nDirection = 3;
                        nc = 1;
                    }
                    break;

                case 4:
                    while(true){
                        // left
                        if(nc - remainSpeed >= 1){
                            nc -= remainSpeed;
                            break;
                        }
                        
                        remainSpeed -= (nc - 1);
                        nDirection = 3;
                        nc = 1;

                        // right
                        if(nc + remainSpeed <= c){
                            nc += remainSpeed;
                            break;
                        }

                        remainSpeed -= (c - nc);
                        nDirection = 4;
                        nc = c;
                    }
                    break;
            }  

            // 복사 배열에 상어 추가
            copyBoard[nr][nc].push_back(Shark(cSpeed, nDirection, cSize));
        }
    }

    // 배열 초기화
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            board[i][j] = Shark(0, 0, 0);
        }
    }

    // 복사 배열에 상어 여러 개라면 size 가장 큰 것만 살아남게 함
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            int cbSize = copyBoard[i][j].size();
            if(!cbSize) continue;

            int maxIndex = 0;
            for(int k = 1; k < cbSize; k++){
                if(copyBoard[i][j][maxIndex].size >= copyBoard[i][j][k].size) continue;

                maxIndex = k;
            }

            board[i][j] = Shark(copyBoard[i][j][maxIndex].speed, copyBoard[i][j][maxIndex].direction, copyBoard[i][j][maxIndex].size);
        }
    }
}

int main(void){
    cin >> r >> c >> m;

    for(int i = 0; i < m; i++){
        int sr, sc, s, d, z;
        cin >> sr >> sc >> s >> d >> z;
        board[sr][sc] = Shark(s, d, z);
    }

    int answer = 0;
    for(int i = 1; i <= c; i++){
        answer += catchShark(i);
        // debug();
        moveShark();
        // debug();
    }
    cout << answer;

    return 0;
}