#include <iostream>
#include <vector>

using namespace std;

int partition(int *a, int low, int high){
    int i = low - 1;
    int pivot = high;
    for (int j = low; j < high; j++){
        if (a[j] < a[pivot]){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[pivot],a[i+1]);
    return i+1; 
}

void qsort(int *a, int low, int high){
    if(low < high){
        int pivot = partition(a, low, high);
        qsort(a, low, pivot-1);
        qsort(a, pivot+1, high);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    

    return 0;
}