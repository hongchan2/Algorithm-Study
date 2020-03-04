#include <iostream>

using namespace std;

#define endl '\n'
#define TEST cout << "TEST" << endl;
#define TOP 1
#define BOTTOM 6

int zusa[7] = { 0, };
int zusaDirection[5][7] = { { 0, },
                        { 987, 2, 0, 3, -3, 0, -2 },
                        { 987, 3, 0, -2, 2, 0, -3},
                        { 987, 1, 4, 0, 0, -4, -1},
                        { 987, 4, -1, 0, 0, 1, -4}
                        };
int map[21][21] = { 0, };
int dx[5] = { 987, 1, -1, 0, 0 };
int dy[5] = { 987, 0, 0, -1, 1 };

int main(void){
    int n, m, x, y, k;
    cin >> n >> m >> y >> x >> k;
    for(int i = 1; i <= n; i++){
       for(int j = 1; j <= m; j++){
           cin >> map[i][j];
       }
    }
    x++; y++;
    while(k--){
        int nextOper = 0;
        cin >> nextOper;

        int ny = y + dy[nextOper];
        int nx = x + dx[nextOper];
        if(ny >= 1 && ny <= n && nx >= 1 && nx <= m){
            // move
            int newZusa[7] = { 0, };
            for(int i = 1; i <= 6; i++){
                newZusa[i + zusaDirection[nextOper][i]] = zusa[i];
            }

            if(map[ny][nx] == 0){
                map[ny][nx] = newZusa[BOTTOM];
            }
            else{
                newZusa[BOTTOM] = map[ny][nx];
                map[ny][nx] = 0;
            }
            
            cout << newZusa[TOP] << endl;

            for(int i = 1; i <= 6; i++){
                zusa[i] = newZusa[i];
            }
            y = ny; x = nx;
        }
    }

    return 0;
}