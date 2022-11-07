#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int partition (int *a, int low, int high){
    int i = low - 1;
    int pivot = high;
    for (int j = low; j < high; j++){
        if (a[j] < a[pivot]){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[pivot], a[i + 1]);
    return i + 1;
}


void qsort(int *a,int low, int high){
    if (low < high){
        int pivot = partition(a,low,high);
        qsort(a,low,pivot-1);
        qsort(a,pivot+1,high);
    }
}

int main (){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    qsort(a,0,n-1);

    // for (int i = 0; i < n; i++){
    //     cout <<  a[i] << " ";
    // }
    int mini = 1e9;

    for (int i = 1; i <= n; i++){
        if (abs(a[i] - a[i-1]) < mini){
            mini = abs(a[i] - a[i-1]);
        }
    }

    for (int i = 1; i <= n; i++){
        if (mini == abs(a[i] - a[i-1]) ){
            cout << a[i-1] << " "  << a[i] << " ";
        }
    }
    
    return 0;
}