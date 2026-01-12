#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    unordered_map<string, string> UM;

    while (N--) {
        string a, b;
        cin >> a >> b;

        UM.insert({a, b});
    }

    while (M--) {
        string a;
        cin >> a;

        cout << UM[a] << "\n";
    }
}