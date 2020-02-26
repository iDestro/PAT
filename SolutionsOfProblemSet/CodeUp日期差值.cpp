#include <iostream>
using namespace std;

int month[13][2] = {
    {0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, 
    {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}
};
int is_leap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

void swap(int &A, int &B) {
    int t = A;
    A = B;
    B = t;
}

int main() {
    int time1, y1, m1, d1,
        time2, y2, m2, d2;
    cin >> time1 >> time2;
    if (time1 > time2) {
        swap(time1, time2);
    }
    // 20191201
    y1 = time1 / 10000;
    m1 = time1 % 10000 / 100;
    d1 = time1 % 100;

    y2 = time2 / 10000;
    m2 = time2 % 10000 / 100;
    d2 = time2 % 100;
    int ans = 1;
    while (y1 < y2 || m1 < m2 || d1 < d2) {
        d1++;
        if (d1 == month[m1][is_leap(y1)]) {
            d1 = 1;
            m1++;
        }
        if (m1 == 13) {
            m1 = 1;
            y1++;
        }
        ans++;
    }
    cout << ans <<endl;
    return 0;
}