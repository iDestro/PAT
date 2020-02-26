#include <iostream>
#include <vector>
using namespace std;
vector<int> pre, post, in;
bool uni = true;

void getIn(int preLeft, int preRight, int postLeft, int postRight) {
    if (preLeft == preRight) {
        in.push_back(pre[preLeft]);
        return;
    }
    if (pre[preLeft] == post[postRight]) {
        int i = preLeft + 1;
        while (i <= preRight && pre[i] != post[postRight-1]) i++;
        if (i - preLeft > 1) {
            getIn(preLeft+1, i-1, postLeft, postLeft+(i-preLeft-1)-1);
        } else {
            uni = false;
        }
        in.push_back(post[postRight]);
        getIn(i, preRight, postLeft+(i-preLeft-1), postRight-1);

    }
}
int main() {
    int N;
    cin >> N;
    pre.resize(N);
    post.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> pre[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> post[i];
    }
    getIn(0, N-1, 0, N-1);
    if (uni) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    for (int i = 0; i < N; i++) {
        cout << in[i];
        if (i != N-1) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}