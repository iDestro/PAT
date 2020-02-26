#include <iostream>
#include <vector>
#include <unordered_map>
#define INF 1000000000
#define maxn 26*26*26+10
using namespace std;


typedef struct node{
    int v, w;
    node(int _v, int _w):v(_v), w(_w) {}
}Node;

vector<Node> G[maxn];
unordered_map<int, string> mp;
int dis[maxn], happiness[maxn], nums[maxn];
bool vis[maxn];

vector<int> pre[maxn];
vector<int> path, tempPath;

int N, K, Sid, Did, tot_hp = 0;
string S;


int getID(string s) {
    int res = 0;
    for (int i =0 ; i < s.length(); i++) {
        res = res*26 + s[i] - 'A';
    }
    return res;
}


void Dijkstra(int s) {
    fill(vis, vis+maxn, false);
    fill(dis, dis+maxn, INF);
    dis[s] = 0;
    nums[s] = 1;
    for (int i = 0; i < maxn; i++) {
        int u = -1, min = INF;
        for (int j = 0; j < maxn; j++) {
            if (!vis[j] && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = true;
        for (int j = 0; j < G[u].size(); j++) {
            int v = G[u][j].v;
            if (!vis[v]) {
                if (dis[u] + G[u][j].w < dis[v]) {
                    dis[v] = dis[u] + G[u][j].w;
                    pre[v].clear();
                    pre[v].push_back(u);
                    nums[v] = nums[u];
                } else if (dis[u] + G[u][j].w == dis[v]) {
                    pre[v].push_back(u);
                    nums[v] += nums[u];
                }
            }
        }
    }
}
int optValue = -1;
void DFS(int u) {
    if (u == Sid) {
        tempPath.push_back(u);
        int value = 0;
        for (int i = tempPath.size() - 1; i >= 0; i--) {
            int id = tempPath[i];
            value += happiness[id];
        }
        if (value > optValue) {
            optValue = value;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(u);
    for (int i = 0; i < pre[u].size(); i++) {
        DFS(pre[u][i]);
    }
    tempPath.pop_back();
}

int main() {
    cin >> N >> K >> S;
    Sid =  getID(S);
    mp[Sid] = S;
    Did = getID("ROM");
    mp[Did] = "ROM";
    fill(happiness, happiness+maxn, 0);
    fill(nums, nums+maxn, 0);
    for (int i = 0; i < N-1; i++) {
        int hp;
        string city;
        cin >> city >> hp;
        int id = getID(city);
        mp[id] = city;
        happiness[id] = hp;
    }

    for (int i = 0; i < K; i++) {
        string u, v;
        int w, uid, vid;
        cin >> u >> v >> w;
        uid = getID(u);
        vid = getID(v);
        G[uid].push_back(Node(vid, w));
        G[vid].push_back(Node(uid, w));
    }
    Dijkstra(Sid);
    DFS(Did);
    cout << nums[Did] << " " << dis[Did] << " " << optValue << " " << optValue/(path.size()-1) << endl;
    for (int i = path.size()-1; i >= 0; i--) {
        cout << mp[path[i]];
        if (i != 0) {
            cout << "->";
        }
    }
    return 0;
}