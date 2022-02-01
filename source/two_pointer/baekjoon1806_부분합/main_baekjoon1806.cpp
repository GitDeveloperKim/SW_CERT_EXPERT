#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX_NUM 1000000

using namespace std;

// ���� 1806
// https://rightbellboy.tistory.com/82

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	freopen("input.txt", "r", stdin);	// ����� ����

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
			len = min(len, high - low + 1);	// ������ ������ų���� ���� 
			sum -= arr[low++];
		}
	}

	// ������ �ϳ��� ���� ��Ű�� ���� ��� 0 ��� 
	cout << (len==MAX_NUM? 0:len) << endl;
	delete[] arr;
	return 0;
}