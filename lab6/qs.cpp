#include <iostream>

using namespace std;
 
int part(int *a, int low , int high){
    int i = low - 1;
    int pivot = high;
    for (int j = low; j < high - 1; j++){
        if (a[j] < a[pivot]){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[pivot]); 
}

void qsort(int *a,int low, int high){
    if (low < high){
        int pivot = part(a,low,high);
        qsort(a, low, pivot - 1);
        qsort(a, pivot + 1, high);
    }
}


int main (){
    int a[] = {1, 15, 6, 8, -8, 7};
    int n = sizeof(a) / sizeof(int);

    return 0;
}