#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int num;
int arr[26][26] = { 0, };
int danji[26][26] = { 0, };
int y[] = { -1, 0, 1, 0}; 
int x[] = { 0, 1, 0, -1};

void dfs(int i, int j, int sum){
    danji[i][j] = sum;

    for(int k = 0; k < 4; k++){
        int newY = i + y[k];
        int newX = j + x[k];

        if(newY >= 0 && newY < num && newX >= 0 && newX < num){
            if(arr[newY][newX] == 1 && danji[newY][newX] == 0){
                dfs(newY, newX, sum);
            }
                
        }
    }
}

int main(void){
    int sum = 0;
    scanf("%d", &num);

    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            scanf("%1d", &arr[i][j]);
        }
    }

    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            // 집이 있고, 방문 안했으면 search 
            if(arr[i][j] == 1 && danji[i][j] == 0){
                sum++;
                dfs(i, j, sum);
            }
        }
    }

    printf("%d\n", sum);
    vector<int> v;
    for(int i = 1; i <= sum; i++){
        int danjiSum = 0;
        for(int j = 0; j < num; j++){
            for(int k = 0; k < num; k++){
                if(danji[j][k] == i)
                    danjiSum++;
            }
        }
        v.push_back(danjiSum);
    }

    sort(v.begin(), v.end());
    for(int n : v){
        printf("%d\n", n);
    }

    return 0;
}