#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
#define PLUS 0
#define MINUS 1
#define MUL 2
#define DIV 3

using namespace std;

int n;
int num[11];
vector<int> operVector;
vector<int> v;
vector<int>::iterator iter;

int maxValue = -2000000000;
int minValue = 2000000000;

void calculate(){
    int sum = num[0];
    for(int i = 1; i < n; i++){
        switch(operVector[v[i - 1]]){
            case PLUS:
                sum += num[i];
                break;
            case MINUS:
                sum -= num[i];
                break;
            case MUL:
                sum *= num[i];
                break;
            case DIV:
                sum /= num[i];
                break;
        }
    }
    maxValue = max(maxValue, sum);
    minValue = min(minValue, sum);
}

void dfs(int n, int m){
    if(m == 0){
        calculate();
        return;
    }

    for(int i = 0; i < n; i++){
        iter = find(v.begin(), v.end(), i);
        if(iter == v.end()){
            v.push_back(i);
            dfs(n, m - 1);
            v.pop_back();
        }
    }
}

int main(void){
    int oper[4];    // + - * /
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> num[i];
    cin >> oper[0] >> oper[1] >> oper[2] >> oper[3];

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < oper[i]; j++)
            operVector.push_back(i);

    dfs(n - 1, n - 1);

    cout << maxValue << endl << minValue << endl;

    return 0;
}