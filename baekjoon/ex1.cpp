#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    int **array = new int *[n];
    for (int i{0}; i < n; i++) {
        array[i] = new int[n];
        for (int j{0}; j < n; j++) {
            cin >> array[i][j];
        }
    }
//    for (int i{0}; i < n; i++) {
//        for (int j{0}; j < n; j++) {
//            cout << array[i][j] << " ";
//        }
//        cout << endl;
//    }
    int cnt = 0;
    bool isPass = false;
    for (int i{ 0 }; i < n; i++) {
        for (int j{ 0 }; j < (n - 1); j++) {
            if (isPass) break;
            if (array[i][j] == array[i][j + 1]) {
                cnt++;
                isPass = true;
            }
        }
    }
    isPass = false;
    for (int i{ 0 }; i < n; i++) {
        for (int j{ 0 }; j < (n - 1); j++) {
            if (isPass) break;
            if (array[j][i] == array[j + 1][i]) {
                cnt++;
                isPass = true;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}