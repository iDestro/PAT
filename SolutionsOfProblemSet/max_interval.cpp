#include <iostream>
#include <algorithm>
using namespace std;

typedef struct  It{
    int x, y;
}Interval;

bool Cmp(Interval A, Interval B) {
    if (A.x != B.x) {
        return A.x > B.x;
    } else {
        return A.y < B.y;
    }
}

int main() {
    int N, count = 1; 
    cin >> N;
    Interval intervals[N];
    for (int i = 0; i < N; i++) {
        cin >> intervals[i].x >> intervals[i].y;
    }
    sort(intervals, intervals+N, Cmp);
    int pre_x = intervals[0].x;
    for (int i = 1; i < N; i++) {
        if (intervals[i].y <= pre_x) {
            count++;
            pre_x = intervals[i].x;
        }
    }
    cout << count;
    return 0;
}