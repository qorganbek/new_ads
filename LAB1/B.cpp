#include <bits/stdc++.h>
using namespace std;

int f(int n,int v[], int index ){
	if (index == 0){
		return -1;
	}
	else {
		for (int i = index - 1; i >= 0; i--){
			if (n >= v[i]){
				return v[i];
			}
		}
		return -1;
	}
}


int main () {
	int n;
	cin >> n;
	int v[n];
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}

	int ff[n];


	for (int i = 0; i < n; i++){ 
		ff[i] = f(v[i],v,i);
	}

	for (int i = 0; i < n; i++){
		cout << ff[i] << " ";
	}


	return 0;
}