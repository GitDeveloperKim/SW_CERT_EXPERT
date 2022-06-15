#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = 0;
    int N = 0; // 1 <= N <= 100 
    cin >> T;

    for (int test_case = 0; test_case < T; test_case++) {
        cin >> N;
        unsigned long long arr[101];
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;
        arr[3] = 1;

        for (int i = 4; i <= 100; i++) {
            arr[i] = arr[i - 2] + arr[i - 3];
        }

        cout << arr[N] << endl;   
    }
    

    return 0;
}