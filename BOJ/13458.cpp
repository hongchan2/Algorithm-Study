#include <cstdio>

using namespace std;
#define endl '\n'
#define TEST cout << "TEST" << endl;

int n;
int a[1000001] = { 0, };
int b, c;

int main(void){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d %d", &b, &c);

    long long answer = 0;
    for(int i = 0; i < n; i++){
        a[i] -= b; answer++;
        if(a[i] > 0){
            int sub = 0;
            sub = a[i] / c;
            if((a[i] % c) != 0){
                sub++;
            }
            answer += sub;
        }
    }
    
    printf("%lld", answer);
    return 0;
}