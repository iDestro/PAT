#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

struct bign {
    char d[1000];
    int len;
    bign() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign change(char str[]) {
    bign a;
    a.len = strlen(str);
    for (int i = 0; i < a.len; i++) {
        a.d[i] = str[a.len - i - 1] - '0';
    }
    return a;
}

int compare(bign a, bign b) {
    if (a.len > b.len) return 1;
    else if (a.len < b.len) return -1;
    else {
        for (int i = 0; i < a.len; i++) {
            if (a.d[i] > b.d[i]) return 1;
            else if (a.d[i] < b.d[i]) return -1;
        }
    }
    return 0;
}

bign add(bign a, bign b) {
    bign c;
    int carry = 0;
    for (int i = 0; i < a.len || i < b.len; i++) {
        int sub_sum = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = sub_sum % 10;
        carry = sub_sum / 10;
    }
    if (carry!=0) {
        c.d[c.len++] = carry;
    }
    return c;
}

bign sub(bign a, bign b) {
    bign c;
    for (int i = 0; i < a.len || i < b.len; i++) {
        if (a.d[i] >= b.d[i]) {
            c.d[c.len++] = a.d[i] - b.d[i];
        } else {
            a.d[i+1]--;
            c.d[c.len++] = a.d[i] + 10 - b.d[i];
        }
    }
    while (c.len-1 >= 1 && c.d[c.len-1] == 0) {
        c.len--;
    }
    return c;
}

bign muti(bign a, int b) {
    bign c;
    int carry = 0;
    for (int i = 0; i < a.len; i++) {
        int temp = a.d[i]*b+carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    while (carry != 0) {
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}

bign div(bign a, bign b, int &r) {
    bign c;
    c.len = a.len;
    for (int i = c.len-1; i >= 0; i--) {
        r = r * 10 + a.d[i];
        if (r < b) {
            c.d[i] = 0;
        } else {
            c.d[i] = r / b;
            r = r % b;
        }
    }
    while (c.len - 1 >= 1 && c.d[c.len-1] == 0) {
        c.len--;
    }
    return c;
}

int main() {
    stack<int> S;
    cout << S.isEmpty();
    return 0;
}