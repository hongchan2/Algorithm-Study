#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> v;

void printVector(vector<int>& vec){
    for(auto num : vec)
        printf("%d ", v[num]);
    printf("\n");
}

// nCm
void comb(int n, int m, vector<int>& vec){
    if(m == 0){
        printVector(vec);
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
    int k;

    while(true){
        scanf("%d", &k);
        if(k == 0)
            break;
        
        for(int i = 0; i < k; i++){
            int num;
            scanf("%d", &num);
            v.push_back(num);
        }

        vector<int> vec;
        // kC6
        comb(k, 6, vec);

        printf("\n");
        v.clear();
    }
    return 0;
}