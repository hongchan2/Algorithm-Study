#include <iostream>

using namespace std;

#define endl '\n'
#define UP 0
#define LEFT 1
#define RIGHT 2

int main(void){
    int testCase = 10;
    while(testCase--){
        int num;
        int board[101][101] = { 0, };
        cin >> num;

        int dx;
        for(int i = 1; i <= 100; i++){
            for(int j = 1; j <= 100; j++){
                int n;
                cin >> n;
                board[i][j] = n;
                if(n == 2)
                    dx = j;
            }
        }

        int cy = 100;
        int cx = dx;
        int cd = UP;
        while(cy != 1){
            // move
            switch(cd){
                case UP:
                    if(cx - 1 >= 1 && board[cy][cx - 1]){
                        cx -= 1;
                        cd = LEFT;
                    }
                    else if(cx + 1 <= 100 && board[cy][cx + 1]){
                        cx += 1;
                        cd = RIGHT;
                    }
                    else{
                        cy -= 1;
                    }
                    break;
                case LEFT:
                    if(board[cy - 1][cx]){
                        cy -= 1;
                        cd = UP;
                    }
                    else{
                        cx -= 1;
                    }
                    break;
                case RIGHT:
                    if(board[cy - 1][cx]){
                        cy -= 1;
                        cd = UP;
                    }
                    else{
                        cx += 1;
                    }
                    break;
            }
        }
 
        cout << "#" << num << " " << cx - 1 << endl;
    }

    return 0;
}