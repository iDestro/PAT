#include <iostream>
using namespace std;
int main() {
    int p[3], a[3], c[3], carry;
    scanf("%d.%d.%d", &p[0], &p[1], &p[2]);
    scanf("%d.%d.%d", &a[0], &a[1], &a[2]);
    c[2] = (p[2]+a[2]) % 29;
    carry = (p[2]+a[2]) / 29;
    c[1] = (p[1]+a[1]+carry) % 17;
    carry = (p[1]+a[1]+carry) / 17;
    c[0] = p[0] + a[0] + carry;
    printf("%d.%d.%d", c[0], c[1], c[2]);
    return 0;
}