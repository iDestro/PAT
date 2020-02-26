#include <iostream>
using namespace std;
int F(int N) {
    if (N == 0 || N == 1) {
        return 1;
    } else {
        return F(N-1) + F(N-2);
    }
}
int main() {
    int N;
    cin >> N;
    cout << F(N) << endl;
}