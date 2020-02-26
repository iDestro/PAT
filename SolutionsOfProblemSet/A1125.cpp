#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> rope(N);
    stack<int> temp;
    for (int i = 0; i < N; i++) {
        cin >> rope[i];
    }
    sort(rope.begin(), rope.end());
    for (int i = rope.size()-1; i >= 0; i--) {
        temp.push(rope[i]);
    }
    while (temp.size() > 1) {
        int a = temp.top();
        temp.pop();
        int b = temp.top();
        temp.pop();
        temp.push((a+b)/2);
    }
    cout << temp.top();
    return 0;
}