#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

queue<pair<int, int> > q;
bool check[100001] = { false, };

void nextSubin(int subin, int sec){
    if(subin - 1 >= 0)
        if(!check[subin - 1]){
            q.push(make_pair(subin - 1, sec));
            check[subin - 1] = true;
        }
        
    if(subin + 1 <= 100000)
        if(!check[subin + 1]){
            q.push(make_pair(subin + 1, sec));
            check[subin + 1] = true;
        }

    if(2 * subin <= 100000)
        if(!check[2 * subin]){
            q.push(make_pair(2 * subin, sec));
            check[2 * subin] = true;
        }
}

int main(void){
    int subin, dong;
    scanf("%d %d", &subin, &dong);
 
    check[subin] = true;
    q.push(make_pair(subin, 0));
    while(!q.empty()){
        pair<int, int> p = q.front(); q.pop();
        int currentSubin = p.first;
        int currentSec = p.second;

        if(currentSubin == dong){
            //  find
            printf("%d\n", currentSec);
            break;
        }
        else{
            nextSubin(currentSubin, ++currentSec);
        }
    }
    return 0;
}