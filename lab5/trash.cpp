#include<iostream>
using namespace std;

struct max_heap{
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
			if (a[p_pos] < a[i]){
				swap(a[i],a[p_pos]);
				heap_up(p_pos);
			} 
		}
	}

	void _cut_max(){
		a[0] = a[len-1];
		len = max(len-1,0);
		heap_down(0);	
	}

	void heap_down(int i){
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		int max_pos = i;
		if (this->len > l && a[l] > a[max_pos]) max_pos = l;
		if (this->len > r && a[r] > a[max_pos]) max_pos = r;
		if (i != max_pos){
			swap(a[max_pos],a[i]);
			heap_down(max_pos);
		}
	}
public:
	max_heap(int cap){
		a = new int[cap];
		this->cap = cap;
		len = 0;
	}
	void add(int x){
		_add(x);
	}
	int cut_max(){
		int res = a[0];
		_cut_max();
		return res;
	}

	void print(){
		for (int i = 0; i < len; i++){
			cout << a[i] << " ";
		}
		cout << endl;
	}


	int get_len(){
		return len;
	}	

	int get_max(){
		return a[0];
	}

};

int main(){

}