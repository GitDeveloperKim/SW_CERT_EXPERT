#include <iostream>
using namespace std;

// k번째 수 
// 1300번
//https://st-lab.tistory.com/281

int main() {
    int N;
    int K; 
    cin >> N >> K;
    
    long long l = 1; 
    long long r = K;
    
    while (l < r) {
        long long count = 0;
        long long mid = (l+r)/2;
        
        for (int i=1; i <= N; i++) {
            count += (mid/i) < N ? mid/i: N;
        }
        
        if (K <= count) {
            r = mid;
        } else {
            l = mid+1;
        }
        
    }
    
    printf("%lld", l);
    
    return 0;
}