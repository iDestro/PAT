#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
};

int N;
vector<int> post;
vector<int> in;
vector<int> ans;

node *create(int postl, int posth, int inl, int inh) {
    if (postl > posth) {
        return NULL;
    }
    node *root = new node;
    root -> data = post[posth];
    int i;
    for (i = inl; in[i] != post[posth]; i++);
    int leftNum = i-inl;
    root -> lchild = create(postl, postl+leftNum-1, inl, inl+leftNum-1);
    root -> rchild = create(postl+leftNum, posth-1, inl+leftNum+1, inh);
    return root;
}

void level(node *&root) {
    queue<node*> Q;
    Q.push(root);
    while (!Q.empty()) {
        node *front = Q.front();
        Q.pop();
        ans.push_back(front->data);
        if (front -> lchild != NULL) {
            Q.push(front -> lchild);
        }
        if (front -> rchild != NULL) {
            Q.push(front -> rchild);
        }
    }
}

int main() {
    int temp;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        post.push_back(temp);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        in.push_back(temp);
    }
    node *root = create(0, N-1, 0, N-1);
    level(root);
    if (ans.size() > 0) {
        for (int i = 0; i < ans.size()-1; i++) {
        printf("%d ", ans[i]);
        }
        printf("%d", ans[ans.size()-1]);
    }
    return 0;
}