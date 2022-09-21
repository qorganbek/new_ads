#include <iostream>
#include <queue>

using namespace std;
int main () {
	int n;
	cin >> n;
	while (n--){
		int x;
		cin >> x;
		int ans[x];
		queue <int> q;
		for (int i = 0; i < x; i++){
			q.push(i);
		} 

		for (int i = 1; i <= x; i++){
			for (int j = 1; j <= i; j++){
				q.push(q.front());
				q.pop();
			}
			ans[q.front()] = i;
			q.pop();
		}
		for (int i = 0; i < x; i++){
			cout << ans[i] << " ";
		}
		cout <<"\n";
	}
	return 0;
}

