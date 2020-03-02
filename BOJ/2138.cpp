#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>


using namespace std;

int num;
vector<int> v;
vector<int> target;
queue<vector<int> > q;


void debug(vector<int>& arr){
    for(auto num : arr)
        cout << num << " ";
    cout << endl;
}

int returnValue(int num){
    if(num == 1)
        return 0;
    else if(num == 0)
        return 1;
    else{
        cout << "error" << '\n';
        return 0;
    }
}

vector<int> pushButton(vector<int> v, int index){
    if(index == 0){
        v[index] = returnValue(v[index]);
        v[index + 1] = returnValue(v[index + 1]);
    }
    else if(index == (num  - 1)){
        v[index - 1] = returnValue(v[index - 1]);
        v[index] = returnValue(v[index]);
    }
    else{
        v[index - 1] = returnValue(v[index - 1]);
        v[index] = returnValue(v[index]);
        v[index + 1] = returnValue(v[index + 1]);
    }

    return v;
}

bool comp(vector<int>& a, vector<int>& b){
    for(int i = 0; i < num; i++){
        if(a[i] != b[i])
            return false;
    }
    return true;
}

int main(void){
    scanf("%d", &num);

    for(int i = 0; i < num; i++){
        int n;
        scanf("%1d", &n);
        v.push_back(n);
    }
    for(int i = 0; i < num; i++){
        int n;
        scanf("%1d", &n);
        target.push_back(n);
    }

    q.push(v);
    int answer = 0;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            vector<int> vec = q.front(); q.pop();

            //debug(vec);
            //debug(target);

            if(comp(vec, target)){
                while(!q.empty())
                    q.pop();
                cout << answer << '\n';
                return 0;
            }

            // 3가지
            for(int i = 0; i < num; i++){
                q.push(pushButton(vec, i));
            }
        }
        answer++;
    }

    return 0;
}