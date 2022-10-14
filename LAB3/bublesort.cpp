#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1 2 2 6 7 8 9
// 0 1 2 3 4 5 6
// 4 8

void bs(vector<int> a, int n, int x){
	int cnt,sum;
	cnt = sum = 0;
	int l,r;
	l = 0;
	r = n - 1;
	while(l <= r){
		int m = l + (r - l)/2;
		if (a[m] <= x and a[m+1] > x and m != n-1){
			cnt = m + 1; 
			for(int i = 0; i <= m; i++){
				sum += a[i];
			}
			cout << cnt << " " << sum << endl;
			break;
		}
		else if (a[m] > x){
			r = m - 1;
		}
		else if (a[m] < x){
			l = m + 1;
		}
	}  
}


int main (){
	int n;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}

	int p;
	cin >> p;
	vector<int> mark;
	for (int i = 0; i < p; i++){
		int x;
		cin >> x;
		mark.push_back(x);
	}
	sort(v.begin(),v.end());

	for (int i = 0; i < p; i++){
		bs(v,n,mark[i]);
	}
	return 0;
}