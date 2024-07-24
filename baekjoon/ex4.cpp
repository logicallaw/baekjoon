#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(string a, string b) {
    return a > b;
}
int main(void) {
    vector<string> array;
    array.push_back("D");
    array.push_back("A");
    array.push_back("E");
    array.push_back("C");
    array.push_back("B");

    //사용자 정의의 비교 함수로 내림차순 정렬
    sort(array.begin(), array.end(), comp);
    for(string s : array) {
        cout << s << " "; //A B C D E
    }
    cout << endl;
    return 0;
}