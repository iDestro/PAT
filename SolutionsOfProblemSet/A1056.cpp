/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-21 09:43:06
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-21 12:12:11
 */
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef struct {
    int w, o, l, i;
}P;

bool cmp0(P a, P b) {
    return a.o < b.o;
}

bool cmp1(P a, P b) {
    return a.w < b.w;
}

int main() {
    int Np, Ng;
    queue<P> Q;
    cin >> Np >> Ng;
    int rank[Np], index[Np];
    P p[Np];
    for (int i = 0; i < Np; i++) {
        cin >> p[i].w;
    }for (int i = 0; i < Np; i++) {
        cin >> p[i].o;
        index[i] = p[i].o;
    }
    sort(p, p+Np, cmp0);
    for (int i = 0; i< Np; i++) {
        Q.push(p[i]);
    }
    int s = Np, cnt = 0, newNp = 0, cntG = 1;
    while (!Q.empty()) {
        vector<P> v;
        int nums = Ng + (Np-cntG*Ng < Ng ? Np-cntG*Ng : 0);
        for (int i = 0; !Q.empty() && i < nums && cnt < s; i++, cnt++) {
            v.push_back(Q.front());
            Q.pop();
        }
        cntG++;
        if (cnt == s) {
            cntG = 1;
            s = newNp;
            newNp = 0;
            cnt = 0;
        } else {
            newNp++;
        }
        P max = *max_element(v.begin(), v.end(), cmp1);
        for (int i = 0; i < v.size(); i++) {
            if (v[i].w < max.w) {
                int r = s / Ng + (s % Ng == 0 ? 0 : 1) + 1;
                rank[v[i].o] = r;
            }
        }
        if (!Q.empty()) {
            Q.push(max);
        } else {
            rank[max.o] = 1;
            break;
        }
    }
    for (int i = 0; i < Np; i++) {
        cout << rank[index[i]] << " ";
    }
    return 0;
}