#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

// 백준 2565 전깃줄 
// https://hwan-shell.tistory.com/310

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	freopen("input.txt", "r", stdin);

	int N = 0; // 전깃줄 개수 <= 100
	vector<pair<int, int>> line; 
	int dp[102] = { 0, };
	int answer = 0;

	scanf("%d", &N);

	line.emplace_back(0, 0);
	for (int i = 0; i < N; i++) {
		int from = 0, to = 0;
		scanf("%d %d", &from, &to);
		line.emplace_back(from, to);
	}
	sort(line.begin(), line.end());

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			if (line[i].second > line[j].second) {
				if (dp[j] >= dp[i]) {
					dp[i] = dp[j] + 1;
				}
			}
		}
		answer = max(answer, dp[i]);
	}

	cout << N - answer << endl;
	return 0;
}