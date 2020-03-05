#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl '\n'
#define TEST cout << "TEST" << endl;

int n, m, k;
int map[101][101] = { 0, };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void debug(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

int dfs(int y, int x, int num){
    if(map[y][x] != 0) return 0;

    map[y][x] = num;
    int sum = 1;

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny >= 0 && ny < n && nx >= 0 && nx < m){
            sum += dfs(ny, nx, num);
        }
    }

    return sum;
}

int main(void){
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
        int y1, x1, y2, x2;
        cin >> x1 >> y1 >> x2 >> y2;
        y1 = n - y1 - 1;
        y2 = n - y2 - 1;

        // cout << "(" << y1 << ", " << x1 << ")" << "(" << y2 << ", " << x2 << ")" << endl;
        for(int i = y1; i > y2; i--){
            for(int j = x1; j < x2; j++){
                map[i][j] = -1;
            }
        }
    }
    
    int answer = 1;
    vector<int> ansVec;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 0){
                ansVec.push_back(dfs(i, j, answer));
                answer++;
            }
        }
    }
    // debug();

    cout << ansVec.size() << endl;
    sort(ansVec.begin(), ansVec.end());
    for(int num : ansVec){
        cout << num << " ";
    }
    return 0;
}