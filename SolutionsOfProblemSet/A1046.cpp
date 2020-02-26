#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N, M, L, R;
    vector<int> res;
    scanf("%d", &N);
    int A[N+1], total_dis = 0, dis[N+1];
    dis[0] = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        total_dis += A[i];
        dis[i] = total_dis;
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &L, &R);
        if (L > R) {
            swap(L, R);
        }
        res.push_back(min(dis[R-1]-dis[L-1], total_dis-dis[R-1]+dis[L-1]));
    }
    for (int i = 0; i < M; i++) {
        printf("%d\n", res[i]);
    }
}