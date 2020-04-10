#include <string>
#include <vector>

#include <queue>
using namespace std;

bool check[20001] = { false, };
vector<int> e[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    for(auto vec : edge){
        e[vec[0]].push_back(vec[1]);
        e[vec[1]].push_back(vec[0]);
    }

    queue<int> q;
    check[1] = true;
    q.push(1);
    while(!q.empty()){
        int qSize = q.size();
        answer = qSize;
        while(qSize--){
            int curNode = q.front(); q.pop();
            
            for(int nextNode : e[curNode]){
                if(check[nextNode]) continue;

                check[nextNode] = true;
                q.push(nextNode);
            }
        }
    }
    return answer;
}