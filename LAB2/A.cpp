#include <iostream>
using namespace std;
struct NODE
{
	int val;
	NODE * next;
	NODE(int x){
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
	void add(int x){
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

	int find_minimum_index(int n){
		NODE * current = head;
		int ind = 0;
		int i = 0;
		int min = 1e9;
		while(current != NULL){
			if(min > abs(n-current->val)){
				min = abs(n - current->val);
				ind = i;
			}
			i++;
			current = current->next;
		}
		return ind;
	}

};


int main () {
	LL ll;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i){
		int x;
		cin >> x;
		ll.add(x);
	}
	int m;
	cin >> m;
	cout << ll.find_minimum_index(m);
	return 0;
}