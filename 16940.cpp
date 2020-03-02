#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'

bool check[100001] = { false, };
vector<int> edge[100001];
vector<int> answer;

int main(void){
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int n1, n2;
        cin >> n1 >> n2;
        edge[n1].push_back(n2);
        edge[n2].push_back(n1);
    }

    for(int i = 0; i < n; i++){
        int n1;
        cin >> n1;
        answer.push_back(n1);
    }

    if(answer.front() != 1){       
        cout << 0 << endl;
        return 0;
    }
    
    queue<int> q;
    q.push(1);
    check[1] = true;
    int ansIndex = 1;
    int incSize = 0;
    int childSize = 0;
    bool flag = false;
    int loopSize = 0;
    while(!q.empty()){
        int nextValue = q.front();
        loopSize++;

        if(!flag){
            for(int i = 0; i < edge[nextValue].size(); i++)
                if(!check[edge[nextValue][i]])
                    childSize++;
            
            flag = true;
        }

        for(int i = 0; i < edge[nextValue].size(); i++){ 
            if(edge[nextValue][i] == answer[ansIndex]){ 
                if(!check[edge[nextValue][i]]){
                    q.push(edge[nextValue][i]);
                    check[edge[nextValue][i]] = true;
                    ansIndex++;
                    incSize++;
                }
            }
        }

        if(incSize == childSize){
            q.pop();
            flag = false;
            childSize = 0;
            incSize = 0;
            loopSize = 0;
        }
        else if(loopSize > edge[nextValue].size()){
            cout << 0 << endl;
            return 0;
        }
    }

    if(ansIndex == n)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    
    return 0;
}