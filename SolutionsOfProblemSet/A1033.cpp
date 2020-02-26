#include <iostream>
#include <algorithm>
#define INF 1000000000;
using namespace std;

typedef struct {
    double price;
    double dis;
}GS;

bool Cmp(GS A, GS B) {
    return A.dis < B.dis;
}

int main() {
    int Cmax, D, Davg, N;
    double sum = 0;
    cin >> Cmax >> D >> Davg >> N;
    GS gs[N+1];
    for (int i = 0; i < N; i++) {
        cin >> gs[i].price >> gs[i].dis;
    }
    gs[N].dis = D;
    gs[N].price = 0;
    double tank = 0;
    sort(gs, gs+N, Cmp);
    if (gs[0].dis != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    double fee = 0;
    int now = 0;
    int k;
    double max_dis = Cmax*Davg;
    while (now < N) {
        double minfee = INF;
        int idx = -1;
        for (k = now+1; k <= N && gs[k].dis-gs[now].dis <= max_dis; k++) {
            if (gs[k].price < minfee) {
                minfee = gs[k].price;
                idx = k;
                if (minfee < gs[now].price) {
                    break;
                }
            }
        }
        if (idx == -1) {
            break;
        }
        double need = (gs[idx].dis-gs[now].dis) / Davg;
        if (minfee < gs[now].price) {
            if (tank >= need) {
                tank -= need;
            } else {
                fee += (need-tank) * gs[now].price;
                tank = 0;
            }
        } else {
            fee += (Cmax-tank)*gs[now].price;
            tank = Cmax - (gs[idx].dis-gs[now].dis) / Davg;
        }
        now = idx;
    }
    if (now == N) {
        printf("%.2f", fee);
    } else {
        printf("The maximum travel distance = %.2f", gs[now].dis+max_dis);
    }
    return 0;
}