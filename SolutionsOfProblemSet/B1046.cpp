#include <iostream>
using namespace std;

int main() {
    int T, a, b, c, d, e = 0, f = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> a >> b >> c >> d;
        if (b == a + c && d != a + c) {
            e++;
        } else if (d == a + c && b != a + c) {
            f++;
        }
    }
    cout << f << " " << e;
    return 0;
}