#include <iostream>

using namespace std;

struct hp
{   private:
    int *a;
    int len,cap;

    void _cut_min(){
        a[0] = a[len-1];
        len = max(len-1,0);
        heap_down(0);
    }

    void heap_down(int i){
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int min_pos = i;
        if (len > l && a[min_pos] > a[l]) min_pos = l;
        if (len > r && a[min_pos] > a[r]) min_pos = r;
        if (min_pos != i){
            swap(a[min_pos],a[i]);
            heap_down(min_pos);
        }
    }
    
    void heap_up(int i){
        if (i > 0){
            int p_pos = (i-1)/2;
            if (a[p_pos] > a[i]){
                swap(a[p_pos],a[i]);
                heap_up(p_pos);
            }
        }
    }
    
    void _add(int x){
        a[len] = x;
        len++;
        heap_up(len-1);
    }
    public:
    hp(int cap){
        a = new int[cap];
        this->cap = cap;
        len = 0;    
    }

    int cut_min(){
        int res = a[0];
        _cut_min();
        return res;
    }

    void add(int x){
        _add(x);
    }

};



int main(){
    int a[] = {19,15,20,-4,32,26,16,4,2};
    int n= sizeof(a) / sizeof(int);
    hp h(100000);
    for (int i = 0; i < n; i++){
        h.add(a[i]);
    }

    for (int i = 0; i < n; i++){
        cout << h.cut_min() << " ";
    }
    return 0;
}