#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int x;
	cin >> x;

	int m,l,r;
	r = n - 1;
	l = 0;


	while (l <= r)
	{
		m = l + (r - l) / 2;
		if (a[m] == x){
			cout << "Yes";
			return 0;
		}
		else if(x < a[m]){
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	cout << "No";
	return 0;
}