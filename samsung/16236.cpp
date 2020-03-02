#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

#define endl '\n'
#define TEST cout << "Test" << endl
class Point{
public:
    int y;
    int x;
};
int n;
int map[21][21] = { 0, };
Point shark;
int sharkAge = 2;
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};

void debug(){
    cout << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << map[i][j] << " ";
        cout << endl;
    }
}

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
            if(map[i][j] == 9){
                shark.y = i;
                shark.x = j;
                map[i][j] = 0;
            }
        }
    }

    int answer = 0;
    int eatCnt = 0;
    while(true){
        bool check[21][21] = { false, };
        queue<pair<int, int> > q;
        q.push(make_pair(shark.y, shark.x));
        check[shark.y][shark.x] = true;
        int qAns = 0;

        bool foundFlag = true;
        vector<pair<int, int> > found;
        while(!q.empty() && foundFlag){
            int size = q.size();
            while(size--){
                auto p = q.front(); q.pop();
                int cy = p.first;
                int cx = p.second;

                if((map[cy][cx] > 0) && (map[cy][cx] < sharkAge)){
                    foundFlag = false;
                    found.push_back(make_pair(cy, cx));
                }
                if(!foundFlag)
                    continue;

                for(int i = 0; i < 4; i++){
                    int ny = cy + dy[i];
                    int nx = cx + dx[i];

                    if(ny >= 0 && ny < n && nx >= 0 && nx < n){
                        if(!check[ny][nx] && map[ny][nx] <= sharkAge){
                            check[ny][nx] = true;
                            q.push(make_pair(ny, nx));
                        }
                    }
                }
            }
            qAns++;
        }
        
        if(!foundFlag){
            //found
            int min_y = 987;
            int min_x = 987;
            
            for(auto p : found){
                if(min_y == p.first){
                    min_x = min(min_x, p.second);
                }
                else if(min_y > p.first){
                    min_y = p.first;
                    min_x = p.second;
                }
                else if(min_y < p.first){
                    continue;
                }
            }
            
            shark.y = min_y;
            shark.x = min_x;
            answer += qAns - 1;
            eatCnt++;
            map[shark.y][shark.x] = 0;

            if(eatCnt == sharkAge){
                sharkAge++;
                eatCnt = 0;
            }

            // debug();
            // cout << qAns << endl;
            continue;
        }
        else
            break;
    }

    cout << answer << endl;
    return 0;
}