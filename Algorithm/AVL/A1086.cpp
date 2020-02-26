#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Node {
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

int N;
vector<int> pre, in;

Node *create(int preL, int preH, int inL, int inH) {
    if (preL > preH) {
        return NULL;
    }
    Node *root = new Node;
    root -> data = pre[preL];
    int k;
    for (k = inL; in[k] != pre[preL]; k++);
    int leftNum = k-inL;
    root -> lchild = create(preL+1, preL+leftNum, inL, inL+leftNum-1);
    root -> rchild = create(preL+leftNum+1, preH, inL+leftNum+1, inH);
    return root;
}

int cnt = 0;

void postOrder(Node *&root) {
    if (root != NULL) {
        postOrder(root -> lchild);
        postOrder(root -> rchild);
        cnt++;
        cout << root -> data;
        if (cnt < N) {
            cout << " ";
        }
    }
}

int main() {
    stack<int> S;
    cin >> N;
    getchar();
    string temp;
    for (int i = 0; i < 2*N; i++) {
        getline(cin, temp);
        if (temp[1] == 'u') {
            S.push(temp[5]-'0');
            pre.push_back(temp[5]-'0');
        } else {
            in.push_back(S.top());
            S.pop();
        }
    }
    Node *root = create(0, N-1, 0, N-1);
    postOrder(root);

    return 0;
}
