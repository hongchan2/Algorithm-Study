#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

#define endl '\n'
int n, m, k;
int a[11][11] = { 0, };
vector<int> tree[11][11];
int yang[11][11] = { 0, };

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

vector<pair<int, int> > eTree;
vector<tuple<int, int, int> > dTree;


void spring(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(tree[i][j].empty())                          // change!
                continue;

            vector<int> temp;
            sort(tree[i][j].begin(), tree[i][j].end());
            for(auto num : tree[i][j]){
                if(num <= yang[i][j]){
                    yang[i][j] -= num;
                    num++;
                    temp.push_back(num);
                    
                    if(num % 5 == 0){
                        eTree.push_back(make_pair(i, j));    // change!
                    }
                }
                else{
                    // die
                    dTree.push_back(make_tuple(i, j, num / 2));     // change!
                }
            }
            tree[i][j] = temp;
        }
    }
}

void summer(){
    for(auto s : dTree){
        int y = get<0>(s);
        int x = get<1>(s);
        int age = get<2>(s);

        yang[y][x] += age;
    }
    dTree.clear();
}

void fall(){
    for(auto s : eTree){
        int y = s.first;
        int x = s.second;

        for(int k = 0; k < 8; k++){
            int ny = y + dy[k];
            int nx = x + dx[k];

            if(ny >= 1 && ny <= n && nx >= 1 &&  nx <= n){
                tree[ny][nx].push_back(1);
            }
        }
    }
    eTree.clear();
}

void winter(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            yang[i][j] += a[i][j];
}

int main(void){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &a[i][j]);
            yang[i][j] = 5;
        }
    }
    for(int i = 0; i < m; i++){
        int x, y, age;
        scanf("%d %d %d", &x, &y, &age);
        tree[x][y].push_back(age);
    }     

    while(k--){
        spring();
        summer();
        fall();
        winter();
        // debug();
    }

    int answer = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!tree[i][j].empty()){
                answer += tree[i][j].size();
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}