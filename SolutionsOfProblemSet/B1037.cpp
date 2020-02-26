#include <cstdio>
using namespace std;
int main() {
    int P[3], A[3];
    scanf("%d.%d.%d", &P[0], &P[1], &P[2]);
    scanf("%d.%d.%d", &A[0], &A[1], &A[2]);
    int P_Knut = P[2] + P[1]*29 + P[0]*17*29;
    int A_Knut = A[2] + A[1]*29 + A[0]*17*29;
    int exchange = A_Knut - P_Knut;
    if (exchange < 0) {
        exchange = -exchange;
        printf("-");
    }
    printf("%d.%d.%d", exchange/29/17, exchange/29%17, exchange%29);
    return 0;
}