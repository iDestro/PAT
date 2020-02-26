#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return !b ? a : gcd(b, a%b);
}
int lcm(int a, int b) {
    int d = gcd(a, b);
    return a/d*b;
}
int main() {
    printf("%d", gcd(100000, 4));
    return 0;
}