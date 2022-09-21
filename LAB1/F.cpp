#include <bits/stdc++.h>
using namespace std;



bool isPrime(int n){
	for (int i = 2; i <= sqrt(n); i++){
		if (n % i == 0){
			return false;
		}
	}
	return true;
}



int main () {
	vector<int> v;
	int n;
	cin >> n;
	for (int i = 2; i < 8000; i++){
		if (isPrime(i)){
			v.push_back(i);
		}
	}
	cout << v[n-1];
	return 0;
}