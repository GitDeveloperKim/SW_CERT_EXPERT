#include <iostream>
#define MOD 1000000000
using namespace std;

// 참고 https://ssinee.tistory.com/37
int main() {
    int N = 0;
    scanf("%d", &N);
    
    // 0 행은 안쓰임 
    auto arr = new int[N+1][10];
    
    for (int j = 0; j <= N; j++) {
        for (int i = 0; i < 10; i++) {
            arr[j][i] = 0;
        }
    }
    
    // base number 
    for (int i = 1; i < 10; i++) {
        arr[1][i] = 1;
    }
    
    // j 자릿수, i 끝자리 숫자 
    for (int j = 2;  j <= N ; j++) {
        for (int i = 0; i < 10; i++) {
            if (i == 0) {
                // 끝자리가 0일 경우  
                arr[j][i] = arr[j-1][i+1];
            } else if (i == 9) {
                // 끝자리가 9일 경우 
                arr[j][i] = arr[j-1][i-1];
            } else {
                // 끝자리가 0이나 9가 아닐 경우 
                arr[j][i] = (arr[j-1][i-1] + arr[j-1][i+1]) % MOD;
            }
        }
    }
    
    int answer = 0;
    for (int i = 0; i < 10; i++) {
        answer = (answer + arr[N][i]) % MOD;
    }
    
    printf("%d\n", answer);
    
    
    
    return 0;
}