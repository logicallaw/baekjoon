#include <iostream>

using namespace std;

int N;

int arr[129][129];

int white = 0;
int blue = 0;

void recur(int r_s, int r_d, int c_s, int c_d) {
    // 종료
    if (r_s == r_d || c_s == c_d) {
        if (arr[r_s][c_s] == 1) {
            blue++;
        } else {
            white++;
        }
        return;
    }

    // 순회
    int TW = 0;
    int TB = 0;
    for (int i = r_s; i <= r_d; i++) {
        for (int j = c_s; j <= c_d; j++) {
            if (arr[i][j] == 1) {
                TB++;
            } else {
                TW++;
            }
        }
    }

    // All Blue
    if (TW == 0 && TB != 0) {
        blue++;
        return;
    }
    // All White
    if (TW != 0 && TB == 0) {
        white++;
        return;
    }
    // others: 섞임

    // 4등분 쪼개고 들어가라
    int rm = (r_s + r_d) / 2;
    int cm = (c_s + c_d) / 2;

    recur(r_s, rm, c_s, cm);
    recur(r_s, rm, cm + 1, c_d);
    recur(rm + 1, r_d, c_s, cm);
    recur(rm + 1, r_d, cm + 1, c_d);

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            arr[i][j] = x;
        }
    }

    recur(0, N - 1, 0, N - 1);
    cout << white << "\n" << blue;
}