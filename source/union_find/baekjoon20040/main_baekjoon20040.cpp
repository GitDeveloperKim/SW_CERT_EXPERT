#include <iostream>		// ǥ�� ����� 
#include <vector>		// vector ���
#include <cstring>		// 
#include <algorithm>	// min, max
#include <map>			// map ��� 

using namespace std;

int* parent;
int find(int x) {
	if (x == parent[x]) {
		return x; // �ڱ��ڽ� 
	}
	else {
		return parent[x] = find(parent[x]);	// ����ȭ 
	}
}

void unionPoint (int x, int y) {
	// union �Լ� (merge)
	x = find(x);
	y = find(y);

	if (x != y) {
		parent[y] = x;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	freopen("input.txt", "r", stdin);	// ����� ����


	int n;	// ���� ���� 
	int m;	// ����� ������ �� 
	int answer = 0;

	cin >> n >> m;
	parent = new int[n + 1];

	for (int i = 0; i < n; i++) {
		parent[i] = i; // �ڱ� �ڽ� ����Ű�� 
	}

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		cnt++;
		int x, y;
		cin >> x >> y;

		if (find(x) != find(y)) {
			unionPoint(x, y); // �ٸ��� ��ġ�� 
		}
		else {
			answer = cnt;  // ������ ����Ŭ ����� 
			break;
		}
	}

	cout << answer;
	return 0;
}