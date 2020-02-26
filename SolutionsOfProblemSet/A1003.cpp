/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-31 19:42:31
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-31 20:56:42
 */

#include <iostream>
#define INF 100000000
#define maxn 505
#include <algorithm>
using namespace std;

int rescueTeams[maxn], hands[maxn], nums[maxn];



int G[maxn][maxn], dis[maxn];
bool vis[maxn] = {false};
int N, M, S, E;


int Dijsktra(int s) {
    fill(dis, dis+N, INF);
    fill(hands, hands+N, 0);
    fill(nums, nums+N, 0);
    nums[s] = 1;
    hands[s] = rescueTeams[s];
    dis[s] = 0;
    for (int i = 0; i < N; i++) {
        int u = -1, min = INF;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && dis[j] < min) {
                u = j;
                min = dis[j];
            }
        }
        if (u == -1) {
            return -1;
        }
        vis[u] = true;
        for (int v = 0; v < N; v++) {
            if (!vis[v] && G[u][v] != INF) {
                if (G[u][v] + dis[u] < dis[v]) {
                    dis[v] = G[u][v] + dis[u];
                    hands[v] = rescueTeams[v] + hands[u];
                    nums[v] = nums[u];
                } else if (G[u][v] + dis[u] == dis[v]) {
                    if (hands[u] + rescueTeams[v] > hands[v]) {
                        hands[v] = hands[u] + rescueTeams[v];
                    } 
                    nums[v] += nums[u];
                }
            }
        }
    }
    return 1;
}


int main() {
    cin >> N >> M >> S >> E;
    for (int i = 0; i < N; i++) {
        cin >> rescueTeams[i];
    }
    fill(G[0], G[0]+maxn*maxn, INF);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        cin >> G[u][v];
        G[v][u] = G[u][v];
    }
    Dijsktra(S);
    cout << nums[E] << " " << hands[E];
    return 0;
}