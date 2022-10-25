#include <iostream>

using namespace std;

struct hp{
private:
    long long * a;
    long long capacity;
    long long length;

    void heap_up(long long i){
        if(i > 0){
            long long p_pos = (i - 1) / 2;
            if(a[i] > a[p_pos]){
                swap(a[i], a[p_pos]);
                heap_up(p_pos);
            }
        }
    }

    void heap_down(long long i){
        long long l = 2 * i + 1;
        long long r = 2 * i + 2;
        long long max_pos = i;
        if(l < this->length && a[max_pos] < a[l]) max_pos = l;
        if(r < this->length && a[max_pos] < a[r]) max_pos = r;
        if(i != max_pos) {
            swap(a[i], a[max_pos]);
            heap_down(max_pos);
        }
    }

    void _cut_max(){
        a[0] = a[length - 1];
        length = length - 1 > 0 ? length - 1 : 0;
        heap_down(0);
    }

    void _add(int x){
        a[length] = x;
        length++;
        heap_up(length - 1);
    }

public:
    hp(long long capacity){
        a = new long long[capacity];
        this->capacity = capacity;
        length = 0;
    }
    
    long long cut_max(){
        long long res = a[0];
        _cut_max();
        return res;
    }

    void add(long long x){
        _add(x);
    }

    void print(){
        for(long long i = 0; i < length; ++i){
            cout << a[i] << " ";
        }
        cout << endl;
    }

    long long get_len(){
        return length;
    }

    long long get_max(){
        return a[0];
    }
};


int main(){
    hp h(100000);
    long long n,m;
    cin >> n >> m;
    string s;
    long long cnt = 0;
    for (long long i = 0; i < n; i++){
        cin >> s;
        if (s == "print"){
            if (h.get_len() == 0){
                cout << 0 << endl;
            }
            else cout << h.get_max() << endl;
        }
        if (cnt <= m){
            if (s == "insert"){
                cnt++;
                long long x;
                cin >> x;
                if (h.get_len() == 0){
                    h.add(x);
                }
                else h.add(x+h.get_max());
            }
        }
    }
    return 0;
}