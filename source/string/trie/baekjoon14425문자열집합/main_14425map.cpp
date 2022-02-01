#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	freopen("input.txt", "r", stdin);	// 제출시 제거

	int N; // 문자열의 갯수 -> (keys)
	int M; // 검사 문자열 갯수 -> S{query_strings}
	cin >> N >> M;

	int answer = 0;
	map<string, bool> m;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		m[s] = true;
	}
	for (int i = 0; i < M; i++) {
		cin >> s;
		if (m[s]) answer++;
	}	
	cout << answer << endl;
	
	return 0;
}