#include <bits/stdc++.h>
using namespace std;
struct MinHeap
{
    vector<int> heap;
    int capacity;
    long long sum;

    MinHeap(int capacity)
    {
        this->capacity = capacity;
    }

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

    void check(int value)
    {
        if (heap.size() == capacity)
        {
            int mini = extractMin();
            if (mini < value)
            {
                insert(value);
                sum += value;
                sum -= mini;
            }
            else
                insert(mini);
        }
        else
        {
            insert(value);
            sum += value;
        }
    }

    void insert(int value)
    {
        this->heap.push_back(value);
        int i = this->heap.size() - 1;
        while (i != 0 && this->heap[parent(i)] > this->heap[i])
        {
            swap(this->heap[parent(i)], this->heap[i]);
            i = parent(i);
        }
    }
    int extractMin()
    {
        if (this->heap.size() == 0)
            return INT_MAX;
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
        if (l < this->heap.size() && this->heap[l] < this->heap[highest])
            highest = l;
        if (r < this->heap.size() && this->heap[r] < this->heap[highest])
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
    int getSum()
    {
        return sum;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    MinHeap *heap = new MinHeap(k);
    while (n--)
    {
        string command;
        cin >> command;
        if (command == "print")
        {
            cout << heap->getSum() << endl;
        }
        else if (command == "insert")
        {
            int x;
            cin >> x;
            heap->check(x);
        }
    }

    return 0;
}