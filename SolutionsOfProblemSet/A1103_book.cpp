#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int N, K, P, ansSum = -1;
vector<int> temp, ans, v;

void init() {
    int temp = 0, index = 1;
    while (temp <= N) {
        v.push_back(temp);
        temp = pow(index, P);
        index++;
    }
}

void dfs(int index, int nowK, int sumQu, int sum) {
    if (nowK == K) {
        if (sumQu == N && sum > ansSum) {
            ansSum = sum;
            ans = temp;
        }
        return;
    }
    if (index >= 1) {
        if (sumQu+v[index] <= N) {
            temp.push_back(index);
            dfs(index, nowK+1, sumQu+v[index], sum+index);
            temp.pop_back();
        }
        dfs(index-1, nowK, sumQu, sum);
    }
}

int main() {
    cin >> N >> K >> P;
    init();
    dfs(v.size()-1, 0, 0, 0);
    if (ansSum != -1) {
        cout << N << " = ";
        for (int i = 0; i < ans.size()-1; i++) {
            cout << ans[i] << "^" << P << " + ";
        }
        cout << ans[ans.size()-1] << "^" << P;
    } else {
        cout << "Impossible";
    }
    return 0;
}