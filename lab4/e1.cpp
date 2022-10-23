#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

struct bct {
    Node* root;

    bct(){
        root = NULL;
    }

    Node *find(Node *current, int x){
        if (current != NULL){
            if (x == current->data) return current;

            find(current->right, x);
            find(current->left, x);
        }
    }

    Node *insert(Node *current, int x, int y, int z){
        if (current == NULL){
            current = new Node(y);
            return current;
        }
        if (z == 0 && current->data == x) current->left = insert(current->left, x, y, z);
        else if (z == 1 && current->data == x) current->right = insert(current->right, x, y, z);
        insert(current->left, x, y, z);
        insert(current->right, x, y, z);
        return current;
    }

    void *print(Node * current){
        if (current != NULL){
            cout << current->data << " ";
            print(current->left);
            print(current->right);
        }
    }

    void *printt(Node * current, int level, int sum[]){
        int cnt = 0;
        // if (current == NULL) return 0;
        if (current != NULL){
            if (current->left != NULL) sum[level] += 1;
            if (current->right != NULL) sum[level] += 1;
            printt(current->left, level + 1, sum);
            printt(current->right, level + 1, sum);
        }
    }

    int height(Node *node){
        if (!node)
            return 0;
    
        int h_l = height(node->left);
        int h_r = height(node->right);
    
        return max(h_l, h_r) + 1;
    }
};


int main(){
    bct bctt;
    int n; cin >> n;
    int x, y, z;

    bctt.root = bctt.insert(bctt.root, 0, 1, 0);

    string str;

    for (int i = 0; i < n-1; i++){
        cin >> x >> y >> z;
        str += z-'0';
        bctt.root = bctt.insert(bctt.root, x, y, z);
    }

    string t = str;
    reverse(str.begin(), str.end());
    if (t == str){
        cout << 1;
        return 0;
    }

    // bctt.print(bctt.root);

    int height = bctt.height(bctt.root);
    int sum[height] = { 0 };

    bctt.printt(bctt.root, 0, sum); 

    // bctt.calculateSum(bctt.root, 0, sum);

    // for (int i = 0; i < height; i++){
        // cout << sum[i] << " ";
    // }

    std::cout << *std::max_element(sum, sum+height);

    // cout << bctt.getMaxWidth(bctt.root);
}