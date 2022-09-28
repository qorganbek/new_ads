#include <iostream>
using namespace std;
struct NODE
{
	string val;
	NODE * next;
	NODE(string x){
		val = x;
		next = NULL;
	}
};

struct LL
{
	NODE * head;
	NODE * tail;
	LL(){
		head = NULL;
		tail = NULL;
	}
	void add(string x){
		NODE * n = new NODE(x);
		if (head == NULL){
			head = n;
			tail = n;
		}
		else {
			tail->next = n;
			tail = n;
		}
	}

	void print(){
		NODE * current = head;
		while (current != NULL)
		{
			cout << current->val << " ";
			current = current->next;
		}
	}


// 0 1 2 3 4
// 1 2 3 4 5 5 2 3
	void cyclic_shift(int n, int m){
		LL ans;
		NODE * current = head;
		int i = 0;
		while (current)
		{
			if (i >= m){
				ans.add(current->val);
			}
			current = current->next;
			i++;
		}
		NODE * current2 = head;
		for (int j = 0; j < m; j++){
			ans.add(current2->val);
			current2 = current2->next;
		}
		ans.print();
	}

};


int main () {
	LL l;
	int n,m;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		string x;
		cin >> x;
		l.add(x);
	}
	l.cyclic_shift(n,m);
	return 0;
}