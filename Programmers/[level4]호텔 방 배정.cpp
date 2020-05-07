#include <vector>
#include <unordered_map>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    // current, parent
    unordered_map<long long, long long> m;
    
    for(long long num : room_number){
        vector<long long> visit_list;
        auto iter = m.find(num);
        
        if(iter == m.end()){
            m.insert(make_pair(num, num + 1));
            answer.push_back(num);
        }
        else{
            visit_list.push_back(num);

            long long i = iter->second;

            while(true){
                iter = m.find(i);

                if(iter != m.end()){
                    visit_list.push_back(i);
                    i = iter->second;

                    continue;
                }
                
                m.insert(make_pair(i, i + 1));
                for(int value : visit_list){
                    m[value] = i;
                }
                answer.push_back(i);
                break;
            }
        }
    }

    return answer;
}