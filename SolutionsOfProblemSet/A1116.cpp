#include <iostream>
#include <map>
#include <cstdio>
#include <cmath>
using namespace std;
map<int, string> m;
map<int, bool> vis;

bool isprime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int N, K;
int main() {
    cin >> N;
    int cnt = 1;
    bool flag = true;
    for (int i = 0; i < N; i++) {
        int id;
        cin >> id;
        if (cnt == 1) {
            m[id] = "Mystery Award";
        } else if (isprime(cnt)) {
            m[id] = "Minion";
            flag = false;
        } else {
            m[id] = "Chocolate";
        }
        vis[id] = false;
        cnt++;
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        int id;
        cin >> id;
        if (m.find(id) == m.end()) {
            printf("%04d: Are you kidding?\n", id);
        } else {
            if (!vis[id]) {
                vis[id] = true;
                printf("%04d: %s\n", id,  m[id].c_str());
            } else {
                printf("%04d: Checked\n", id);
            }
        }
    }
    return 0;
}


