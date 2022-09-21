#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int a[10];
	for(int i=0;i<5;i++){
		cin >> a[i];
	}
	for (int i=0;i<5;i++){
		cout << a[i] << " " << endl;
	}
	next_permutation(a,a+5);
	for (int i=0;i<5;i++){
		cout << a[i] << " ";
	}

	return 0;
}