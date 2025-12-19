#include <iostream>
//selection_sort
using namespace std;
void selection_sort(int nums[], const int& size);
void printNums(int nums[], const int& n);

int main(void){
    int size;
    cin >> size;

    int nums[1000];
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i{ 0 }; i < size; i++){
        cin >> nums[i];
    }

    //selection_sort 실행합니다.
    selection_sort(nums, size);

    //출력합니다.
    printNums(nums, size);
}

void selection_sort(int nums[], const int& SIZE){
    int indexMin;
    //n-1번 반복합니다.
    //이때, 정렬되지 않는 배열의 맨 앞 index 번호는 i입니다.
    for (int i{ 0 }; i < SIZE - 1; i++){
        indexMin = i;
        //i + 1번째부터 맨 끝까지 순회하면서
        //정렬되지 않는 배열 원소의 최솟값 index를 찾습니다.
        //찾은 index는 indexMin으로 저장합니다.
        for (int j{ i + 1 }; j < SIZE; j++){
            if (nums[indexMin] > nums[j]){
                indexMin = j;
            }
        }
        //temp:정렬되지 않는 가장 작은 값을 임시 저장합니다.
        int temp = nums[indexMin];
        //맨 앞 원소랑 가장 작은 원소랑 exchange 합니다.
        nums[indexMin] = nums[i];
        //맨 앞 원소에 가장 작은 값을 저장하여 오름차순 정렬합니다.
        nums[i] = temp;
    }
}


void printNums(int nums[], const int& n){
    for (int i{ 0 }; i < n; i++)
        printf("%d\n", nums[i]);
}
