#include <iostream>
//merge sort
using namespace std;

void sort(int arr[], const int first, const int last);
void merge(int arr[], const int first, const int mid, const int last);

int main(void){
    const int SIZE = 5;
    int sum = 0;
    int arr[SIZE];
    for (int i{ 0 }; i < SIZE; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    //오름차순 정렬합니다.
    sort(arr, 0, SIZE - 1);

    //평균을 출력합니다.
    cout << sum / SIZE << endl;

    //중앙값을 출력합니다.
    cout << arr[2] << endl;

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
    int i = first, j = mid + 1, k = 0;
    while(i <= mid && j <= last){
        if (arr[i] <= arr[j]){
            param[k++] = arr[i++];
        }
        else{
            param[k++] = arr[j++];
        }
    }
    if (i > mid){
        while (j <= last){
            param[k++] = arr[j++];
        }
    }
    else{
        while(i <= mid){
            param[k++] = arr[i++];
        }
    }
    for (i = first, k = 0; i <= last;){
        arr[i++] = param[k++];
    }

    delete[] param;

}