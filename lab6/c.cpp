#include <iostream>

using namespace std;

int partitition(int *a, int low, int high){
    int i = low - 1;
    int pivot = high;
    for (int j = low; j < high; j++){
        if(a[j] < a[pivot]){
            i++;
            swap(a[j],a[i]);
        }
    }
    swap(a[pivot],a[i+1]);
    return i + 1; 
}

void qsort(int *a, int low, int high){
    if (low < high){
        int pivot = partitition(a,low,high);
        qsort(a,low,pivot-1);
        qsort(a,pivot+1,high);
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    qsort(a,0,n-1);

    int f;
    int s;
    
    return 0;
}