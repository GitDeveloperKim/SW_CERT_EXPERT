#include <iostream>   // standard input output
#include <algorithm> // sort 
#include <cstring>

using namespace std;

int modpow (int x, int n, int m) {
    if (n == 0)
        return 1%m;
    long long u = modpow(x, n/2, m);
    u = (u*u)%m;
    if (n%2 == 1) 
        u = (u*x)%m;
    return u;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, n, m = 0; // x의 n 승을 m으로 나눈 나머지 
    cin >> x >> n >> m;
    
    cout << modpow(x, n, m); // logn의 시간 복잡도 
}