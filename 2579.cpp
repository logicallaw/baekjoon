#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int arr[301];
int result[301];
bool status[301];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }

    queue<int> Q;
    result[1] = arr[1];
    result[2] = arr[2];
    status[1] = false;
    status[2] = false;

    Q.push(1);
    Q.push(2);

    while(!Q.empty()) {
        int i = Q.front();
        Q.pop();
        if (i == n) continue;
        cout << "i: " << i << "\n";

        if (status[i] == false) {
            if (i+1 <= n && result[i+1] < result[i] + arr[i+1]) {
                result[i+1] = result[i] + arr[i+1];
                cout << i << " " << result[i+1] << "\n";
                status[i+1] = true;
                Q.push(i+1);
            }

            if (i+2 <= n && result[i+2] < result[i] + arr[i+2]) {
                result[i+2] = result[i] + arr[i+2];
                cout << i << " " << result[i+2] << "\n";
                status[i+2] = false;
                Q.push(i+2);
            }
        } else {
            if (i+2 <= n && result[i+2] < result[i] + arr[i+2]) {
                result[i+2] = result[i] + arr[i+2];
                cout << i << " " << result[i+2] << "\n";
                status[i+2] = false;
                Q.push(i+2);
            }
        }
    }
    cout << result[n];
}