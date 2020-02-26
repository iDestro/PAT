#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<string> ans, temp;
map<string, bool> m;
int M, N, S;
int main() {
    cin >> M >> N >> S;
    string name;
    for (int i = 1; i <= M; i++) {
        cin >> name;
        temp.push_back(name);
    }
    if (S > M) {
        cout << "Keep going...";
        return 0;
    }
    int cnt = 1;
    for (int i = 1; i <= M; i++) {
        name = temp[i-1];
        bool flag = m[name];
        if (cnt-S >= 0 && (cnt-S)%N == 0 && !m[name]) {
            ans.push_back(name);
            m[name] = true;
        }
        if (!flag) {
            cnt++;
        }
    }
    for (int i = 0; i < ans.size(); i++) {  
        cout << ans[i] << endl;
    }
    return 0;
}