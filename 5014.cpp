#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

bool check[1000001] = { false, };

int main(void){
    int f, s, g, u, d;

    cin >> f >> s >> g >> u >> d;

    queue<int> q;
    q.push(s);
    check[s] = true;
    int answer = 0;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            int cFloor = q.front(); q.pop();

            if(cFloor == g){
                cout << answer << endl;
                return 0;
            }

            // up
            int nFloor = cFloor + u;
            if(nFloor <= f && !check[nFloor]){
                check[nFloor] = true;
                q.push(nFloor);
            }

            // down
            nFloor = cFloor - d;
            if(nFloor > 0 && !check[nFloor]){
                check[nFloor] = true;
                q.push(nFloor);
            }
        }
        answer++;
    }

    cout << "use the stairs" << endl;


    return 0;
}