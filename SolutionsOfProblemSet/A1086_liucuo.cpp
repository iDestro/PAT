/* @Descripttion: 1086 Tree Traversals Again (25 分) 
 * 输入方式有错误,以下是正确的输入方式，但我不知道我的哪里有BUG @.@!
 * for (int i = 0; i < 2*N; i++) {
        if (strlen(str) == 4) {
            int num;
            scanf("%d", &num);
            value.push_back(num);
            pre.push_back(key);
            s.push(key++);
        } else {
            in.push_back(S.top());
            s.pop();
        } 
    }
 * 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-26 09:51:08
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-26 10:21:01
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int N;
vector<int> pre, in, ans, value;

void postOrder(int root, int start, int end) {
    if (start > end) {
        return;
    }
    int k;
    for (k = start; in[k] != pre[root]; k++);
    int leftNum = k - start;
    postOrder(root+1, start, start+leftNum-1);
    postOrder(root+leftNum+1, start+leftNum+1, end);
    ans.push_back(pre[root]);
}

int main() {
    stack<int> S;
    cin >> N;
    getchar();
    string temp;

    // 输入过程
    int key = 0;
    for (int i = 0; i < 2*N; i++) {
        getline(cin, temp);
        if (temp[1] == 'u') {
            value.push_back(temp[5]-'0');
            pre.push_back(key);
            S.push(key++);
        } else {
            in.push_back(S.top());
            S.pop();
        }
    }
    
    postOrder(0, 0, N-1);
    cout << value[ans[0]];
    for (int i = 1; i < ans.size(); i++) {
        cout << " " << value[ans[i]];
    }
    return 0;
}
