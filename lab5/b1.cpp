#include <iostream>

using namespace std;

struct hp{
private:
    int * a;
    int capacity;
    int length;

    void heap_up(int i){
        if(i > 0){
            int p_pos = (i - 1) / 2;
            if(a[i] > a[p_pos]){
                swap(a[i], a[p_pos]);
                heap_up(p_pos);
            }
        }
    }

    void heap_down(int i){
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int max_pos = i;
        if(l < this->length && a[max_pos] < a[l]) max_pos = l;
        if(r < this->length && a[max_pos] < a[r]) max_pos = r;
        if(i != max_pos) {
            swap(a[i], a[max_pos]);
            heap_down(max_pos);
        }
    }

    void _cut_max(){
        a[0] = a[length - 1];
        length = max(length - 1, 0);
        heap_down(0);
    }

    void _add(int x){
        a[length] = x;
        length++;
        heap_up(length - 1);
    }

public:
    int get_len(){
        return length;
    }

    hp(int capacity){
        a = new int[capacity];
        this->capacity = capacity;
        length = 0;
    }
    
    int cut_max(){
        int res = a[0];
        _cut_max();
        return res;
    }

    void add(int x){
        _add(x);
    }

    void print(){
        for(int i = 0; i < length; ++i){
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


int main(){
    hp h(100000);
    int n,x;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        h.add(x);
    }
    
    // for (int i = 0; i < n; i++){
    //     cout << h.cut_max() << " ";
    // }

    while (h.get_len() > 1)
    {
        int max_1 = h.cut_max();
        int max_2 = h.cut_max();
        h.add(max_1-max_2);
    }
    if (h.get_len()== 0){
        cout << 0;
        return 0;
    }
    cout << h.cut_max();
    
    

    return 0;
}