#include <bits/stdc++.h>
using namespace std;
int main () {
	int j = -1e9;
	vector <int> v;
	deque <int> deq;
	char a;
	while (cin >> a)
	{
		if (a == '+'){
			int x;
			cin >> x;
			deq.push_front(x);  
		}
		else if (a == '-'){
			int x;
			cin >> x;
			deq.push_back(x);
		}
		else if (a == '*'){
			if (deq.empty()){
				v.push_back(j);
			}
			else if (deq.size() == 1){
				v.push_back(deq.front() + deq.back());
				deq.pop_back();
			}
			else {
				v.push_back(deq.front() + deq.back());
				deq.pop_back();
				deq.pop_front();
			}
		}
		else if (a == '!'){
			break;
		}
	}
	for (int i = 0; i < v.size(); i++ ){
		if (v[i] == j){
			cout << "error" << endl;
		}
		else {
			cout << v[i] << endl;
		}
	}
	return 0;
}