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
    char my_char;
    
    cin >> my_char;

    qsort(a,0,n-1);
    
    if (a[n-1] == my_char){
        cout << a[0];
        return 0;
    }
    
    for (int i = 0; i < n; i++){

        if (a[i] > my_char){
            cout << a[i];
            return 0;
        }
    }
    return 0;
}