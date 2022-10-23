#include <bits/stdc++.h>
using namespace std;

int sum = 0;

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

    Node *insert(Node *current, int x){
        if (current == NULL){
            current = new Node(x);
            return current;
        }
        if (x > current->data) current->right = insert(current->right, x);
        else if (x < current->data) current->left = insert(current->left, x);
        return current;
    }

    void *print(Node * current){
        if (current != NULL){
            print(current->right);
            cout << current->data << " ";
            print(current->left);
        }
    }

    void *summm(Node * current){
        if (current != NULL){
            summm(current->right);
            // sum += current->data;
            cout <<  sum + current->data << " ";
            sum += current->data;
            summm(current->left);
        }
    }

    int height(Node *node){
        if (!node)
            return 0;
    
        int h_l = height(node->left);
        int h_r = height(node->right);
    
        return max(h_l, h_r) + 1;
    }

    void calculateSum(Node* node, int level, int sum[]){
        if (node == NULL)
            return;

        sum[level] += node->data;
    
        calculateSum(node->left, level + 1, sum);
        calculateSum(node->right, level + 1, sum);
    }

};

int main(){
    bct bctt;
    int n; cin >> n;
    int num;
    int cnt = 0;

    for (int i = 0; i < n; i++){
        cin >> num;
        bctt.root = bctt.insert(bctt.root, num);
    }

    int sum[n] = { 0 };

    bctt.summm(bctt.root);

    // bctt.print(bctt.root);

    // for (int i = 0; i < n; i++){
    //     cout << sum[i] << " ";
    // }
}