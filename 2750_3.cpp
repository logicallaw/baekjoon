#include <iostream>
//bubble_sort
using namespace std;
void insertion_sort(int nums[], const int& SIZE);
void printNums(int nums[], const int& SIZE);

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
    insertion_sort(nums, n);

    //출력합니다.
    printNums(nums, n);

    return 0;
}
void insertion_sort(int nums[], const int& SIZE){
    //i:1부터 시작 (n-1까지 반복)
    for (int i{ 1 }; i < SIZE; i++){
        int j = i;
        //temp:정렬되지 않는 배열의 맨 앞 원소의 값(옮길 원소, 대상 원소).
        int temp = nums[i];
        while (j > 0 && nums[j - 1] > temp){
            //nums[j-1] 왼쪽 값을 오른쪽으로 push
            nums[j] = nums[j - 1];
            j--;
        }
        nums[j] = temp;
    }
}
void printNums(int nums[], const int& SIZE){
    for (int i{ 0 }; i < SIZE; i++)
        printf("%d\n", nums[i]);
}
