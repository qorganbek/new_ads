#include <bits/stdc++.h>
using namespace std;
int main () {
	string s,t;
	cin >> s >> t;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '#'){
			s.erase(i-1,2);
			i -= 2;
		}
	}
	for (int i = 0; i < t.size(); i++){
		if (t[i] == '#'){
			t.erase(i-1,2);
			i -= 2;
		}
	}
	if (s == t){
		cout << "yes";
	}
	else{
		cout << "no";
	}
	return 0;
}