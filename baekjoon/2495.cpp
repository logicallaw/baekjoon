#include <iostream>
#include <string>
using namespace std;
int main(void) {
    int cnt = 3;
    while(cnt--){
        string n;
        cin >> n;
        int duplicated = 1;
        int max = 1;
        for(int i{ 0 }; i < 8; i++) {
            if(i == 0 || n[i-1] != n[i]) {
                if(duplicated > 1) { //두번 이상만 체크한다.
                    max = (max < duplicated) ? duplicated : max;
                }
                duplicated = 1;
            } else {
                duplicated++;
            }
        }
        if(duplicated > 1) {
            max = (max < duplicated) ? duplicated : max;
        }
        cout << max << endl;
    }
    return 0;
}