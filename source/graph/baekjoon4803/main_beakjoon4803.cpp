#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// 백준 4803 
// reference -> https://mapocodingpark.blogspot.com/2020/05/4803.html
int n;	// 노드 
int m;	// 인덱스 
vector<int> adj[505];
bool isVisited[505];

bool isTree(int currentNode, int beforeNode) {	
	isVisited[currentNode] = true;

	for (auto nextNode : adj[currentNode]) {
		if (nextNode == beforeNode) // 사이클 판정이 아닌 이전 노드 정보 
			continue;
		if (isVisited[nextNode]) // 사이클 판정 
			return false;
		if (isTree(nextNode, currentNode) == false) {
			return false;
		}
			
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	int testCase = 0;

	while (1) {
		testCase++;
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)
			break;

		int answer = 0;
		memset(isVisited, false, sizeof(isVisited));
		for (int i = 0; i < 505; i++) {
			adj[i].clear();
		}

		for (int i = 0; i < m; i++) {
			int from, to;
			scanf("%d %d", &from, &to);

			adj[from].push_back(to);
			adj[to].push_back(from);
		}

		for (int i = 1; i <= n; i++) {
			if (isVisited[i] == true)
				continue;
			if (isTree(i, 0))
				answer++;
		}
		//cout << answer << endl;
		if (answer > 1) {
			cout << "Case " << testCase << ": A forest of "<<  answer <<" trees.\n";
		}
		else if (answer == 1) {
			cout << "Case " << testCase << ": There is one tree.\n";
		}
		else {
			cout << "Case " << testCase << ": No trees.\n";
		}
	}

	return 0;
}