#include <iostream>

using namespace std;

int partition(int *a, int low, int high){
    int i = low - 1;
    int pivot = high;
    for (int j = low; j < high; j++){
        if (a[j] < a[pivot]){
            i++;
            swap(a[j],a[i]);
        }
    }
    swap(a[pivot], a[i + 1]);
    return i + 1;
}


void qsort(int *a, int low, int high){
    if (low < high){
        int pivot = partition(a, low, high);
        qsort(a, low, pivot - 1);
        qsort(a, pivot + 1, high);
    }
}


int main(){
    int a[] = {19, 7 , 10, 9, 15, 12, 27, 16, 20};
    int n = sizeof(a) / sizeof(int);

    qsort(a, 0, n - 1);

    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}