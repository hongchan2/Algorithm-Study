#include <iostream>
#include <deque>

using namespace std;
#define endl '\n'
#define TEST cout << "TEST" << endl;
#define JIWOO 0
#define KYUNGHEE 1
#define MINHO 2

int n, k;
int map[10][10] = { 0, };
deque<int> kyunghee;
deque<int> minho;
int dfsFlag = false;

void dfs(deque<bool> j_current, int k_index, int m_index, int o1, int o2, int wait, int jiwooCnt, int kyungheeCnt, int minhoCnt){
    if(dfsFlag)
        return;
    
    if(j_current.empty() || jiwooCnt == k || kyungheeCnt == k || minhoCnt == k){
        if(jiwooCnt == k)
            dfsFlag = true;
        return;
    }
    
    if(o1 == JIWOO){
        deque<bool> j_next = j_current;
        for(int i = 1; i <= n; i++){
            if(j_next[i]){
                j_next[i] = false;
                int next = 0;

                if(o2 == KYUNGHEE){
                    next = kyunghee[k_index];
                    if(map[i][next] == 2){
                        // JIWOO win
                        dfs(j_next, k_index + 1, m_index, JIWOO, wait, KYUNGHEE, jiwooCnt + 1, kyungheeCnt, minhoCnt);
                    } 
                    else{
                        // JIWOO draw, lose
                        dfs(j_next, k_index + 1, m_index, KYUNGHEE, wait, JIWOO, jiwooCnt, kyungheeCnt + 1, minhoCnt);
                    }
                }
                else if(o2 == MINHO){
                    next = minho[m_index];
                    if(map[i][next] == 2){
                        // JIWOO win
                        dfs(j_next, k_index, m_index + 1, JIWOO, wait, MINHO, jiwooCnt + 1, kyungheeCnt, minhoCnt);
                    } 
                    else{
                        // JIWOO draw, lose
                        dfs(j_next, k_index, m_index + 1, wait, MINHO, JIWOO, jiwooCnt, kyungheeCnt, minhoCnt + 1);
                    }
                }
                j_next[i] = true;
            }
        }
    }
    else{
        // o1 == KYUNGHEE / o2 == MINHO
        int k_next = kyunghee[k_index];
        int m_next = minho[m_index];

        if(map[k_next][m_next] == 2){
            // KYUNGHEE win
            dfs(j_current, k_index + 1, m_index + 1, wait, KYUNGHEE, MINHO, jiwooCnt, kyungheeCnt + 1, minhoCnt);
        }
        else{
            // KYUNGHEE draw, lose
            dfs(j_current, k_index + 1, m_index + 1, wait, MINHO, KYUNGHEE, jiwooCnt, kyungheeCnt, minhoCnt + 1);
        }
    }
}

int main(void){
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> map[i][j];
    
    deque<bool> jiwoo(10, false);
    for(int i = 1; i <= n; i++)
        jiwoo[i] = true;
    for(int i = 0; i < 20; i++){
        int n1;
        cin >> n1;
        kyunghee.push_back(n1);
    }
    for(int i = 0; i < 20; i++){
        int n1;
        cin >> n1;
        minho.push_back(n1);
    }

    dfs(jiwoo, 0, 0, JIWOO, KYUNGHEE, MINHO, 0, 0, 0);
    
    if(dfsFlag)
        cout << 1;
    else
        cout << 0;
    return 0;
}