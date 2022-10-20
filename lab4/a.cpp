#include <iostream>

using namespace std;

struct node{
    int val;
    node * left;
    node * right;
    int cnt;
    node(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};

struct bst{
    public:
    bst(){
        root = NULL;
    }
    void add(int x){
        node * result = this->add(this->root, x);
        if(root == NULL){
            root = result;
        }
    }
    void print(){
        this->print(this->root);
    }

    bool check(string s){
        return this->check(root,s);
    }

    private:
    node * root;
    node * add(node * current, int x){
        if(current == NULL){
            current = new node(x);
        }else if(current->val > x){
            if(current->left == NULL){
                current->left = add(current->left, x);
            }else{
                add(current->left, x);
            }
        }else if(current->val < x){
            if(current->right == NULL){
                current->right = add(current->right, x);
            }else{
                add(current->right, x);
            }
        }
        return current;
    }
    void print(node * current){
        if(current != NULL){
            print(current->left);
            cout << current->val << " ";
            print(current->right);
        }
    }



    bool check(node * cur, string s){
        for (int i = 0; i < s.size(); i++){
            if (s[i] == 'L') cur = cur->left;
            else cur = cur->right;
            if (cur == NULL) return false;
        }
        return true;
    }
};


int main(){
    int n, m, x;
    cin >> n >> m;
    bst * b = new bst();
    for (int i = 0; i < n; i++){
        cin >> x;
        b->add(x);
    }
    string s;
    for (int i = 0; i < m; i++){
        cin >> s;
        string res = b->check(s) ? "YES" : "NO";
        cout << res << endl;
    }
    return 0;
}