#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    stack<int> s;
    vector<char> ans;
    int num = 1;
    for(int i{ 0 }; i < n; i++) {
        int x;
        cin >> x;
        if(num <= x){
            while(num <= x) {
                s.push(num++); ans.push_back('+');
            }
            s.pop(); ans.push_back('-');
        } else { // num > x
            if(!s.empty() && s.top() == x) {
                s.pop(); ans.push_back('-');
            } else {
                cout << "NO";
                return 0;
            }
        }
    }
    for(vector<char>::iterator it = ans.begin(); it != ans.end(); it++) {
        printf("%c\n", *it);
    }
    return 0;
}