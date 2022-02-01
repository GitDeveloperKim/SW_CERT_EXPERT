#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX_NUM 1000000

using namespace std;

// 백준 1806
// https://rightbellboy.tistory.com/82

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	freopen("input.txt", "r", stdin);	// 제출시 제거

	int N, S;
	int low = 1, high = 1;
	int sum = 0;
	int len = MAX_NUM;
	
	scanf("%d %d", &N, &S);

	int* arr = new int[N + 2];
	memset(arr, 0, sizeof(int)*(N+2));
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	sum = arr[1];
	while (low <= high && high <= N) {
		if (sum < S) {
			sum += arr[++high];
		}
		else {
			len = min(len, high - low + 1);	// 조건을 만족시킬때만 갱신 
			sum -= arr[low++];
		}
	}

	// 조건을 하나도 만족 시키지 못할 경우 0 출력 
	cout << (len==MAX_NUM? 0:len) << endl;
	delete[] arr;
	return 0;
}