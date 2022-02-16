#include <iostream>		// 표준 입출력 
#include <vector>		// vector 사용
#include <cstring>		// 
#include <algorithm>	// min, max
#include <map>			// map 사용 

using namespace std;

int* parent;
int find(int x) {
	if (x == parent[x]) {
		return x; // 자기자신 
	}
	else {
		return parent[x] = find(parent[x]);	// 최적화 
	}
}

void unionPoint (int x, int y) {
	// union 함수 (merge)
	x = find(x);
	y = find(y);

	if (x != y) {
		parent[y] = x;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	freopen("input.txt", "r", stdin);	// 제출시 제거


	int n;	// 점의 갯수 
	int m;	// 진행된 차례의 수 
	int answer = 0;

	cin >> n >> m;
	parent = new int[n + 1];

	for (int i = 0; i < n; i++) {
		parent[i] = i; // 자기 자신 가리키기 
	}

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		cnt++;
		int x, y;
		cin >> x >> y;

		if (find(x) != find(y)) {
			unionPoint(x, y); // 다르면 합치고 
		}
		else {
			answer = cnt;  // 같으면 사이클 생긴것 
			break;
		}
	}

	cout << answer;
	return 0;
}