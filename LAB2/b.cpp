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


	

	string cyclic_shift(int n){
		string ans = "";
		NODE * cur  = head;
		int i = 0;
		int size = 0;
		while (cur != NULL){
			cout << cur->val;
			cur = cur->next;
		}
		return ans;	
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
	cout << l.cyclic_shift(m);
	return 0;
}