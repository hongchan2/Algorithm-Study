#include <vector>
#include <unordered_map>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    unordered_map<long long, long long> m;
    
    for(long long num : room_number){
        vector<long long> visit_list;
        auto iter = m.find(num);
        
        if(iter == m.end()){
            m.insert(make_pair(num, 0));
            answer.push_back(num);
        }
        else{
            visit_list.push_back(num);
            long long i = num + 1;

            if(iter->second != 0) i += iter->second;

            for(; i <= k; i++){
                iter = m.find(i);

                if(iter != m.end()){
                    visit_list.push_back(i);
                    if(iter->second != 0) i += iter->second;

                    continue;
                }
                
                m.insert(make_pair(i, 0));
                for(long long value : visit_list){
                    m[value] = i - value;
                }
                answer.push_back(i);
                break;
            }
        }
    }

    return answer;
}