#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int num, N;
    scanf("%d", &N);
    int mp[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        mp[num] = i;
    }
    int cnt = 0;
    int is_ok = 0;
    for (int i = 1; i < N; i++) {
        if (mp[i] == i) {
            is_ok++;
        }
    }
    int k = 1;
    while (is_ok < N-1) {
        if (mp[0] == 0) {
            while (k < N) {
                if (mp[k] != k) {
                    swap(mp[k], mp[0]);
                    cnt++;
                    break;
                }
                k++;
            }
        }
        while (mp[0] != 0) {
            swap(mp[0], mp[mp[0]]);
            is_ok++;
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}