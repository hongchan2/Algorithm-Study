#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
#define endl '\n'
#define TEST cout << "TEST" << endl

vector<int> susic[10];
unordered_map<char, int> m;
int perms[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

int main(void){
    int n;
    cin >> n;

    int alphaCnt = 0;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int strSize = s.size();
        for(int j = 0; j < strSize; j++){
            auto iter = m.find(s[j]);
            if(iter == m.end()){
                // not found                
                m.insert(make_pair(s[j], alphaCnt));
                susic[i].push_back(alphaCnt);
                alphaCnt++;
            }
            else{
                susic[i].push_back(iter->second);
            }
        }
    }

    long long answer = -987654321;
    do{
        long long sum = 0;
        for(int i = 0; i < n; i++){
            long long temp = 0;
            for(auto num : susic[i]){
                long long next = 9 - perms[num];
                if(temp == 0){
                    temp = next;
                }
                else{
                    temp = (10 * temp) + next;
                }
            }
            sum += temp;
        }
        answer = max(answer, sum);
    }while(next_permutation(perms, perms + alphaCnt));
    
    cout << answer;
    return 0;
}