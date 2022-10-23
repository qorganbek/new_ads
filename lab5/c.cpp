#include <bits/stdc++.h>
using namespace std;
struct MaxHeap
{
    vector<int> heap;

    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int left(int i)
    {
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }
    void insert(int value)
    {
        this->heap.push_back(value);
        int i = this->heap.size() - 1;
        while (i != 0 && this->heap[parent(i)] < this->heap[i])
        {
            swap(this->heap[parent(i)], this->heap[i]);
            i = parent(i);
        }
    }
    int extractMax()
    {
        if (this->heap.size() == 0)
            return INT_MIN;
        if (this->heap.size() == 1)
        {
            int root = this->heap[0];
            this->heap.pop_back();
            return root;
        }
        int root = this->heap[0];
        this->heap[0] = this->heap[this->heap.size() - 1];
        this->heap.pop_back();
        this->heapify(0);
        return root;
    }
    void heapify(int i)
    {
        int l = this->left(i);
        int r = this->right(i);
        int highest = i;
        if (l < this->heap.size() && this->heap[l] > this->heap[highest])
            highest = l;
        if (r < this->heap.size() && this->heap[r] > this->heap[highest])
            highest = r;
        if (highest != i)
        {
            swap(this->heap[i], this->heap[highest]);
            this->heapify(highest);
        }
    }
    int size()
    {
        return heap.size();
    }
};

int main()
{
    MaxHeap heap;
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        heap.insert(arr[i]);
    }
    long sum = 0;
    while (k--)
    {
        int maxi = heap.extractMax();
        sum += maxi;
        heap.insert(maxi - 1);
    }
    cout << sum << endl;

    return 0;
}