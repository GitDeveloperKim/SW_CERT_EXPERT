#include <iostream>
using namespace std;

// 2559 
// 수열 
// 10 2
// 3 -2 -4 -9 0 3 7 13 8 -3
// 슬라이딩 윈도우 개념 확인 

int main() {
    int N; // 온도를 측정한 전체 날짜 수 
    int K; // 연속 날짜 수 1<= K <= N  
    cin >> N >> K;
    
    auto arr = new int [N+1];
    
    for (int i = 1; i <= N;i++) {
        cin >> arr[i];
    }

    int max = 0;
    
    for (int i = 1; i <= K; i++) {
        max += arr[i];
    }
    
    int temp = max;
    for (int i = K+1; i <= N; i++) {
        temp -= arr[i-K];
        temp += arr[i];
        if (max < temp) {
            max = temp;
        }
    }
    cout << max << endl;
    
    return 0;
}