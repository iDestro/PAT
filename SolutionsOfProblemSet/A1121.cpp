#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<string, bool> mark;
map<string, string> cp;
vector<string> ans, query;
int main() {   
    int N, M;
    string id1, id2;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> id1 >> id2;
        mark[id1] = true;
        mark[id2] = true;
        cp[id1] = id2;
        cp[id2] = id1;
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> id1;
        mark[id1] = false;
        query.push_back(id1);
    }
    for (int i = 0; i < query.size(); i++) {
        string id = query[i];
        if (cp.find(id) == cp.end()) {
            ans.push_back(id);
        } else {
            if (mark[cp[id]] == true) {
                ans.push_back(id);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size()-1) {
            cout << " ";
        }
    }
    return 0;
}