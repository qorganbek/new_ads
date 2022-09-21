#include <bits/stdc++.h>
using namespace std;

int find_min(int a[], int n){
	int min = 1e9;
	int pos;
	for (int i = 0; i < n; i++){
		if (min > a[i]){
			min = a[i];
			pos = i;
		}
	}
	return pos;
}


int main () {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int x;
	cin >> x;
	for (int i = 0; i < n; i++){
		if (a[i] < 0){
			a[i] += x;
			if (a[i] < 0){
				a[i] *= -1;
			}
		}
		else {
			a[i] -= x;
			if (a[i] < 0){
				a[i] *= -1;
			}
		}
	}
	
	cout << find_min(a, n);
	return 0;
}