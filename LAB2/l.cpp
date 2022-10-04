# include <iostream>
# include <algorithm>
# include <cassert>

using namespace std;

struct Node {
  int val;
  Node *next;
  Node() {
    val = 0;
    next = NULL;
  }

};

// -1 -1 -1

int findMaxSum(int n, Node *head) {
    int max = -1e9;
    int sum = 0;
    Node * cur = head;
    while (cur)
    {
        sum += cur->val;
        if (sum > max){
            max = sum;
        }
        if (sum < 0){
            sum = 0;
        }
        cur = cur->next;
    }
    return max;
}

int main() {
  int n;
  cin >> n;

  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;
    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }

  cout << findMaxSum(n, head) << "\n";
  return 0;
}
