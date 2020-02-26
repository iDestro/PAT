#include <iostream>
using namespace std;
int main() {
    int C;
    char ch;
    cin >> C >> ch;
    int R = (C*0.5-C/2)*10 >= 5 ? C/2+1 : C/2;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << ((i == 0 || i == R-1 || j == 0 || j == C-1) ? ch : ' ');
        }
        cout << endl;
    }
}