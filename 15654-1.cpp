#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N, M;

int num[9];
int arr[9];
bool check[9];

void dfs(int arr_last, int checked) {
    if (checked == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!check[i]) {
            arr[arr_last] = num[i];
            // cout << "arr[" << arr_last << "] = num[" << i << "]\n"; 
            check[i] = true;
            dfs(arr_last + 1, checked + 1);
            check[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        num[i] = x;
    }

    sort(num, num + N);

    // for (auto ele : num) {
    //     cout << ele << " ";
    // }
    // cout << "--\n";

    for (int i = 0; i < N; i++) {
        arr[0] = num[i];
        check[i] = true;
        dfs(1, 1);
        check[i] = false;

        // cout << "bye\n";
        // for (auto ele : check) {
        //     cout << ele << " ";
        // }
        // cout << "==\n";
    }
}