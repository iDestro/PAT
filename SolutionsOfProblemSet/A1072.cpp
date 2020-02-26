/*
 * @Descripttion: 1072 Gas Station (30 分)
 * 输入坐标坑了好久
 * @version: 
 * @Author: iDestro
 * @Date: 2019-08-02 10:40:31
 * @LastEditors: iDestro
 * @LastEditTime: 2019-08-02 21:46:59
 */


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cctype>
#define maxn 1025
#define INF 1000000000
using namespace std;
int N, M, K, Ds, G[maxn][maxn], dis[maxn];
bool vis[maxn];


void Dijkstra(int s) {
    fill(dis, dis+maxn, INF);
    fill(vis, vis+maxn, false);
    dis[s] = 0;
    for (int i = 1; i <= N+M; i++) {
        int u = -1, min = INF;
        for (int j = 1; j <= M+N; j++) {
            if (!vis[j] && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = true;
        for (int v = 1; v <= M+N; v++) {
            if (!vis[v] && G[u][v] != INF && dis[u] + G[u][v] < dis[v]) {
                dis[v] = dis[u] + G[u][v];
            }
        }
    }
}

int getID(string str) {
    int i = 0, len = str.length(), ID = 0;
    while (i < len) {
        if (str[i] != 'G') {
            ID = ID*10 + str[i] - '0';
        }
        i++;
    }
    if (str[0] == 'G') return N+ID;
    else return ID;
}

int main() {
    cin >> N >> M >> K >> Ds;
    fill(G[0], G[0]+maxn*maxn, INF);
    for (int i = 0; i < K; i++) {
        string c1, c2;
        int u, v, w;
        cin >> c1 >> c2 >> w;
        u = getID(c1);
        v = getID(c2);
        G[v][u] = G[u][v] = w;
    }

    double ansDis = -1;
    double ansAvg = INF;
    int p = -1;
    for (int i = N+1; i <= M+N; i++) {
        double avgDis = 0, minDis = INF;
        Dijkstra(i);
        for (int j = 1; j <= N; j++) {
            if (dis[j] > Ds) {
                minDis = -1;
                break;
            }
            if (dis[j] < minDis) {
                minDis = dis[j];
            }
            avgDis += 1.0*dis[j]/N;
        }
        if (minDis == -1) {
            continue;
        }
        if (minDis > ansDis) {
            p = i;
            ansAvg = avgDis;
            ansDis = minDis;
        } else if (minDis == ansDis && avgDis < ansAvg) {
            p = i;
            ansAvg = avgDis;
        }
    }
    if (p == -1) {
        cout << "No Solution";
        return 0;
    }
    cout << "G" << p-N << endl;
    printf("%.1f %.1f", ansDis, ansAvg);
    return 0;
}