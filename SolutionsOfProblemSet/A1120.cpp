#include <iostream>
#include <set>
using namespace std;
set<int> ans;
int main() {
    int N, temp;
    string num;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num;
        temp = 0;
        for (int i = 0; i < num.length(); i++) {
            temp += num[i]-'0';
        }
        ans.insert(temp);
    }
    cout << ans.size() << endl;
    set<int> :: iterator it;
    it = ans.begin();
    while (it != ans.end()) {
        cout << *it;
        it++;
        if (it != ans.end()) {
            cout << " ";
        }
    }
    return 0;
}