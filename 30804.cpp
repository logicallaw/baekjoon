#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

int arr[200001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }

    int ans = 0;

    set<int> S;
    unordered_map<int, int> UM;
    S.insert(arr[0]);
    UM[arr[0]]++;

    int j = 0;
    for (int i = 0; i < N; i++) {
        while (j + 1 < N && S.size() <= 2) {
            if (S.size() == 2 && S.find(arr[j+1]) == S.end()) break;
            UM[arr[j+1]]++;
            S.insert(arr[j+1]);
            j++;
        }
        ans = max(ans, j - i + 1);
        UM[arr[i]]--;
        if (UM[arr[i]] == 0) {
            S.erase(arr[i]);
        }
    }
    cout << ans;
}