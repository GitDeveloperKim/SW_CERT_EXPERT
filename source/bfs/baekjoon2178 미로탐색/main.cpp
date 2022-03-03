#include <iostream>
#include <queue>

using namespace std;

int N, M;
char arr[101][101] = { 0, };
bool isVisited[101][101] = { false, };
int dp[101][101] = { 0, };
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void BFS(int x, int y) {
    isVisited[y][x] = true;
    queue <pair<int,int>> q;
    q.push(make_pair(0, 0));
    dp[y][x] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if (next_x <0 || next_x >= M || next_y < 0 || next_y >= N) {
                continue;
            }
            if (arr[next_y][next_x] == '0') {
                continue;
            }
            if (isVisited[next_y][next_x] == true) {
                continue;
            }
            isVisited[next_y][next_x] = true;
            q.push(make_pair(next_x, next_y));
            dp[next_y][next_x] = dp[y][x] + 1;
        }
        
    }

}

int main(int argc, char* argv[]) {
    scanf("%d %d", &N, &M); // За·Д
    for (int i = 0; i < N; i++) {
        scanf("%s", arr[i]);
    }
    BFS(0, 0);
    cout << dp[N-1][M-1] << endl;

    return 0;
}