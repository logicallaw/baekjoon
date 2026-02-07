#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int arr[101][101][101];

int M, N, H;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

bool isRange(int a, int b) {
    return (0 <= a && a < b);
}

bool canGo(int z, int x, int y) {
    return (isRange(z, H) && isRange(x, N) && isRange(y, M));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N >> H;

    int R = 0;

    queue<tuple<int, int, int, int>> Q;

    for (int z = 0; z < H; z++) {
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < M; y++) {
                int a;
                cin >> a;
                arr[z][x][y] = a;
                if (a == 0) R++;
                if (a == 1) Q.push({z, x, y, 0});
            }
        }
    }

    int result = 0;
    while (!Q.empty()) {
        auto F = Q.front();
        Q.pop();
        int z = get<0>(F);
        int x = get<1>(F);
        int y = get<2>(F);
        int day = get<3>(F);
        // cout << x << " " << y << " " << z << " " << day << "\n";

        if (result < day) result = day;

        for (int i = 0; i < 6; i++) {
            int nz = dz[i] + z;
            int nx = dx[i] + x;
            int ny = dy[i] + y;

            if (!canGo(nz, nx, ny)) continue;
            if (arr[nz][nx][ny] == 1 || arr[nz][nx][ny] == -1) continue;
            
            arr[nz][nx][ny] = 1;
            Q.push({nz, nx, ny, day + 1});
            R--;
        }
    }

    if (R == 0) {
        cout << result << '\n';
    } else {
        cout << "-1\n";
    }
}