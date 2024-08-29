#include <iostream>
using namespace std;

int sol(int arr[], int a, int b) {
    return arr[a] * arr[b];
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;
    int arr[101] {};
    for(int i{ 1 }; i <= n; i++) {
        cin >> arr[i];
    }
    int s = sol(arr, 1, 1 + k);
    while(k < n) {
        for(int i{ 1 }; i <= n; i++) {
            if(i + k <= n) {
                int temp = sol(arr, i, i + k);
                s = (s < temp) ? temp : s;
            } else {
                break;
            }
        }
        k++;
    }
    cout << s;
    return 0;
}