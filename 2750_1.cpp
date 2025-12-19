#include <iostream>
//bubble_sort
using namespace std;
void bubble_sort(int nums[], const int& SIZE);
void printNums(int nums[], const int& SIZE);
void swap(int* p1, int* p2);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int inputNumber;
    int nums[1000];
    cin >> n;
    //n번째까지 입력을 받습니다.
    for (int i{ 0 }; i < n; i++){
        cin >> nums[i];
    }
    //정렬합니다.
    bubble_sort(nums, n);

    //출력합니다.
    printNums(nums, n);

    return 0;
}
void bubble_sort(int nums[], const int& SIZE){
    //변수 i의 역할:SIZE - 1번 반복합니다.
    for (int i{ 0 }; i < SIZE - 1; i++){
        //변수 j의 역할:배열을 순회합니다. 이때, 점점 순회하면서 순회 횟수는 줄입니다.
        for (int j{ 0 }; j < SIZE - i - 1 ; j++){
            if (nums[j] > nums[j+1])
                swap(nums[j], nums[j+1]);
        }
    }
}
void swap(int* p1, int* p2){
    int* temp = p1;
    p1 = p2;
    p2 = p1;
}
void printNums(int nums[], const int& SIZE){
    for (int i{ 0 }; i < SIZE; i++)
        printf("%d\n", nums[i]);
}
