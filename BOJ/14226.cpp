#include <iostream>
#include <queue>

using namespace std;

bool check[9001][9001] = { { false, } , };

int main(void){
    int s;
    cin >> s;

    // screen / clipboard
    queue<pair<int, int> > q;
    q.push(make_pair(1, 0));
    check[1][0] = true;
    int answer = 0;

    while(!q.empty()){
        int size = q.size();

        while(size--){
            int screen = q.front().first;
            int clipboard = q.front().second;
            q.pop();

            if(screen == s){
                while(!q.empty()){
                    q.pop();
                }
                break;
            }    

            int nextScreen;
            int nextClipboard; 

            // 1. copy to clipboard
            nextScreen = screen;
            nextClipboard = screen;
            if(!check[nextScreen][nextClipboard]){
                q.push(make_pair(nextScreen, nextClipboard));
                check[nextScreen][nextClipboard] = true;
            }

            // 2. paste to screen
            if(clipboard > 0){
                nextScreen = screen + clipboard;
                nextClipboard = clipboard;
                if(!check[nextScreen][nextClipboard]){
                    q.push(make_pair(nextScreen, nextClipboard));
                    check[nextScreen][nextClipboard] = true;
                }
            }
            
            // 3. delete
            if(screen > 0){
                nextScreen = screen - 1;
                nextClipboard = clipboard;
                if(!check[nextScreen][nextClipboard]){
                    q.push(make_pair(nextScreen, nextClipboard));
                    check[nextScreen][nextClipboard] = true;
                }
            }
        }
        answer++;
    }
    cout << --answer << '\n';

    return 0;
}