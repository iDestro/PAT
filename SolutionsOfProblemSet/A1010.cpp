#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<char, int> mp;

void init() {
    for (char c = '0'; c <= '9'; c++) {
        mp[c] = c-'0';
    }
    for (char c = 'a'; c <= 'z'; c++) {
        mp[c] = c-'a'+10;
    }
}

long long convert(string know, long long radix) {
    long long num = 0;
    for (int i = 0; i < know.length(); i++) {
        num = num*radix + mp[know[i]];
    }
    return num;
}

long long find_radix(string unknow, long long num) {
    char min_ch = *max_element(unknow.begin(), unknow.end());
    long long l = mp[min_ch] + 1;
    long long r = max(num, l);

    while (l <= r) {
        long long mid = (l+r)/2;
        long long unknow_val = convert(unknow, mid);
        if (unknow_val == num) {
            return mid;
        } else if (unknow_val < 0 || unknow_val > num) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int main() {
    init();
    string A, B;
    long long tag, radix, result;
    cin >> A >> B >> tag >> radix;
    if (tag == 1) {
        result = find_radix(B, convert(A, radix));
    } else {
        result = find_radix(A, convert(B, radix));
    }
    if (result == -1) {
        cout << "Impossible";
    } else {
        cout << result;
    }
    return 0;
}