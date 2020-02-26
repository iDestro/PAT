/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-27 12:01:21
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-15 23:19:41
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;


int binary_search(vector<int> arr) {
    int l = 1, r = arr.size()-1, mid;
    while (l < r) {
        mid = l + (r-l)/2;
        if (arr[mid] > mid) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    return l;
}

int main() {
    int n, t;
    cin >> n;
    vector<int> a;
    a.push_back(-1);
    unordered_set<int> set;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t > 0) {
            set.insert(t);
        }
    }
    unordered_set<int> :: iterator it;
    it = set.begin();
    while (it != set.end()) {
        a.push_back(*it);
        it++;
    }
    sort(a.begin()+1, a.end());
    if (a[a.size()-1] == a.size()-1) {
        cout << a.size();
        return 0;
    }
    // for (int i = 1; i < a.size(); i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    cout << binary_search(a);
    return 0;
}