#include <iostream>

using namespace std;

int partition(char *a, int low, int high){
    int i = low - 1;
    int pivot = high;
    for (int j = low; j <= high; j++){
        if (a[j] < a[pivot]){
            i++;
            swap(a[i],a[j]);
        }               
    }
    swap(a[i + 1],a[pivot]);
    return i + 1; 
}

void qsort(char *a, int low, int high){
    if (low < high){
       int pivot = partition(a,low,high);
       qsort(a,low,pivot-1);
       qsort(a,pivot+1,high); 
    }
}

int main (){
    int n;
    cin >> n;
    char a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        if (a[i] == 'a' or a[i] == 'e' or a[i] == 'u' or a[i] == 'i' or a[i] == 'o'){
            a[i] -= 32;
        }
    }    
    qsort(a,0,n-1);
    for (int i = 0; i < n; i++){
        if (a[i] + 32 == 'a' or a[i] + 32 == 'e' or a[i] + 32 == 'u' or a[i] + 32 == 'i' or a[i] + 32 == 'o'){
            a[i] += 32;
        }
    }     
    for (int i = 0; i < n; i++){
        cout << a[i];
    }
    return 0;
}