#include <iostream>
#include <cstring>

using namespace std;
#define endl '\n'
#define TEST cout << "TEST" << endl;

int n;
int map[101] = { 0, };

int main(void){
    cin >> n;
    memset(map, -1, sizeof(map));
    
    int cow, loc;
    int answer = 0;
    while(n--){
        cin >> cow >> loc;
        if(map[cow] == -1){
            map[cow] = loc;
        }
        else if(map[cow] != loc){
            answer++;
            map[cow] = loc;
        }
    }

    cout << answer;
    return 0;
}