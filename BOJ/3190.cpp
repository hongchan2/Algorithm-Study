#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

bool apple[101][101] = { false, };
bool board[101][101] = { false, };
queue<pair<int, char> > q;
queue<int> direction;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

struct Point{
    int y;
    int x;
    Point(int y, int x): x(x), y(y) {};
};

int main(void){
    int n, k, l;
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        int y, x;
        cin >> y >> x;
        apple[y][x] = true;
    }
    cin >> l;
    for(int i = 0; i < l; i++){
        int n1;
        char c;
        cin >> n1 >> c;
        q.push(make_pair(n1, c));
    }

    board[1][1] = true;
    Point head(1, 1);
    Point tail(1, 1);
    int curIndex = 0;
    int answer = 0;
    while(true){
        answer++;

        // move
        int ny = head.y + dy[curIndex];
        int nx = head.x + dx[curIndex];

        if((ny >= 1 && ny <= n && nx >= 1 && nx <= n) && !board[ny][nx]){
            head.y = ny;
            head.x = nx;
            board[head.y][head.x] = true;
            direction.push(curIndex);
            if(apple[head.y][head.x]){
                // apple exist
                apple[head.y][head.x] = false;
            }
            else{
                // no apple
                board[tail.y][tail.x] = false;
                tail.y += dy[direction.front()];
                tail.x += dx[direction.front()];
                direction.pop();
            }
        }
        else
            break;
        
        // cout << answer << "sec / " << tail.y << ", " << tail.x << endl;
        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= n; j++){
        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // !q.empty()
        if(q.front().first == answer){
            char direction = q.front().second; q.pop();
            // curIndex = (curIndex + 1) % 4;
            // curIndex = (curIndex + 3) % 4;
            switch(direction){
                case 'D':
                    if(curIndex == 3)
                        curIndex = 0;
                    else
                        curIndex++;
                    break;
                case 'L':
                    if(curIndex == 0)
                        curIndex = 3;
                    else
                        curIndex--;
                    break;
            }
        }
    }

    cout << answer << endl;
    return 0;
}