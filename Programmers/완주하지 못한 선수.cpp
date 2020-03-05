#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

map<string, int> m;

string solution(vector<string> participant, vector<string> completion) {
    for(auto s : participant){
        auto iter = m.find(s);
        if(iter != m.end()){
            iter->second++;
        }
        else{
            m.insert(make_pair(s, 1));
        }
    }
    
    for(auto s : completion){
        auto iter = m.find(s);
        iter->second--;
    }
    
    auto iter = m.begin();
    string answer = "";
    for(; iter != m.end(); iter++){
        if(iter->second != 0){
            answer = iter->first;
            break;
        }
    }
    
    return answer;
}