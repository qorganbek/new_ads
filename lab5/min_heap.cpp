#include <iostream>

using namespace std;

struct min_heap{
private:
	int * a;
	int len, cap;
	void _add(int x){
		a[len] = x;
		len++;
		heap_up(len-1);
	}

	void heap_up(int i){
		if (i > 0){
			int p_pos = (i-1)/2;
			if (a[p_pos] > a[i]){
				swap(a[i],a[p_pos]);
				heap_up(p_pos);
			} 
		}
	}

	void _cut_min(){
		a[0] = a[len-1];
		len = max(len-1,0);
		heap_down(0);	
	}

	void heap_down(int i){
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		int min_pos = i;
		if (this->len > l && a[l] < a[min_pos]) min_pos = l;
		if (this->len > r && a[r] < a[min_pos]) min_pos = r;
		if (i != min_pos){
			swap(a[min_pos],a[i]);
			heap_down(min_pos);
		}
	}
public:
	min_heap(int cap){
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

	int get_len(){
		return this->len;
	}	

	int get_min(){
		return this->a[0];
	}


	void print(){
		for (int i = 0; i < len; i++){
			cout << a[i] << " ";
		}
		cout << endl;
	}	

};

int main (){
	min_heap hp(100000);
	int a[] = {9, -5, 1 ,15, 8};
	int n = sizeof(a) / sizeof(int);
	for (int i = 0; i < n; i++){
		hp.add(a[i]);
	}

	cout << hp.get_len() << endl;
	cout << hp.get_min();
	return 0;
}