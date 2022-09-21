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
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 2; i < 4000; i++){
		if (isPrime(i)){
			v.push_back(i);
		}
	}
	vector<int> prime;
	for (int i = 2; i < v.size(); i++){
		if (isPrime(i)){
			prime.push_back(v[i-1]);
		}
	}
	cout << prime[n-1];
	return 0;
}