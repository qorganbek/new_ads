#include <iostream>

using namespace std;

int partition(string &a, int low, int high){
    int i = low - 1;
    int pivot = high;
    for(int j = low; j <= high - 1; ++j){
        if(a[j] < a[pivot]){
            i++;
            char save2 = a[i];
            a[i] = a[j];
            a[j] = save2;
        }
    }
    char save = a[pivot];
    a[pivot] = a[i + 1];
    a[i + 1] = save;
    return i + 1;
}


void qsort(string &a, int low, int high){
    if(low < high){
        int pivot = partition(a, low, high);
        qsort(a, low, pivot - 1);
        qsort(a, pivot + 1, high);
    }
}

int main(){
    string s;
    cin >> s;
    qsort(s,0,s.size()-1);
    
    cout << s;
    return 0;
}