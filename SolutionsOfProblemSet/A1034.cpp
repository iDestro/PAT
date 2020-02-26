/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-29 09:22:27
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-29 11:15:30
 */

#include <iostream>
#include <map>
#include <vector>
#define maxn 2000
using namespace std;

int numMember = 0, G[maxn][maxn] = {0}, gangs = 0, weight[maxn] = {0};
int N, K;
map<string, int> stringToInt;
map<int, string> intToString;
map<string, int> res;
bool vis[maxn] = {false};


int change(string s) {
    if (stringToInt.find(s) != stringToInt.end()) {
        return stringToInt[s];
    } else {
        stringToInt[s] = numMember;
        intToString[numMember] = s;
        return numMember++;
    }
}

void DFS(int u, int &head, int &nums, int &totW) {
    vis[u] = true;
    if (weight[u] > weight[head]) {
        head = u;
    }
    nums++;
    for (int i = 0; i < numMember; i++) {
        if (G[u][i] > 0) {
            totW += G[u][i];
            G[u][i] = G[i][u] = 0;
            if (!vis[i]) {
                DFS(i, head, nums, totW);
            }
        }
    }
}

void DFSTravel() {
    for (int i = 0; i < numMember; i++) {
        if (!vis[i]) {
            int head = i, nums = 0, totW = 0;
            DFS(i, head, nums, totW);
            if (nums > 2 && totW > K) {
                gangs++;
                res[intToString[head]] = nums;
            }
        }
    }
}
int main() {
    cin >> N >> K;
    string u, v;
    int tempW;
    for (int i = 0; i < N; i++) {
        cin >> u >> v >> tempW;
        int uid = change(u);
        int vid = change(v);
        G[uid][vid] += tempW;
        G[vid][uid] += tempW;
        weight[uid] += tempW;
        weight[vid] += tempW;
    }
    DFSTravel();
    cout << gangs << endl;
    map<string, int> :: iterator iter;
    iter = res.begin();
    while (iter != res.end()) {
        cout << iter -> first << " " << iter -> second << endl;
        iter++;
    }
}