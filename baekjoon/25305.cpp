#include <iostream>
//merge sort
using namespace std;

void sort(int arr[], const int first, const int last);
void merge(int arr[], const int first, const int mid, const int last);

int main(void){
    int arr[1000];
    int n;
    int k;
    cin >> n >> k;

    for (int i{ 0 }; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, 0, n - 1);

    cout << arr[n - k];

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
    while (i <= mid && j <= last){
        if (arr[i] <= arr[j]) param[k++] = arr[i++];
        else param[k++] = arr[j++];
    }
    if (i > mid)
        while (j <= last) param[k++] = arr[j++];
    else
        while (i <= mid) param[k++] = arr[i++];

    for (i = first, k = 0; i <= last;)
        arr[i++] = param[k++];

    delete[] param;
}