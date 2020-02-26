#include <iostream>
#include <string>
#include <stack>
using namespace std;
string idx[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int main() {
    int sum = 0, k = 0, nums[10];
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        sum += s[i]-'0';
    }
    while (sum != 0) {
        nums[k++] = sum % 10;
        sum /= 10;
    }
    for (int i = k-1; i>= 0; i--) {
        cout << idx[nums[i]];
        if (i != 0) {
            cout << " ";
        }
    }
    return 0;
}