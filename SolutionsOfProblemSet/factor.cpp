#include <iostream>
using namespace std;
int F(int N) {
    if (N == 0) {
        return 1;
    } else {
        return N*F(N-1);
    }
}
int main() {
    int N;
    cin >> N;
    cout << F(N);
}