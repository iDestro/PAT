#include <iostream>
using namespace std;
int main() {
    int N, nums[3];
    cin >> N;
    nums[0] = N/100;
    nums[1] = N/10%10;
    nums[2] = N%10;
    for (int i = 0; i < nums[0]; i++) {
        cout << "B";
    }
    for (int i = 0; i < nums[1]; i++) {
        cout << "S";
    }
    for (int i = 1; i <= nums[2]; i++) {
        cout << i;
    }
    return 0;
}