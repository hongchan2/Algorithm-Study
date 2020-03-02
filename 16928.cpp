#include <iostream> 
#include <queue>

using namespace std;

#define endl '\n'

int board[101] = { 0, };
bool check[101] = { 0, };
int n, m;

int main(void){
    cin >> n >> m;
    for(int i = 0; i < n + m; i++){
        int num;
        cin >> num;
        cin >> board[num];
    }

    queue<int> q;
    q.push(1);
    int answer = 0;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            int cur = q.front(); q.pop();

            if(cur == 100){
                while(!q.empty())
                    q.pop();
                break;
            }

            for(int i = 1; i <= 6; i++){
                int next = cur + i;

                if(!check[next] && next <= 100){
                    if(board[next])
                        next = board[next];
                    
                    // cout << next << " ";
                    check[next] = true;
                    q.push(next);
                }
            }
        }
        answer++;
    }

    cout << --answer << endl;
    return 0;
}