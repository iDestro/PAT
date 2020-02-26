#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct {
    string n;
    int h;
}P;
bool cmp(P a, P b) {
    if (a.h != b.h) {
        return a.h > b.h;
    } else {
        return a.n < b.n;
    }
}

int main() {
    int N, K, M;
    cin >> N >> K;
    P p[N];
    for (int i = 0; i < N; i++) {
        cin >> p[i].n >> p[i].h;
    }
    sort(p, p+N, cmp);
    int row = K, j, t = 0;
    while (row) {
        if (row == K) {
            M = N - N/K*(K-1);
        } else {
            M = N/K;
        }
        vector<string> ans(M);
        ans[M/2] = p[t].n;

        j = M/2-1;
        // 左边
        for (int i = t+1; i < t+M; i+=2) {
            ans[j--] = p[i].n;
        }
        j = M/2+1;
        for (int i = t+2; i < t+M; i+=2) {
            ans[j++] = p[i].n;
        }
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
            if (i != ans.size()-1) {
                cout << " ";
            }
        }
        cout << endl;
        row--;
        t += M;
    }
    return 0;
}