#include<iostream>
#include<map>
#include<vector>
using namespace std;

map<int, vector<int> > mp;

int main() {
    for (int i = 0; i < 3; i++) {
        mp[i].push_back(i);
    }
    for (int i = 0; i < 3; i++) {
        cout << mp[i][0] << endl;
    }
    return 0;
}