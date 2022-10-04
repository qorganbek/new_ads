#include <bits/stdc++.h>
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
        NODE * cur = head;
        while(cur){
            cout << cur->val << " ";
            cur = cur->next;
        }
    }

    int find_max_ind(int a[]){
        int max = -1e9;
        int ind;
        for (int i = 0; i < 1001; i++){
            if (max < a[i]){
                max = a[i];
                ind = i;
            }
        }
        return max;
    }


// 1 1 1 2 3 cnt 

};






int main () {
    int arr[1001];
    for (int i = 0; i < 1001; i++){
        arr[i] = 0;
    }
    LL ll;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr[x]++;
        ll.add(x);
    }
    int mode_ind = ll.find_max_ind(arr);
    vector<int> v;
    for (int i = 0; i < 1001; i++){
        if (arr[i] == mode_ind){
            v.push_back(i);
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    return 0;
}

// 5 
//1 1 1 2 3 