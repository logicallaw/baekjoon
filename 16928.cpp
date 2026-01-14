/*
첫 번째 접근:
가장 높이 올라갈 수 있는 사다리를 선택해서 올라간다.
올라간 후로는 뱀을 통해 내려가선 안된다.
주사위를 한 번 더 굴리더라도 내려가는 길은 선택하지 않는다.

올라갈 때는 사다리를 적극 활용해서 최소 주사위 횟수로 올라가야한다.

-- 정답 확인 --
새롭게 알게 된 점:
- 주사위 횟수 => BFS 깊이
- BFS 알고리즘은 O(V+E), O(V^2)임. 시간 충분함
  - 이 문제에선 700 연산 수행함.
 */
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

bool visited[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    unordered_map<int, int> UM;

    int cnt = N + M;
    while (cnt--) {
        int x, y;
        cin >> x >> y;
        UM.insert({x, y});
    }

    queue<pair<int, int>> Q;
    Q.emplace(1, 0);


    int ans = 0;
    while (!Q.empty()) {
        pair<int, int> F = Q.front();
        visited[F.first] = true;
        Q.pop();

        if (F.first == 100) {
            ans = F.second;
            break;
        }

        for (int i = 1; i <= 6; i++) {
            int NE = F.first + i;
            if (NE > 100) continue;
            if (visited[NE]) continue;
            if (UM.find(NE) != UM.end()) NE = UM[NE];
            Q.emplace(NE, F.second + 1);
        }
    }

    cout << ans;
}