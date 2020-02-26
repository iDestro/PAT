#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, K, P, maxFactSum = -1;
vector<int> ans, temp, v;

void init() {
    int temp = 0, index = 1;
    while (temp <= N) {
        v.push_back(temp);
        temp = pow(index,P);
        index++;
    }
}

void dfs(int index, int nowK, int sum, int factSum) {
    if (nowK == K) {
        if (sum == N && factSum > maxFactSum) {
            maxFactSum = factSum;
            ans = temp;
        }
        return;
    }
    while (index >= 1) {
        if (sum + v[index] <= N) {
            temp.push_back(index);
            dfs(index, nowK+1, sum+v[index], factSum+index);
            temp.pop_back();
        }
        index--;
    }
}

int main() {
    cin >> N >> K >> P;
    init();
    dfs(v.size()-1, 0, 0, 0);
    if (maxFactSum != -1) {
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