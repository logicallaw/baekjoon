#include <iostream>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int* array = new int[6];
    for(int i{ 0 }; i < 6; i++) {
        cin >> array[i];
    }
    int r1 = 0, r2 , r3;
    int t, p;
    cin >> t >> p;
    for(int i{ 0 }; i < 6; i++) {
        if(array[i] % t == 0) {
            r1 += array[i] / t;
        } else {
            r1 += (array[i] / t) + 1;
        }
    }
    r2 = n / p;
    r3 = n % p;
    cout << r1 << "\n";
    cout << r2 << " " << r3;
    delete[] array;
    return 0;
}