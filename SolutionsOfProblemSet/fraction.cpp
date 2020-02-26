#include <iostream>
using namespace std;
struct Fraction {
    int up, down;
};

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

Fraction reduction(Fraction result) {
    if (result.down < 0) {
        result.up *= -1;
        result.down *= -1;
    }
    if (result.up == 0) {
        result.down = 1;
    } else {
        int d = gcd(result.up, result.down);
        result.up /= d;
        result.down /= d;
    }
    return result;
}

Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down + f2.up*f1.down;
    result.down = f1.down*f2.down;
    return reduction(result);
}

Fraction minu(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down - f2.up*f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction muti(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f1.down*f2.down;
    return reduction(result);
}

Fraction divde(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;
    return reduction(result);
}

void show_fraction(Fraction f) {
    if (f.up == 0) {
        cout << 0;
    } else if (f.down == 1) {
        cout << f.up;
    } else {
        cout << f.up << "/" << f.down;
    }
}

int main() {

}