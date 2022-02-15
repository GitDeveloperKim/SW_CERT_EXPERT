#include <iostream>		// 표준 입출력 
#include <vector>		// vector 사용
#include <cstring>		// 
#include <algorithm>	// min, max
#include <map>			// map 사용 

using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	freopen("input.txt", "r", stdin);	// 제출시 제거
	
	// K <= N 
	int N; // 1 <= N <= 100_0000
	int K; // 1 <= K <= 10_0000
	long long* arr;
	long long left=1;
	long long mid=0;
	long long right=0;
	long long rope=0;

	cin >> K >> N;
	arr = new long long[K + 1];

	for (int i = 0; i < K; i++) {
		cin >> arr[i];
		if (right <= arr[i]) {
			right = arr[i]; // max 값 
		}
	}

	left = 1;
	mid = (right + left) / 2;

	while (left <= right) {
		rope = 0;
		for (int i = 0; i < K; i++) {
			rope += (arr[i] / mid);
		}
		if (rope >= N) {
			left = mid + 1; // 기준 늘리기 
		}
		else if (rope < N) {
			right = mid - 1;  // 기준 줄이기 
		}
		mid = (right + left) / 2;
	}
	cout << mid << endl;

	return 0;
}