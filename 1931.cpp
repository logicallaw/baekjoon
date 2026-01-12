#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> V;

    for (int i = 0; i < N; i++) {
        int st, end;
        cin >> st >> end;

        V.emplace_back(end, st);
    }

    sort(V.begin(), V.end());

    int cnt = 1;
    int curr = V.front().first;

    for (int i = 1; i < N; i++) {
        if (curr <= V[i].second) {
            curr = V[i].first;
            cnt++;
        }
    }
    cout << cnt;
}

/*
첫 번째 접근 (시간초과): N^2으로 Greedy하게 p와 q가 작은 값을 선택해서 탐색하는 방법으로 풀이함
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    for (int i = 0; i < N; i++) {
        int st, end;
        cin >> st >> end;
        PQ.emplace(st, end);
    }

    int ans = 0;
    int cnt = 0;
    while (!PQ.empty()) {
        pair<int, int> TOP = PQ.top();
        PQ.pop();

        cnt = 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> COPY = PQ;
        int curr = TOP.second;

        while (!COPY.empty()) {
            pair<int, int> TOPP = COPY.top();
            COPY.pop();
            if (curr > TOPP.first) {
                continue;
            }
            curr = TOPP.second;
            cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}
두 번째 접근 (시간초과): 이미 한 연산은 안하도록 하는데도, N^2 때문에 시간초과가 발생하는 듯
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ, COPY;
    vector<int> V;
    unordered_map<int, int> UM;
    for (int i = 0; i < N; i++) {
        int st, end;
        cin >> st >> end;
        PQ.emplace(st, end);
    }

    int ans = 0;
    int cnt = 0;
    while (!PQ.empty()) {
        V.clear();

        pair<int, int> P = PQ.top();
        PQ.pop();

        cnt = 1;
        COPY = PQ;
        int curr = P.second;
        V.push_back(curr);

        while (!COPY.empty()) {
            if (UM.find(curr) != UM.end()) {
                cnt += UM[curr];
                break;
            }

            pair<int, int> C = COPY.top();
            COPY.pop();

            if (curr > C.first) {
                continue;
            }
            cnt++;
            curr = C.second;
            V.push_back(curr);
        }
        ans = max(ans, cnt);

        for (auto& ele : V) {
            cnt--;
            UM[ele] = cnt;
        }
    }
    cout << ans;
}
세 번째 접근(정답 확인함):
- 나의 오해: 모든 것을 확인해야할 줄 앎
- 정답: 정말로 Greedy하게만 선택하면 풀림. 다 확인할 필요 없이.. 이런게 Greedy 알고리즘 문제인가?
 */