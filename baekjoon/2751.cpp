#include <iostream>
//merge sort
using namespace std;
int arr[1000000];

void sort(int arr1[], const int first, const int last);
void merge(int arr1[], const int first, const int mid, const int last);

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i{ 0 }; i < n; i++)
        cin >> arr[i];

    sort(arr, 0, n -1 );

    for (int i{ 0 }; i < n; i++)
        printf("%d\n", arr[i]);

    return 0;
}

void sort(int arr1[], const int first, const int last){
    if (first < last){
        int mid = (first + last)/2;
        sort(arr, first, mid);
        sort(arr1, mid + 1, last);
        merge(arr1, first, mid, last);
    }
}

void merge(int arr1[], const int first, const int mid, const int last){
    int* param = new int[last - first + 1];
    int i = first, j = mid + 1, k = 0;
    while (i <= mid && j <= last)
        if (arr1[i] <= arr1[j])
            param[k++] = arr1[i++];
        else
            param[k++] = arr1[j++];

    if (i > mid)
         while (j <= last)
             param[k++] = arr1[j++];
    else
        while (i <= mid)
            param[k++] = arr1[i++];

    for (i = first, k = 0; i <= last;)
        arr1[i++] = param[k++];

    delete[] param;
}