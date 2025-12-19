#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> V(N, 0);

    priority_queue<tuple<int, int, int>> PQ;
    priority_queue<tuple<int, int, int>> TMP;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        PQ.emplace(x, y, i);
    }

    int rank = 1;
    int cnt = 0;

    while (!PQ.empty()) {
        rank += cnt;
        cnt = 1;

        tuple<int, int, int> FIRST = PQ.top();
        //cout << "FIRST: " << get<0>(FIRST) << "," << get<1>(FIRST) << "," << get<2>(FIRST) << "\n";
        PQ.pop();

        V[get<2>(FIRST)] = rank;

        while (!PQ.empty()) {
            tuple<int, int, int> TOP = PQ.top();
            //cout << "FIRST: " << get<0>(TOP) << "," << get<1>(TOP) << "," << get<2>(TOP) << "\n";
            PQ.pop();
            if (get<0>(FIRST) > get<0>(TOP) && get<1>(FIRST) > get<1>(TOP)) {
                TMP.push(TOP);
                //cout << "TMP.push: " << get<0>(TOP) << "," << get<1>(TOP) << "," << get<2>(TOP) << "\n";
            } else {
                V[get<2>(TOP)] = rank;
                cnt++;
            }
        }
        swap(PQ, TMP);
        //cout << "===\n";
    }

    for (auto &ele : V) {
        cout << ele << " ";
    }
}