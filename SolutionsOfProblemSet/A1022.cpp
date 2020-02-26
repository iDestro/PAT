/*
 * @Descripttion: 输出的数字格式不错
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-25 23:41:34
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-26 08:48:35
 */

#include <iostream>
#include <unordered_map>
#include <set>
#include <cstdio>
using namespace std;
unordered_map<string, set<int> > mp[5];

int main() {
    string title, author, keywords, publisher, year;
    int N, K, id;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> id;
        char c = getchar();
        getline(cin, title);
        mp[0][title].insert(id);
        getline(cin, author);
        mp[1][author].insert(id);
        while (cin >> keywords) {
            mp[2][keywords].insert(id);
            c = getchar();
            if (c == '\n') {
                break;
            }
        }
        getline(cin, publisher);
        mp[3][publisher].insert(id);
        getline(cin, year);
        mp[4][year].insert(id);
    }
    cin >> K;
    getchar();
    string temp;
    for (int i = 0; i < K; i++) {
        int index;
        scanf("%d: ", &index);
        getline(cin, temp);
        cout << index << ": " << temp << endl;
        set<int> a = mp[index-1][temp];
        if (a.size() == 0) {
            cout << "Not Found" << endl;
        }
        set<int> :: iterator iter;
        iter = a.begin();
        while (iter != a.end()) {
            printf("%07d\n", *iter);
            iter++;
        }
    }
}