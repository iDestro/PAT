#include <iostream>
#include <cmath>
#define eps 1e-5
using namespace std;
const double PI = acos(-1.0);

double f(double R, double h) {
    double alpha = 2*acos(R-h/R);
    double L = R*sin(alpha/2)*2;
    double S1 = alpha*R*R - L*(R-h)/2;
    double S2 = PI*R*R/2;
    return S1/S2;
}

double solve(double R, double r) {
    int left = 0, right = R, mid;
    while (right - left > eps) {
        mid = left + (right - left)/2;
        if (f(R, mid) > r) right = mid;
        else left = mid;
    }
    return mid;
}

int main() {

    return 0;
}