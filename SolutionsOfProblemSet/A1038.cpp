#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool Cmp(string a, string b) {
    return a+b < b+a;
}
int main() {
    int N;
    cin >> N;
    string s[N];
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }
    sort(s, s+N, Cmp);
    bool flag = false;
    string res = "";
    for (int i = 0; i < N; i++) {
        res += s[i];
    }
    while (res.size() != 0 && res[0] == '0') {
        res.erase(res.begin());
    }
    if (res.size() == 0) cout << 0;
    else cout << res;
    return 0;
}