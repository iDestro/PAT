#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxInt(vector<int> dis, int N) {
    int cnt = 0;
    for (int i = 0; i < dis.size(); i++) {
        dis[i] -= N;
        if (dis[i] > 0) {
            cnt++;
        }
    }
    return cnt;
}


int main() {
    int N;
    cin >> N;
    vector<int> dis;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        dis.push_back(temp);
    }
    sort(dis.begin(), dis.end(), greater<int>());
    int e = 0;
    while (e < N && dis[e] > e+1) e++;
    cout << e;
    return 0;
}