#include <iostream>

using namespace std;
#define endl '\n'
#define TEST cout << "TEST" << endl

int main(void){
    char s[1000001] = { 0, };
    char p[1000001] = { 0, };
    cin >> s >> p;
    
    if(strstr(s, p) != NULL)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}