#include <iostream>

using namespace std;

void bubble_sort(int *a, int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (a[i] > a[j]){
                swap(a[i],a[j]);
            }
        }
    }
}

int main(){
    int a[] = {19, 7 , 10, 9, 15, 12, 27, 16, 20};
    int n = sizeof(a) / sizeof(int);

    bubble_sort(a,n);
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    return 0;
}