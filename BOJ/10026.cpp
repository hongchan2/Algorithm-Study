#include <iostream>
#include <cstdio>

#define NORMAL 0
#define REDGREEN 1

using namespace std;

char arr[101][101] = { 0, };
bool check[101][101] = { false, };
bool checkRedGreen[101][101] = { false, };
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int num;

void dfs(int row, int col, int flag){
    if(flag == NORMAL)
        check[row][col] = true;
    else if(flag == REDGREEN)
        checkRedGreen[row][col] = true;

    for(int i = 0; i < 4; i++){
        int newRow = row + dy[i];
        int newCol = col + dx[i];
        
        if(newRow >= 0 && newRow < num && newCol >= 0 && newCol < num){
            if(flag == NORMAL){
                if(arr[row][col] == arr[newRow][newCol] && !check[newRow][newCol])
                    dfs(newRow, newCol, flag);
            }
            else if(flag == REDGREEN){
                if(!checkRedGreen[newRow][newCol]){
                    if((arr[row][col] == arr[newRow][newCol]) ||
                    (arr[row][col] == 'R' && arr[newRow][newCol] == 'G') ||
                    (arr[row][col] == 'G' && arr[newRow][newCol] == 'R'))
                        dfs(newRow, newCol, flag);
                }   
            }
        }  
    }
}

int main(void){
    scanf("%d", &num);
    
    for(int i = 0; i < num; i++){
        scanf("%s", arr[i]);
    }

    int normalSum = 0;
    int redGreenSum = 0;
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            if(!check[i][j]){
                dfs(i, j, NORMAL);
                normalSum++;
            }

            if(!checkRedGreen[i][j]){
                dfs(i, j, REDGREEN);
                redGreenSum++;
            }
        }
    }
    
    printf("%d %d\n", normalSum, redGreenSum);

    return 0;
}