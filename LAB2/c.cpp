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


	void multithread(){
		LL ans;
		NODE * cur = head;
		int i = 0;
		while (cur)
		{
			if (i % 2 == 0){
				ans.add(cur->val);
			}
			i++;
			cur = cur->next;
		}
		ans.print();
		
	}

};
// 1 2 3 4 5
int main () {
	LL ll;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i){
		int x;
		cin >> x;
		ll.add(x);
	}
	ll.multithread();
	return 0;
}