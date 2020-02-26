#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> nums;
    int N, b;
    cin >> N >> b;
    while (N!=0) {
        nums.push_back(N%b);
        N /= b;
    }
    int size = nums.size();
    bool flag = true;
    for (int i = 0 ; i < size / 2; i++) {
        if (nums[i] != nums[size-i-1]) {
            flag = false;
            break;
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
    for (int i = size-1; i > 0; i--) {
        cout << nums[i] << " ";
    }
    cout << nums[0];
    return 0;
}