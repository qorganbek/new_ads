#include <bits/stdc++.h>
using namespace std;

struct node
{
    /* data */
    int val;
    node *right, *left;
    node(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};

struct bst
{

    public:


    int getHeight(node* cur) {
		if (!cur) return 0;
		int left = getHeight(cur->left);
		int right = getHeight(cur->right);
		return max(left, right) + 1;
	}

    node * getRoot(){
        return root;
    }

    bst(){
        root = NULL;
    }


    void print(){
        this->print(this->root);
    }

    void add(int x){
        node * res = this->add(this->root,x);
        if (root == NULL){
            root = res;
        }
    }

    int getSize(){
        return this->getSize(this->getRoot());
    }

    /* data */
    private:
    node * root;

    int getSize(node * cur){
        if (cur == NULL) return 0;
        return getSize(cur->left) + getSize(cur->right) + 1;
    }


    node  * add(node * cur, int x){
        if(cur == NULL){
            cur = new node(x);
        }
        else if (cur->val > x){
            if (cur->left == NULL){
                cur->left = add(cur->left,x);
            }
            else add(cur->left,x);
        }
        else if (cur->val < x){
            if (cur->right == NULL){
                cur->right = add(cur->right,x);
            }
            else add(cur->right,x);
        }
        return cur;
    }


    void print(node * cur){
        if (cur != NULL){
            print(cur->left);
            cout << cur->val << " ";
            print(cur->right);
        }
    }

};

void sum_level(int level, vector<int> &v, node * cur){
    if (cur == NULL){
        return;
    }    
    v[level] += cur->val;
    sum_level(level+1,v,cur->left);
    sum_level(level+1,v,cur->right);
}

int main (){
    bst * tree = new bst();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        tree->add(x);
    }
    
    int level = tree->getHeight(tree->getRoot());
    vector <int> v(level);

    cout << endl;

    sum_level(0,v,tree->getRoot());

    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++){

        cout << v[i] << " ";
    }
    return 0;
}