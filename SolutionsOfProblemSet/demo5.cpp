#include <iostream>
#define eps 1e-5
using namespace std;
double f(double x) {
    return x*x-2;
}
double calsqrt() {
    double left = 1, right = 2, mid;
    while (right - left > eps) {
        mid = left + (right - left)/2;
        if (f(mid) > 0) right = mid;
        else left = mid;
    }
    return left;
}
int main() {
    cout << calsqrt();
    return 0;
}