#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 나이트의 8가지 이동 방향
const int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
const int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

// BFS 탐색을 위한 함수
void bfs(vector<vector<int>>& board, vector<vector<int>>& result, int startX, int startY, int n) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    result[startX][startY] = 1;  // 시작 위치를 이동 가능한 위치로 표시

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 8가지 방향으로 이동
        for (int i = 0; i < 8; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            // 체스판의 범위 내에 있는지 확인
            if (newX >= 0 && newX < n && newY >= 0 && newY < n) {
                // 해당 위치에 말이 없고, 방문하지 않았으면
                if (board[newX][newY] == 0 && result[newX][newY] == 0) {
                    q.push({newX, newY});
                    result[newX][newY] = 1;
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    // 체스판과 결과를 저장할 2차원 벡터
    vector<vector<int>> board(n, vector<int>(n));
    vector<vector<int>> result(n, vector<int>(n, 0));

    // 체스판 입력
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    // 나이트의 시작 위치 입력
    int r, c;
    cin >> r >> c;
    --r; // 1-based to 0-based index
    --c; // 1-based to 0-based index

    // BFS 탐색 실행
    bfs(board, result, r, c, n);

    // 결과 출력
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}