#include <iostream>
using namespace std;

struct hp{
    private:
    int  * a;
    int cap;
    int len;
    void _cut_min(){
        a[0] = a[len-1];
        len = max(len-1 , 0);
        heap_down(0);
    }
    void _add(int x){
        a[len] = x;
        len++;
        heap_up(len-1);
    }
    void heap_down(int i){
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int min_pos = i;
        if (l < this->len and a[min_pos] > a[l]) min_pos = l;
        if (r < this->len and a[min_pos] > a[r]) min_pos = r;
        if (i != min_pos){
            swap(a[i],a[min_pos]);
            heap_down(min_pos);
        }
    }

    void heap_up(int i){
        if (i > 0){
            int p_pos = (i - 1) / 2;
            if (a[i] < a[p_pos]){
                swap(a[i],a[p_pos]);
                heap_up(p_pos);
            }
        }
    }

    public:
        hp(int cap){
            a =  new int [cap];
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
};

int main (){
    hp hp_min(100);
    int a[] = {15, 20, 18, 2, 5, -1};
    int n = sizeof(a) / sizeof(int);
    for (int i = 0; i < n; i++){
        hp_min.add(a[i]);
    }
    
    for (int i = 0; i < n; i++){
        cout << hp_min.cut_min() << " "; 
    }
    

}