/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-08 22:56:13
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-11 21:30:50
 */
#include <iostream>
#include <set>
int book[50005] = {0};
using namespace std;

struct node {
    int val, cnt;
    node (int _v, int _c):val(_v), cnt(_c) {}
    bool operator < (const node &a) const {
        if (cnt != a.cnt) {
            return cnt > a.cnt;
        } else {
            return val < a.val;
        }
    }
};
int main() {
    int n, k;
    cin >> n >> k;
    set<node> s;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (i != 0) {
            cout << num << ":";
            int tempCnt = 0;
            for (auto it = s.begin(); tempCnt < k && it != s.end(); it++) {
                cout << " " << (*it).val;
                tempCnt++;
            }
            cout << endl;
        }
        auto it = s.find(node(num, book[num]));
        if(it != s.end()) {
            s.erase(it);
        }
        book[num]++;
        s.insert(node(num, book[num]));
        
    }
    return 0;
}