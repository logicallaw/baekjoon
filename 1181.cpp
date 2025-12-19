#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <cstring>
using namespace std;
bool compare(string a, string b) {
    if(a.length() < b.length()) {
        return true;
    } else if (a.length() == b.length()) {
        if(strcmp(a.c_str(), b.c_str()) < 0) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}
int main(void) {
    //입력 수가 많으므로 비동기화 진행
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> array;
    unordered_set<string> keys;
    while(n--) {
        string userInput;
        cin >> userInput;
        //중복 확인 : O(1) time
        if(keys.find(userInput) == keys.end()) {
            //새로운 문자열 삽입 연산 : O(1) time
            keys.insert(userInput);
            array.push_back(userInput);
        }
    }
    //문자열 compare 함수 기준으로 정렬 : O(nlogn) time
    sort(array.begin(), array.end(), compare);
    //printf 사용
    for(string element : array){
        printf("%s\n", element.c_str());
    }
    return 0;
}