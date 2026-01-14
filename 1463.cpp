#include <iostream>
#include <queue>

using namespace std;

bool visited[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    queue<pair<int, int>> Q;

    Q.emplace(N, 0);


    while (!Q.empty()) {
        pair<int, int> T = Q.front();
        Q.pop();
        visited[T.first] = true;
        if (T.first < 1) continue;

        if (T.first == 1) {
            cout << T.second;
            break;
        }

        if (T.first % 3 == 0 && !visited[T.first / 3]) {
            //cout << T.first / 3 << " " << T.second + 1 << "\n";
            Q.emplace(T.first / 3, T.second + 1);
        }
        if (T.first % 2 == 0 && !visited[T.first / 2]) {
            //cout << T.first / 2 << " " << T.second + 1 << "\n";
            Q.emplace(T.first / 2, T.second + 1);
        }
        if (!visited[T.first - 1]) {
            //cout << T.first - 1 << " " << T.second + 1 << "\n";
            Q.emplace(T.first - 1, T.second + 1);
        }
    }

}