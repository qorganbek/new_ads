#include <iostream>
using namespace std;
int main (){
	int a[] = {1,8,12,15,10,-5,49,70,65,12};
	int n = sizeof(a) / sizeof(int);
	for (int i = 0; i < n-1; i++){
		for (int j = i + 1; j < n; j++){
			if (a[i] > a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	return 0;
}