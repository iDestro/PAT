#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> in, post, ans, temp;
int N;

struct Node {
    int data;
    Node *left, *right;
};

Node *newNode(int x) {
    Node *node = new Node;
    node -> data = x;
    node -> left = node -> right = NULL;
    return node;
}

Node *create(int postL, int postH, int inL, int inH) {
    if (postL > postH) {
        return NULL;
    }
    Node *node = newNode(post[postH]);
    int k;
    for (k = inL; in[k] != post[postH]; k++);
    int leftNum = k-inL;
    node -> left = create(postL, postL+leftNum-1, inL, inL+leftNum-1);
    node -> right = create(postL+leftNum, postH-1, inL+leftNum+1, inH);
    return node;
}

int cnt = 0;

void bfs(Node *root) {
    queue<Node*> Q;
    Q.push(root);
    Node *lastNode = root;
    while (!Q.empty()) {
        Node *front = Q.front();
        Q.pop();
        temp.push_back(front -> data);
        if (front == lastNode) {
            if (cnt % 2 == 0) {
                reverse(temp.begin(), temp.end());
            }
            for (int i = 0; i < temp.size(); i++) {
                ans.push_back(temp[i]);
            }
            cnt++;
            temp.clear();
        }
        if (front -> left != NULL) {
            Q.push(front -> left);
        }
        if (front -> right != NULL) {
            Q.push(front -> right);
        }
        if (front == lastNode) {
            lastNode = Q.back();
        }
    }
}

int main() {
    cin >> N;
    in.resize(N);
    post.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> in[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> post[i];
    }
    Node *root = create(0, N-1, 0, N-1);
    bfs(root);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size()-1) {
            cout << " ";
        }
    }
    return 0;
}