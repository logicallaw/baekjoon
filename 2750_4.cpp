#include <iostream>
//merge_sort
using namespace std;

void sort(int arr[], const int first, const int last);
void merge(int arr[], const int first, const int mid ,const int last);
void print(int arr[], const int& SIZE);

int main(void){
    int arr[1000];
    //size를 입력받습니다.
    int size;
    cin >> size;

    //배열 원소 값을 입력 받습니다.
    for (int i{ 0 }; i < size; i++){
        cin >> arr[i];
    }

    //오름차순 병합정렬(합병정렬) 합니다.
    sort(arr, 0, size - 1);
    //정렬된 배열을 출력합니다.
    print(arr, size);

    return 0;

}

void sort(int arr[], const int first, const int last){
    if (first < last){
        int mid = (first + last) / 2;
        sort(arr, first, mid);
        sort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }

}

void merge(int arr[], const int first, const int mid, const int last){
    int* param = new int[last - first + 1];
    int i = first, j = mid + 1, k = 0; //k:param 배열의 맨 앞 원소의 index

    while(i <= mid && j <= last){
        if (arr[i] <= arr[j]){
            param[k++] = arr[i++];
        }
        else {
            param[k++] = arr[j++];
        }
    }
    //두개의 분할된 배열 중 하나가 이미 다 정렬되어 있다면, 남은 배열 순차적으로 param 배열에 저장한다.
    if (i > mid){
        while(j <= last){
            param[k++] = arr[j++];
        }
    }
    else{
        while(i <= mid){
            param[k++] = arr[i++];
        }
    }

    //param 임시 배열의 원소 값을 arr 배열에 할당한다.
    for (i = first, k = 0; i <= last;){
        arr[i++] = param[k++];
    }

    //임시 배열 param 동적 메모리 해제합니다.
    delete[] param;
}

void print(int arr[], const int& SIZE) {
    for (int i { 0 }; i < SIZE; i++)
        printf("%d\n", arr[i]);
}