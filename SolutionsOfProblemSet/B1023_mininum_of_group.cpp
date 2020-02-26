#include <iostream>
using namespace std;
int main() {
    int nums[10];
    for (int i = 0; i < 10; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < 10; i++) {
        if (nums[i] != 0 && i != 0) {
            cout << i;
            nums[i]--;
            break;
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < nums[i]; j++) {
            cout << i;
        }
    }
    return 0;
}