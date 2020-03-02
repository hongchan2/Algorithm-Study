#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
using namespace std;

#define endl '\n'
#define TEST cout << "TEST" << endl;

int dh[4] = { -1, 0, 1, 0 };
int dw[4] = { 0, 1, 0, -1 };

int main(void){
    int T;
    cin >> T;
    while(T--){
        char map[102][102] = { 0, };
        vector<vector<pair<int, int> > > door(27);
        int key[27] = { 0, };
        int h, w;
        string keys;

        cin >> h >> w;
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                cin >> map[i][j];
            }
        }
        cin >> keys;
        if(keys != "0"){
            int len = keys.size();
            for(int i = 0; i < len; i++){
                key[keys[i] - 'a'] += 1;
            }
        }
        for(int i = 0; i <= w + 1; i++){
            map[0][i] = map[h + 1][i] = '.';
        }
        for(int i = 0; i <= h + 1; i++){
            map[i][0] = map[i][w + 1] = '.';
        }

        bool check[102][102] = { false, };
        int answer = 0;
        queue<pair<int, int> > q;
        check[0][0] = true;
        q.push(make_pair(0, 0));
        while(!q.empty()){
            int ch = q.front().first;
            int cw = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nh = ch + dh[i];
                int nw = cw + dw[i];

                if(nh >= 0 && nh <= h + 1 && nw >= 0 && nw <= w + 1 && !check[nh][nw]){
                    if(map[nh][nw] == '*') continue;

                    if(map[nh][nw] == '$' || map[nh][nw] == '.'){
                        check[nh][nw] = true;
                        q.push(make_pair(nh, nw));
                        
                        if(map[nh][nw] == '$'){
                            answer++;
                        }
                    }
                    else if(isupper(map[nh][nw])){
                        // door
                        if(key[map[nh][nw] - 'A']){
                            check[nh][nw] = true;
                            q.push(make_pair(nh, nw));
                        }
                        else{
                            door[map[nh][nw] - 'A'].push_back(make_pair(nh, nw));
                        }
                    }
                    else if(islower(map[nh][nw])){
                        // key
                        key[map[nh][nw] - 'a'] += 1;
                        check[nh][nw] = true;
                        q.push(make_pair(nh, nw));
                        for(auto p : door[map[nh][nw] - 'a']){
                            check[p.first][p.second] = true;
                            q.push(make_pair(p.first, p.second));
                        }
                        door[map[nh][nw] - 'a'].clear();
                    }
                }
            }
        }

        cout << answer << endl;
    }
    return 0;
}