#include <iostream>
using namespace std;

struct hp{
public:
	hp(int cap){
		a = new int[cap];
		this->cap = cap;
		len = 0;
	}

	void add(int x){
		_add(x);
	}

	int cut_min(){
		int res = a[0];
		_cut_min();
		return res;
	}

	void print(){
		for (int i = 0; i < len; i++){
			cout << a[i] << " ";
		}
		cout << endl;
	}
private:
	int *a;
	int cap,len;

	void _add(int x){
		a[len] = x;
		len++;
		heap_up(len-1);
	}

	void heap_up(int i){
		if (i > 0){
			int p_pos = (i-1) / 2;
			if (a[p_pos] > a[i]){
				swap(a[p_pos],a[i]);
				heap_up(p_pos);
			}
		}
	}

	void _cut_min(){
		a[0] = a[len-1];
		len = max(len - 1,0);
		heap_down(0);
	}

	void heap_down(int i){
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		int min_pos = i;
		if (l < len && a[min_pos] > a[l]) min_pos = l;
		if (r < len && a[min_pos] > a[r]) min_pos = r;
		if (i != min_pos){
			swap(a[min_pos],a[i]);
			heap_down(min_pos);
		}
	}




};



int main (){
	hp h(100000);
	int a[] = {5,1,8,3,15,-9};
	int n = sizeof(a) / sizeof(int);
	for (int i = 0; i < n; i++){
		h.add(a[i]);
	} 

	h.print();


	for (int i = 0; i < n; i++){
		cout << h.cut_min() << " ";
	}
	cout << endl;
	

	return 0;
}