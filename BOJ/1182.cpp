#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> v;
int cnt = 0;
int s;

void checkVector(vector<int>& vec){
    int sum = 0;
    
    for(auto num : vec)
        sum += v[num];

    if(sum == s)
        cnt++;
}

// nCm
void comb(int n, int m, vector<int>& vec){
    if(m == 0){
        checkVector(vec);
        return;
    }

    int nextValue = vec.empty() ? 0 : vec.back() + 1;
    for(int next = nextValue; next < n; next++){
        vec.push_back(next);
        comb(n, m - 1, vec);
        vec.pop_back();
    }
}

int main(void){
    int n;
    scanf("%d %d", &n, &s);

    for(int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);
        v.push_back(num);
    }

    vector<int> vec;
    for(int i = 1; i <= n; i++){
        // nCi
        comb(n, i, vec);
    }

    printf("%d\n", cnt);
    return 0;
}