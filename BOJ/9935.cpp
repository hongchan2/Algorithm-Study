#include <iostream>

using namespace std;
#define endl '\n'
#define TEST cout << TEST << endl

int main(void){
    string s, p;
    cin >> s >> p;
    int sSize = s.size();
    int pSize = p.size();
    
    char c[1000001] = { 0, }; 
    int cIndex = 0;
    for(int i = 0; i < sSize; i++){
        if(s[i] == p.back()){
            int j = 0;
            int tempCIndex = cIndex - 1;
            for(j = pSize - 2; j >= 0;){
                if(tempCIndex < 0)
                    break;
                
                if(c[tempCIndex] != p[j])
                    break;
                
                tempCIndex--; j--;
            }

            if(j == -1){
                // bomb
                cIndex -= pSize - 1;
            }
            else{
                c[cIndex] = s[i];
                cIndex++;
            }
        }
        else{
            c[cIndex] = s[i];
            cIndex++;
        } 
    }
    if(cIndex == 0)
        cout << "FRULA" << endl;
    else{
        for(int i = 0; i < cIndex; i++)
            cout << c[i];
        cout << endl;
    }
    
    return 0;
}