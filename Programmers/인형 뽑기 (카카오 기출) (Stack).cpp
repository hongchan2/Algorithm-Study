#include <iostream>
#include <stack>
#include <vector>

using namespace std;
#define endl '\n'
#define TEST cout << "TEST" << endl;

int n;
int m;
int answer = 0;
vector<int> board[31];
vector<int> moves;

int main(void){
    cin >> n;
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            int n1;
            cin >> n1;
            board[i].push_back(n1);
        }
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        int n2;
        cin >> n2;
        moves.push_back(n2);
    }
    
    stack<int> s;
    for(int loc : moves){
        int find = 0;

        for(int i = n - 1; i >= 0; i--){
            if(board[i][loc - 1] == 0) continue;
            
            find = board[i][loc - 1];
            board[i][loc - 1] = 0;
            break;
        }

        // cout << find << endl;
        if(find == 0) continue;

        if(s.empty()){
            s.push(find);
            continue;
        }

        if(s.top() == find){
            answer += 2;
            s.pop();
        }
        else{
            s.push(find);
        }
    }

    cout << answer;
    return 0;
}