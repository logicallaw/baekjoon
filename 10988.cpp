#include <iostream>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true) {
        string word;
        cin >> word;
        if(word == "0") break;
        int lth = word.length();
        bool isPass = false;
        for(int i{ 0 }; i < lth/2; i++) {
            if(isPass) break;
            if(word[i] != word[lth - 1 - i]) {
                printf("no\n");
                isPass = true;
            }
        }
        if(!isPass) {
            printf("yes\n");
        }
    }
}