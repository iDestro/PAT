#include <cstdio>
#include <string>
#include <iostream>
#include <cctype>
using namespace std;

int trans(char ch) {
    if (isdigit(ch)) {
        return ch - '0';
    } else if (islower(ch)) {
        return ch - 'a' + 10;
    } else {
        return ch - 'A' + 36;
    }
}

int main() {
    string beads_sell, beads_want;
    cin >> beads_sell >> beads_want;
    bool flag = true;
    int extra[10+26+26] = {0};
    int miss[10+26+26] = {0};
    int sum = 0;
    for (int i = 0; i < beads_sell.length(); i++) {
        extra[trans(beads_sell[i])]++;
    }
    for (int i = 0; i < beads_want.length(); i++) {
        int index = trans(beads_want[i]);
        if (extra[index] == 0) {
            flag = false;
            miss[index]++;
        } else {
            extra[index]--;
        }
    }
    if (flag) {
        for (int i = 0; i < 10 + 26 + 26; i++) {
            sum += extra[i];
        }
        printf("Yes %d", sum);
    } else {
        for (int i = 0; i < 10 + 26 + 26; i++) {
            sum += miss[i];
        }
        printf("No %d", sum);
    }
}