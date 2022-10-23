#include<bits/stdc++.h>
using namespace std;
struct MinHeap {
	vector<int> heap;

	int parent(int i) {
		return (i - 1) / 2;
	}
	int left(int i) {
		return 2 * i + 1;
	}
	int right(int i) {
		return 2 * i + 2;
	}
	void insert(int val) {
		heap.push_back(val);
		int i = heap.size() - 1;
		while (i != 0 && heap[parent(i)] > heap[i]) {
			swap(heap[parent(i)], heap[i]);
			i = parent(i);
		}
	}
	int extractMin() {
		if (heap.size() == 0) return -1;
		if (heap.size() == 1) {
			int root = heap[0];
			heap.pop_back();
			return root;
		}
		int root = heap[0];
		heap[0] = heap[heap.size() - 1];
		heap.pop_back();
		heapify(0);
		return root;
	}
	void heapify(int i) {
		int l = left(i);
		int r = right(i);
		int smallest = i;
		if (l < heap.size() && heap[l] < heap[i])
			smallest = l;
		if (r < heap.size() && heap[r] < heap[smallest])
			smallest = r;
		if (smallest != i) {
			swap(heap[i], heap[smallest]);
			heapify(smallest);
		}
	}
    int getSize(){
        return heap.size();
    }
};

int main() {
	MinHeap h;
	long long n, k;
    cin >> n >> k;
    while(n--){
        int m;
        cin >> m;
        h.insert(m);
    }

    int cnt = 0;
    while(h.getSize() > 0){
        int mn = h.extractMin();
        if(mn >= k) break;
        int smn = h.extractMin();
        if(smn == -1){
            cout << -1;
            return 0;
        }
        int nmix = mn + 2 * smn;
        h.insert(nmix);
        cnt++;
    }
    cout << cnt;
}
